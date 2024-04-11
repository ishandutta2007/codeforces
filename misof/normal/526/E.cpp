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
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int N, Q;
long long A[1<<20];
long long B[64];
long long S[1<<21];
int Z[21][1<<20];
int UZ[1<<20], BUD[1<<20];

int visited[1<<20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    REP(n,N) cin >> A[n];
    REP(q,Q) cin >> B[q];
    S[0] = 0;
    REP(n,N) S[n+1] = S[n] + A[n];
    REP(n,N) S[N+n+1] = S[N+n] + A[n];
    REP(q,Q) {
        if (S[N] <= B[q]) {
            cout << "1\n";
            continue;
        }
        // zistime kolko da spravit na jeden skok
        {
            int hi = 0;
            for (int lo=0; lo<N; ++lo) {
                while (S[hi+1] - S[lo] <= B[q]) ++hi;
                Z[0][lo] = hi-lo;
            }
        }

        int ANSWER = N+7;

        for (int n=0; n<N; ++n) visited[n] = 0;

        for (int n=0; n<N; ++n) if (visited[n] == 0) {
            // simulujeme z n kym nenajdeme bud cyklus alebo nieco uz spracovane
            int kde = n;
            while (true) {
                visited[kde] = 2;
                kde += Z[0][kde];
                if (kde >= N) kde -= N;
                if (visited[kde]) break;
            }
            int skus = -1;
            if (visited[kde] == 2) skus = kde;
            kde = n;
            while (true) {
                visited[kde] = 1;
                kde += Z[0][kde];
                if (kde >= N) kde -= N;
                if (visited[kde] == 1) break;
            }
            if (skus == -1) continue;
            kde = skus;
            int answer = 0;
            while (true) {
                ++answer;
                kde += Z[0][kde%N];
                if (kde >= skus+N) break;
            }
            ANSWER = min( ANSWER, answer );
        }
        cout << ANSWER << "\n" << flush;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread