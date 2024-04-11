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

const int mod = inf + 7;

const int N = 1e5 + 5;
const int X = 1 << 20;

int n, q;
int a[N];
int res[N];
vec< pii > Q[N];
int dp[X];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int l, x, i = 0;i < q;i++) {
        scanf("%d %d", &l, &x);
        Q[l].push_back({i, x});
    }

    dp[0] = 1;

    int pw = 1;

    for(int i = 1;i <= n;i++) {
        if(dp[a[i]]) {
            pw += pw;
            if(pw >= mod) pw -= mod;
        }else {
            for(int x = 0;x < X;x++) {
                dp[x ^ a[i]] |= dp[x];
            }
        }
        for(pii t : Q[i]) {
            if(dp[t.second]) {
                res[t.first] = pw;
            }
        }
    }

    for(int i = 0;i < q;i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}