#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int lim = 1000000, mod = 1000000007;
int n, q;
ll p2[100005], inv2[100005];
string s[25], t;
vi pos[256], acu[256];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

vi obtZF (string &s) {
    int n = s.size();
    vi zf(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            zf[i] = min(r - i + 1, (int)zf[i - l]);
        
        while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
            zf[i]++;
        
        if (i + zf[i] - 1 > r)
            l = i, r = i + zf[i] - 1;
    }
    
    return zf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	p2[0] = inv2[0] = 1;
	for (int i = 1; i < 100005; i++) {
		p2[i] = 2 * p2[i - 1] % mod;
		inv2[i] = pot(p2[i], mod - 2);
		assert(p2[i] * inv2[i] % mod == 1);
	}
	
	cin >> n >> q >> s[0] >> t;
	
	forn (i, n) {
		if (s[i].size() > lim) break;
		s[i + 1] = s[i] + t[i] + s[i];
	}
	
	forn (i, n) {
		int c = t[i];
		pos[c].pb(i + 1);
		acu[c].pb(acu[c].size() ? acu[c].back() : 0);
		(acu[c].back() += p2[n - (i + 1)]) %= mod;
	}
	
	while (q--) {
		int k;
		string w;
		cin >> k >> w;
		
		int ind = 0;
		forn (i, n + 1)
			if (s[i].size() >= w.size()) {
				ind = i;
				break;
			}
		
		if (ind > k) {
			cout << 0 << endl;
			continue;
		}
		
		string s_pre = w + s[ind];
		string s_suf = s[ind] + w;
		
		vi pre = obtZF(s_pre);
		vi suf = obtZF(s_suf);
		
		ll res = 0;
		
		for (int i = w.size(); i < pre.size(); i++)
			if (pre[i] >= w.size())
				res++;
		
		(res *= p2[k - ind]) %= mod;
		
		for (int i = w.size(); i <= pre.size(); i++) {
			ll p = 0;
			int sz = int(pre.size()) - i;
			
			if (sz && (pre[i] < sz || sz >= w.size())) continue;
			
			if (sz + 1 < w.size()) {
				int r = int(w.size()) - (sz + 1);
				if (suf[s[ind].size() + sz + 1] < r) continue;
			}
			
			int c = w[sz];
			int y = upper_bound(all(pos[c]), k) - pos[c].begin(); y--;
			
			if (y < 0) continue;
			
			int x = upper_bound(all(pos[c]), ind) - pos[c].begin(); x--;
			
			if (x >= y) continue;
			
			p = acu[c][y];
			if (x >= 0) p -= acu[c][x];
			
			(p *= inv2[n - k]) %= mod; 
			
			(res += p) %= mod;
		}
		
		cout << MOD(res, mod) << endl;
	}
	
	return 0;
}