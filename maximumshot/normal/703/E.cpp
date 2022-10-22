#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long  ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;
    ll k;

    cin >> n >> k;

    vec< ll > a(n), div, b(n);
    for(int i = 0;i < n;i++) cin >> a[i], b[i] = __gcd(a[i], k);

    for(ll x = 1;x * x <= k;x++) {
        if(k % x) continue;
        div.push_back(x);
        if(x != k / x) div.push_back(k / x);
    }

    sort(ALL(div));
    int sz = (int)div.size();

    vec< vec< pair< int, ll > > > dp(n, vec< pair< int, ll > >(sz, mp(inf, inf64)));
    vec< vec< int > > par(n, vec< int >(sz, -1));

    for(int i = 0;i < sz;i++) {
        if(a[0] % div[i] == 0) dp[0][i] = {1, a[0]};
    }

    unordered_map< ll, int > um;

    um.reserve(sz);

    for(int i = 0;i < sz;i++) {
        um[div[i]] = i;
    }

    for(int i = 1;i < n;i++) {
        pair< int, ll > tmp;
        for(int y, j = 0;j < sz;j++) {
            if(a[i] % div[j] == 0) {
                dp[i][j] = {1, a[i]};
                par[i][j] = -1;
            }
            if(dp[i][j] > dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
                par[i][j] = j;
            }
            y = um[div[j] / __gcd(div[j], b[i])];
            tmp = {dp[i - 1][y].first + 1, dp[i - 1][y].second + a[i]};
            if(dp[i][j] > tmp) {
                dp[i][j] = tmp;
                par[i][j] = y;
            }
        }
    }

    if(dp[n - 1][sz - 1].first == inf) {
        cout << -1 << '\n';
        return true;
    }

    cout << dp[n - 1][sz - 1].first << '\n';

    for(int i = n - 1, j = sz - 1;;) {
        if(par[i][j] == -1) {
            cout << i + 1 << '\n';
            break;
        }else if(par[i][j] == j) {
            i--;
        }else {
            cout << i + 1 << ' ';
            j = par[i--][j];
        }
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}