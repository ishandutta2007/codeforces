#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

inline void relax(int &x, int y) {
    if(y < x) x = y;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;

    string s;
    cin >> s;

    sort(ALL(s));

    vec< vec< int > > dp[2];

    for(int i = 0;i < 2;i++) {
        dp[i].resize(k + 1, vec< int >(26, inf));
    }

    for(int i = 0;i < n;i++) {
        dp[i & 1] = dp[(i & 1) ^ 1];
        int cur = s[i] - 'a';
        relax(dp[i & 1][1][cur], cur + 1);
        for(int j = 1;j < k;j++) {
            for(int last = 0;last + 1 < cur;last++) {
                relax(dp[i & 1][j + 1][cur], dp[(i & 1) ^ 1][j][last] + cur + 1);
            }
        }
    }

    int res = inf;

    for(int j = 0;j < 26;j++) {
        relax(res, dp[(n - 1) & 1][k][j]);
    }

    printf("%d\n", res == inf ? -1 : res);

    return 0;
}