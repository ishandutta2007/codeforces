#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1'000'005, mod = 1'000'000'007;
int n, k, a[MX], q[MX];
ll l;
vector<vector<ll>> dp;

ll techo (ll x, ll y) {
    return (x + y - 1) / y;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    iota(q, q+n, 0);
    sort(q, q+n, [&] (int i, int j) {
        return a[i] < a[j];
    });

    dp.assign(n+1, vector<ll>(k+1));

    for (int j = k - 1; j >= 0; j--) {
        ll acu = 0;
        int z = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int u = q[i];
            while (z >= 0 && a[q[z]] >= a[u]) {
                acu += dp[z][j+1];
                acu %= mod;
                z--;
            }

            ll d = max(0LL, techo(l - u, n) - j) % mod;
            dp[i][j] = (acu + d) % mod;
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++)
        res += dp[i][0];
    cout << res % mod << endl;

    return 0;
}