#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int mod = 998244353;
ll n;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i == n) cout << 10;
		else {
			ll a = 2 * 10 * (10 - 1) % mod * pot(10, n - i - 1) % mod;
			ll b = (n - i - 1) * 10 % mod * pot(10 - 1, 2) % mod * pot(10, n - i - 2) % mod;
			cout << (a + b) % mod << " ";
		}
	}
	
	cout << endl;

	return 0;
}