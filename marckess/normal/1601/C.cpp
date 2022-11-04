
// Problem : C. Optimal Insertion
// Contest : Codeforces - Codeforces Round #751 (Div. 1)
// URL : https://codeforces.com/contest/1601/problem/C
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 1000005;

struct ST {
	int mn[4 * MX], lz[4 * MX];
	
	void init (int n) {
		for (int i = 1; i <= 4 * n; i++) {
			mn[i] = 0;
			lz[i] = 0;
		}
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}
		
		mn[pos] += lz[pos];
		lz[pos] = 0;
	}
	
	void update (int i, int j, int pos, int a, int b, int k) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			lz[pos] = k;
			push(i, j, pos);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);
		
		mn[pos] = min(mn[pos * 2], mn[pos * 2 + 1]);
	}
}st;

int n, m, a[MX], b[MX], cn[2 * MX], ft[2 * MX];
vi pos[2 * MX], c;

void update (int i, int k) {
	while (i < 2 * MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

void main_() {
	cin >> n >> m;
	
	c.clear();
	st.init(n + 1);
	
	forn (i, n) {
		cin >> a[i];
		c.pb(a[i]);
	}
	
	forn (i, m) {
		cin >> b[i];
		c.pb(b[i]);
	}
	
	sort(all(c));
	c.erase(unique(all(c)), c.end());
		
	forn (i, c.size() + 2) {
		pos[i].clear();
		cn[i] = 0;
		ft[i] = 0;
	}
	
	forn (i, n) {
		a[i] = lower_bound(all(c), a[i]) - c.begin();
		pos[a[i]].pb(i + 1);
	}
	
	forn (i, m) {
		b[i] = lower_bound(all(c), b[i]) - c.begin();
		cn[b[i]]++;
	}
	
	for (int i = 1; i <= n; i++)
		st.update(1, n + 1, 1, i + 1, n + 1, 1);
	
	ll res = 0;
	
	forn (i, n) {
		res += i - query(a[i] + 1);
		update(a[i] + 1, 1);
	}
	
	forn (i, c.size()) {
		for (int j : pos[i])
			st.update(1, n + 1, 1, j + 1, n + 1, -1);
		
		st.push(1, n + 1, 1);
		res += 1ll * cn[i] * st.mn[1];
		 		
		for (int j : pos[i])
			st.update(1, n + 1, 1, 1, j, 1);
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