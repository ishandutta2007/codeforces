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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 1e9+7, MX = 1e5+5;

ll pot (ll b, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) res = res * b % mod;
        b = b * b % mod;
        p /= 2;
    }
    return res;
}

ll f (int n) {
    if (n + 1 <= 0) return 0;
    return pot(2, n+1) - 1;
} 

int n, q, acu[MX];
char c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        acu[i] = acu[i-1];
        if (c == '1') acu[i]++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int x = acu[r] - acu[l-1];
        int y = r - l + 1;

        if (!x) {
            cout << 0 << endl;
        } else {
            cout << MOD(f(y-1) - f(y-1-x), mod) << endl;
        }
    }

	return 0;
}