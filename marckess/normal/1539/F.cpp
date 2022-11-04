#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;

struct ST {
	int mn[4 * MX], mx[4 * MX], lz[4 * MX];
	
	void init () {
		memset(mn, 0, sizeof(mn));
		memset(mx, 0, sizeof(mx));
		memset(lz, 0, sizeof(lz));
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}
		
		mn[pos] += lz[pos];
		mx[pos] += lz[pos];
		lz[pos] = 0;
	}
	
	void update (int i, int j, int pos, int a, int b, ll k) {
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
		mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
	}
	
	ii query (int i, int j, int pos, int a, int b) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return {1e9, -1e9};
		
		if (a <= i && j <= b) return {mn[pos], mx[pos]};
		
		int m = (i + j) / 2;
		ii x = query(i, m, pos * 2, a, b);
		ii y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return {min(x.fi, y.fi), max(x.se, y.se)};
	}
}pre, suf;

int n, res[MX];
vi pos[MX];

ii operator - (const ii &a, const ii &b) {
	return {a.fi - b.fi, a.se - b.se};
}

int techo (int a, int b) {
	if (a < 0) return a / b;
	return (a + b - 1) / b;
}

void solve (int f) {
	pre.init();
	suf.init();
	
	for (int i = 1; i <= n; i++) {
		pre.update(1, n, 1, i, n, 1);
		suf.update(1, n, 1, 1, i, 1);
	}
	
	for (int i = 1; i <= n; i++) {
		if (f) for (int j : pos[i]) {
			pre.update(1, n, 1, j, n, -2);
			suf.update(1, n, 1, 1, j, -2);
		}
		
		for (int j : pos[i]) {
			ii a(0, 0), b(0, 0);
			
			if (j > 1)
				a = suf.query(1, n, 1, 1, j - 1) - suf.query(1, n, 1, j, j);
			
			if (j < n)
				b = pre.query(1, n, 1, j + 1, n) - pre.query(1, n, 1, j, j);
			
			a.fi = min(0, a.fi), b.fi = min(0, b.fi);
			a.se = max(0, a.se), b.se = max(0, b.se);
			
			res[j] = max(res[j], abs(techo(a.fi + b.fi, 2)));
			res[j] = max(res[j], abs(techo(a.se + b.se, 2)));
		}
				
		if (!f) for (int j : pos[i]) {
			pre.update(1, n, 1, j, n, -2);
			suf.update(1, n, 1, 1, j, -2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		pos[a].pb(i);
	}
	
	solve(0);
	solve(1);
	
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
	
	return 0;
}