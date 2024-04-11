#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;
const double pi = acos(-1.0);

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m, k;

    cin >> n >> m >> k;

    vec< vec< int > > c(n + 1, vec< int >(k + 1, inf));

    for(int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        vec< int > pr(m);
        for(int j = 0;j < m;j++) {
            if(j > 0) pr[j] = pr[j - 1];
            if(s[j] == '1') pr[j]++;
        }
        if(pr[m - 1] <= k) {
            c[i][pr[m - 1]] = 0;
        }
        for(int l = 0;l < m;l++) {
            for(int r = l;r < m;r++) {
                int tm = 0;
                if(l > 0) tm += pr[l - 1];
                if(r + 1 < m) tm += pr[m - 1] - pr[r];
                if(tm <= k) {
                    c[i][tm] = min(c[i][tm], r - l + 1);
                }
            }
        }
    }

    vec< vec< int > > dp(n + 1, vec< int >(k + 1, inf));

    dp[0][0] = 0;

    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= k;j++) {
            for(int ad = 0;j + ad <= k;ad++) {
                dp[i][j + ad] = min(dp[i][j + ad], dp[i - 1][j] + c[i][ad]);
            }
        }
    }

    int res = inf;

    for(int j = 0;j <= k;j++) {
        res = min(res, dp[n][j]);
    }

    cout << res << "\n";

    return 0;
}