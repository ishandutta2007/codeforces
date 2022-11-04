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

const int MX = 200005, mod = 998244353;
int n, a[MX];
ll fac[MX], inv[MX], dp[MX], pre[MX], suf[MX];
map<ll, ll> mp, ms;
vii pos;

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
	if (n < 0 || k < 0 || n - k < 0) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void main_() {
	cin >> n;
	forr (i, 1, n)
		cin >> a[i];
	
	mp.clear();
	mp[0] = 0;
	forr (i, 1, n) {
		pre[i] = pre[i - 1] + a[i];
		if (!mp.count(pre[i]))
			mp[pre[i]] = i;
	}
	
	ms.clear();
	ms[0] = n + 1;
	suf[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + a[i];
		if (!ms.count(suf[i]))
			ms[suf[i]] = i;
	}
	
	pos.clear();
	forn (i, n + 1) {
		if (mp[pre[i]] == i && ms.count(pre[i])) {
			if (mp[pre[i]] >= ms[pre[i]]) {
				break;
			}
			
			pos.pb({mp[pre[i]], ms[pre[i]]});
		}
	}
	
	ll acu = 1;
	for (int i = (int)pos.size() - 1; i >= 0; i--) {
		ii p = pos[i];
		int x = 0;
		while (x + p.fi + 1 < p.se && a[x + p.fi + 1] == 0)
			x++;
		
		int y = 0;
		while (p.se - y - 1 > p.fi && a[p.se - y - 1] == 0)
			y++;
		
		if (x + p.fi + 1 == p.se) {
			if (!p.fi)
				dp[i] = pot(2, x - 1);
			else
				dp[i] = pot(2, x + 1) - 1;
		} else {
			ll f = 0;
			
			if (p.fi) {
				for (int i = 1; i <= min(x, y) + 1; i++)
					(f += comb(x + 1, i) * comb(y + 1, i)) %= mod;
			} else {
				for (int i = 0; i <= min(x, y); i++)
					(f += comb(x, i) * comb(y, i)) %= mod;
			}
			
			dp[i] = f * acu % mod;
		}
		
		(acu += dp[i]) %= mod;
	}
	
	cout << MOD(dp[0], mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	forr (i, 1, MX - 1) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}