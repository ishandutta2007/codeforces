#include <bits/stdc++.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const int LOG = 40;

int n;
ull k;
vec< int > f, w;

struct FunctionalGraphPaths {
    vec< int > F[LOG];
    vec< ull > S[LOG];
    vec< int > M[LOG];
    FunctionalGraphPaths() {
        for(int i = 0;i < LOG;i++) {
            F[i].resize(n, -1);
            S[i].resize(n, 0);
            M[i].resize(n, inf);
        }
        for(int i = 0;i < n;i++) {
            F[0][i] = f[i];
            S[0][i] = M[0][i] = w[i];
        }
        for(int i = 1;i < LOG;i++) {
            for(int j = 0;j < n;j++) {
                int _p = F[i - 1][j];
                int _q = F[i - 1][_p];
                // j -> _p -> _q;
                F[i][j] = _q;
                S[i][j] = S[i - 1][j] + S[i - 1][_p];
                M[i][j] = min(M[i - 1][j], M[i - 1][_p]);
            }
        }
    }
    pair< ull, int > get(int v) const {
        ull SUM = 0;
        int MIN = inf;
        ull LEN = k;
        for(int i = LOG - 1;i >= 0 && LEN > 0;i--) {
            if((1ll << i) > LEN) continue;
            LEN -= (1ll << i);
            SUM += S[i][v];
            MIN = min(MIN, M[i][v]);
            v = F[i][v];
        }
        return mp(SUM, MIN);
    }
} ;

bool solve() {

    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    f.resize(n);
    w.resize(n);
    for(int i = 0;i < n;i++) cin >> f[i];
    for(int i = 0;i < n;i++) cin >> w[i];

    FunctionalGraphPaths fgp;

    for(int i = 0;i < n;i++) {
        pair< ull, int > T = fgp.get(i);
        cout << T.first << ' ' << T.second << '\n';
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}