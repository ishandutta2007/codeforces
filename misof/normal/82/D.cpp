// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////
#include <cstring>

int N;
int A[1024];
int memo[1024][1024];
int ako[1024][1024];

int solve(int prvy, int dalsi) {
    int &res = memo[prvy][dalsi];
    if (res >= 0) return res;
    if (dalsi == N) return res = A[prvy];
    if (dalsi == N-1) return res = max(A[prvy],A[dalsi]);
    res = max(A[prvy],A[dalsi]) + solve(dalsi+1,dalsi+2);
    res = min(res, max(A[prvy],A[dalsi+1]) + solve(dalsi,dalsi+2));
    res = min(res, max(A[dalsi],A[dalsi+1]) + solve(prvy,dalsi+2));
    return res;
}

int main() {
    cin >> N;
    REP(n,N) cin >> A[n];
    memset(memo,-1,sizeof(memo));
    cout << solve(0,1) << "\n";
    int prvy=0, dalsi=1;
    while (prvy < N) {
        if (dalsi == N) { cout << (prvy+1) << endl; break; }
        if (dalsi == N-1) { cout << (prvy+1) << " " << (dalsi+1) << endl; break; }
        if (solve(prvy,dalsi) == max(A[prvy],A[dalsi]) + solve(dalsi+1,dalsi+2)) {
            cout << (prvy+1) << " " << (dalsi+1) << endl;
            prvy = dalsi+1;
            dalsi = dalsi+2;
            continue;
        }
        if (solve(prvy,dalsi) == max(A[prvy],A[dalsi+1]) + solve(dalsi,dalsi+2)) {
            cout << (prvy+1) << " " << (dalsi+2) << endl;
            prvy = dalsi;
            dalsi = dalsi+2;
            continue;
        }
        cout << (dalsi+1) << " " << (dalsi+2) << endl;
        dalsi = dalsi+2;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread