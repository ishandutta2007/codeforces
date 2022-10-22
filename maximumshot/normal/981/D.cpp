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

const int N = 55;
const int LOG = 60;

int n, k;
ll a[N];

bool check(int I, ll mask) {
    ll hlp = 0;
    for(int j = LOG;j >= I;j--) hlp |= (1ll << j);

    vec< vec< int > > dp(k + 1, vec< int >(n + 1));

    {
        ll sum = 0;
        for(int i = 1;i <= n;i++) {
            sum += a[i];
            ll tmp = sum & hlp;
            if((mask & tmp) == mask) {
                dp[1][i] = 1;
            }
        }
    }
    for(int j = 2;j <= k;j++) {
        for(int i = j;i <= n;i++) {
            ll sum = 0;
            for(int q = i;q > j - 1;q--) {
                sum += a[q];
                if(!dp[j - 1][q - 1]) continue;
                ll tmp = sum & hlp;
                if((mask & tmp) == mask) {
                    dp[j][i] = 1;
                }
            }
        }
    }
    return dp[k][n];
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> k;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    ll res = 0;

    for(int i = LOG;i >= 0;i--) {
        if(check(i, res | (1ll << i))) {
            res |= (1ll << i);
        }
    }

    cout << res << "\n";

    return 0;
}