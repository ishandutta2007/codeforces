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
    cout << 302 << endl;
    cout << "0 255000" << endl;
    int kde = 250000;
    for (int n=300; n>=1; --n) {
        cout << kde << " " << n << endl;
        kde += 2*n;
    }
    cout << "1000000 1000000" << endl;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread