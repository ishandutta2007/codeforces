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

inline int Read() {
    char ch = getchar();
    while (!((ch >= '0' && ch <= '9') || ch == '-')) ch = getchar();
    int x = 0, p = 1;
    if (ch == '-') p = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x * p;
}

bool solve() {

    int n, k;

    n = Read();
    k = Read();

    vec< vec< int > > u(n + 1, vec< int >(n + 1)), cost(n + 1, vec< int >(n + 1));

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) {
            //scanf("%d", &u[i][j]);
            u[i][j] = Read();
            u[i][j] += u[i][j - 1];
        }

    for(int l = 1;l <= n;l++) {
        for(int r = l + 1;r <= n;r++) {
            cost[l][r] = cost[l][r - 1] + u[r][r - 1] - (l?u[r][l - 1] : 0);
        }
    }

    vec< vec< int > > dp(n + 1, vec< int >(k + 1, inf)),
            best(n + 1, vec< int >(k + 1, n + 1));

    dp[0][0] = 0;
    for(int i = 1;i <= n;i++) {
        dp[i][1] = cost[1][i];
        best[i][1] = 0;
    }

    for(int c = 2;c <= k;c++) {
        for(int i = n;i >= 1;i--) {
            int l, r;
            l = best[i][c - 1];
            r = i == n ? n : best[i + 1][c];
            for(int j = l;j <= r;j++) {
                if(dp[i][c] > dp[j][c - 1] + (j + 1 <= i?cost[j + 1][i] : 0)) {
                    dp[i][c] = dp[j][c - 1] + (j + 1 <= i?cost[j + 1][i] : 0);
                    best[i][c] = j;
                }
            }
        }
    }

    printf("%d\n", dp[n][k]);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}