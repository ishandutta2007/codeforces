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

long long best[1024][2048];
long long INF = 12345678901234LL;
int D[1024], S[1024];

int main() {
    int M, K;
    cin >> M >> K;
    for (int m=0; m<M; ++m) cin >> D[m];
    for (int m=0; m<M; ++m) cin >> S[m];
    S[M] = 0;

    for (int m=0; m<=M; ++m) for (int p=0; p<2048; ++p) best[m][p] = INF;
    best[0][S[0]] = 0;
    int bests = S[0];
    for (int m=0; m<M; ++m) {
        bests = max( bests, S[m] );
        // update fuel times
        for (int p=0; p+bests<2048; ++p) best[m][p+bests] = min( best[m][p+bests], best[m][p] + K );
        // try traveling
        for (int p=D[m]; p<2048; ++p) if (best[m][p] != INF) {
            best[m+1][min(2047,p-D[m]+S[m+1])] = best[m][p] + D[m];
            //cout << (m+1) << " " << min(2047,p-D[m]+S[m+1]) << ": " << best[m+1][min(2047,p-D[m]+S[m])] << endl;
        }
    }
    long long answer = best[M][0];
    for (int p=1; p<2048; ++p) answer = min( answer, best[M][p] );
    cout << answer << endl;
    return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread