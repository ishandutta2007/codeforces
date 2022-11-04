// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 200005, mod = 1000000007;

ii operator + (const ii &a, const ii &b) {
	ii res = {a.fi + b.fi, a.se + b.se};
	if (res.fi >= mod) res.fi -= mod;
	if (res.se >= mod) res.se -= mod;
	return res;
}

struct ST {
	ii st[4 * MX];
	
	void init (int n) {
		forn (i, 4 * n + 5)
			st[i] = {0, 0};
	}
	
	void update (int i, int j, int pos, int a, const ii &k) {
		if (a < i || j < a) return;
		
		if (i == j) {
			st[pos] = k;
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, k);
		update(m + 1, j, pos * 2 + 1, a, k);
		
		st[pos] = st[pos * 2] + st[pos * 2 + 1];
	}
	
	ii query (int i, int j, int pos, int a, int b) {
		if (b < i || j < a) return {0, 0};
		
		if (a <= i && j <= b) return st[pos];
		
		int m = (i + j) / 2;
		ii x = query(i, m, pos * 2, a, b);
		ii y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return x + y;
	}
}st;

int n, a[MX], pre[MX];
ii b[MX];

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		b[i] = {a[i], i + 1};
	}
	
	sort(b, b + n, [&] (const ii &a, const ii &b) {
		if (a.fi != b.fi) return a.fi < b.fi;
		return a.se > b.se;
	});
	st.init(n);
	
	forn (i, n) {
		auto &[_, j] = b[i];
		
		pre[j] = 1;
		if (j > 1) {
			pre[j] += st.query(1, n, 1, 1, j - 1).fi;
			if (pre[j] >= mod)
				pre[j] -= mod;
		}
		
		st.update(1, n, 1, j, {pre[j], 0});
	}
	
	ll res = 0, last = 0;
	stack<int> s;
	
	sort(b, b + n, [&] (const ii &a, const ii &b) {
		if (a.fi != b.fi) return a.fi > b.fi;
		return a.se < b.se;
	});
	st.init(n);
	
	forn (i, n) {
		auto &[_, j] = b[i];
		ii p;
		
		if (last < j) {
			while (s.size()) {
				int u = s.top();
				s.pop();
				
				ii r = st.query(1, n, 1, u, u);
				st.update(1, n, 1, u, {r.se, r.se});
			}
			
			p = {0, 1};
			last = j;
		} else {
			p = {1, 1};
		}
		s.push(j);
		
		if (j < n) {
			p = p + st.query(1, n, 1, j + 1, n);
		}
		st.update(1, n, 1, j, p);
		
		(res += 1ll * pre[j] * p.fi) %= mod;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}