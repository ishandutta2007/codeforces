#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

int main() {

    int n;

    cin >> n;

    string s;
    cin >> s;

    s = " " + s;

    vec< int > a(26);
    for(int i = 0;i < 26;i++) cin >> a[i];

    vec< int > dp(n + 1);
    vec< int > mx(n + 1);
    vec< int > cn(n + 1, inf);

    dp[0] = 1;
    mx[0] = 0;
    cn[0] = 0;

    for(int i = 1;i <= n;i++) {
        for(int mn = inf, j = i;j >= 1;j--) {
            mn = min(mn, a[ s[j] - 'a' ]);
            if(mn < i - j + 1) break;
            dp[i] = (dp[i] + dp[j - 1]) % mod;
            mx[i] = max(mx[i], max(mx[j - 1], i - j + 1) );
            cn[i] = min(cn[i], cn[j - 1] + 1);
        }
    }

    cout << dp[n] << "\n" << mx[n] << "\n" << cn[n] << "\n";

    return 0;
}