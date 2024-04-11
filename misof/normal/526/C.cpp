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
    long long C, Hr, Hb, Wr, Wb;
    cin >> C >> Hr >> Hb >> Wr >> Wb;
    long long best = 0;
    if (Wr < Wb) { swap(Wr,Wb); swap(Hr,Hb); }

    if (Wr >= 1000) {
        for (long long i=0; i*Wr <= C; ++i) {
            best = max( best, i * Hr + ((C - i*Wr) / Wb) * Hb );
        }
    } else {
        if (Hr * Wb > Hb * Wr) { swap(Wr,Wb); swap(Hr,Hb); }
        for (long long i=0; i<=1000; ++i) {
            if (i * Wr > C) continue;
            best = max( best, i * Hr + ((C - i*Wr) / Wb) * Hb );
        }
    }
    cout << best << endl;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread