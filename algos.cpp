// ============================================================================
// algos.cpp
// ~~~~~~~~~~~~~~~~
// Saksham Arora
// ============================================================================

#include <stdexcept> // to throw exceptions if you need to
#include <iostream>
#include <fstream>   // to open & read from input file
#include <cstdlib>   // for atoi() if you want to use it
#include <istream>
#include <sstream>
#include <set>       // for sba algorithm
#include <vector>    // for vba algorithm
#include <algorithm> // for vba algorithm

#include "Lexer.h"
#include "algos.h"
using namespace std; // BAD PRACTICE

ifstream ifs;
istringstream is;

int vba(string filename){
    
    string line;
    ifs.open(filename.c_str());
    vector<pair<int, int> > myvector;
    while (getline(ifs, line)) {
        
        if (line.at(0) == '#') {
            continue;
        }else{
            istringstream is(line);
            int a, b;
            is >> a >> b;
            if (a > b) {
                pair <int,int> pair3 = make_pair(a, b);
                myvector.push_back(pair3);
            } else {
                pair <int,int> pair4 = make_pair(b,a);
                myvector.push_back(pair4);
                
            }
        }
    }
				sort(myvector.begin(), myvector.end());
				vector<pair<int, int> >::iterator i = myvector.begin();
    while (i != myvector.end()) {
        vector<pair<int, int> >::iterator j = i + 1;
        if (j != myvector.end() && *j == *i) {
            i = myvector.erase(i);
            continue;
        } else {
            i++;
        }
    }		ifs.close();
				return myvector.size();
}


int sba(string filename){
    
    string line;
    istringstream is2(line);
    set<pair<int,int> > myset;
    ifs.open(filename.c_str());
    while(getline(ifs, line)){
        istringstream is2(line);
        int a,b;
        if (line[0] != '#'){
            is2 >> a >> b;
            pair<int, int> p1 = make_pair(a, b);
            pair<int, int> p2 = make_pair(b, a);
            if (a > b) {
                myset.insert(p1);
            } else {
                myset.insert(p2);
            }
        }
    }
    ifs.close();
    return myset.size();
}
