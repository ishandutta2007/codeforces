// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int main() {
    int N; cin >> N;
    string S; cin >> S;
    bool found = false;
    for (int d=1; 0+4*d<N; ++d) {
        for (int z=0; z+4*d<N; ++z) {
            bool ok = true;
            for (int i=0; i<5; ++i) if (S[z+i*d]!='*') ok = false;
            if (ok) found = true;
        }
    }
    cout << (found ? "yes" : "no") << endl;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread