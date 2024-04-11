#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mx = 200005, mod = 998244353;
int n, m, s, b[mx];
ll res = 1;

ll pot (ll b, int p) {
    ll res = 1;
    
    while (p) {
        if (p & 1) res = res * b % mod;
        b = b * b % mod;
        p /= 2;
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    for (int i = 1; i <= m; i++) {
        ll x = pot(s, b[i] - b[i-1]);
        res *= x * (x + 1) % mod * pot(2, mod-2) % mod;
        res %= mod;
    }

    res = res * pot(s, n - b[m] * 2) % mod;
    cout << res << endl;

    return 0;
}