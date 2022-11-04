#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 300005, mod = 1000000007;
int n, a;
ll f[MX], in[MX], res = 0, sum[MX];
vi pos[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	if (k < 0 || n < 0 || n < k) return 0;
	return f[n] * in[k] % mod * in[n-k] % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	f[0] = in[0] = 1;
	for (int i = 1; i < MX; i++) {
		f[i] = i * f[i-1] % mod;
		in[i] = pot(f[i], mod - 2);
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int i = 2; i * i <= a; i++)
			if (a % i == 0) {
				pos[i].pb(0);
				while (a % i == 0) {
					a /= i;
					pos[i].back()++;
				}
			}
		if (a > 1)
			pos[a].pb(1);
	}

	for (int i = 0; i <= n - 1; i++) {
		if (i) sum[i] = sum[i-1];
		(sum[i] += comb(n - 1, i)) %= mod;
	}

	for (int i = 2; i < MX; i++)
		if (pos[i].size()) {
			sort(all(pos[i]));
			int a = n - pos[i].size();
			int b = n - a - 1;

			for (int x : pos[i]) {
				if (a) res += x * sum[a-1] % mod;
				if (b) res -= x * sum[b-1] % mod;
				a++, b--;
			}

			res %= mod;
		}

	cout << MOD(res, mod) << endl;

	return 0;
}