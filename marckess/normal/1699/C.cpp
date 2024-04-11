// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 1000000007;
int n, a[MX], f[MX];
ll fac[MX], inv[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void main_() {
	cin >> n;
	forr (i, 1, n) {
		cin >> a[i];
		f[a[i]] = i;
	}
	
	int l = f[0], r = f[0], mex = 1, dis = 0;
	set<int> st;
	st.insert(0);
	ll res = 1;
	
	while (mex < n) {
		int sig = f[mex];
		
		if (sig < l) {
			while (l > sig) {
				l--;
				st.insert(a[l]);
				dis++;
			}
		} else {
			while (r < sig) {
				r++;
				st.insert(a[r]);
				dis++;
			}
		}
		dis--;
		
		int x = 0;
		while (st.count(mex)) {
			mex++;
			x++;
		}
		x--;
		
		(res *= fac[dis]) %= mod;
		dis -= x;
		(res *= inv[dis]) %= mod;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	forr (i, 1, MX - 1) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
		assert(fac[i] * inv[i] % mod == 1);
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}