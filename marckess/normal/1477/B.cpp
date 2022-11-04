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
int n, q, x[MX], y[MX];
string s, f;

struct ST {
	int n;
	vi st, lz;
	
	void init (int _n) {
		n = _n;
		st = vi(4 * n, 0);
		lz = vi(4 * n, 0);
	}
	
	void push (int i, int j, int pos) {
		if (!lz[pos]) return;
		
		if (i < j) {
			lz[pos * 2] = lz[pos];
			lz[pos * 2 + 1] = lz[pos];
		}
		
		if (lz[pos] == -1) st[pos] = 0;
		else st[pos] = j - i + 1;
		lz[pos] = 0;
	}
	
	void update (int i, int j, int pos, int a, int b, int k) {
		push(i, j, pos);
		
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			lz[pos] = k;
			push(i, j, pos);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);
		
		st[pos] = st[pos * 2] + st[pos * 2 + 1];
	}
	
	int query (int i, int j, int pos, int a, int b) {
		push(i, j, pos);
		
		if (b < i || j < a) return 0;
		
		if (a <= i && j <= b) return st[pos];
		
		int m = (i + j) / 2;
		return query(i, m, pos * 2, a, b) + query(m + 1, j, pos * 2 + 1, a, b);
	}
}st;

void solve () {
	cin >> n >> q >> s >> f;
	forn (i, q) cin >> x[i] >> y[i];
	
	st.init(n);
	forn (i, n) {
		if (f[i] == '0')
			st.update(1, n, 1, i + 1, i + 1, -1);
		else
			st.update(1, n, 1, i + 1, i + 1, 1);
	}
	
	for (int i = q - 1; i >= 0; i--) {
		int si = st.query(1, n, 1, x[i], y[i]);
		int no = y[i] - x[i] + 1 - si;
		
		if (si < no) st.update(1, n, 1, x[i], y[i], -1);
		else if (si > no) st.update(1, n, 1, x[i], y[i], 1);
		else {
			cout << "NO" << endl;
			return;
		}
	}
	
	forn (i, n) {
		if (s[i] == '0' && st.query(1, n, 1, i + 1, i + 1)) {
			cout << "NO" << endl;
			return;
		}
		if (s[i] == '1' && !st.query(1, n, 1, i + 1, i + 1)) {
			cout << "NO" << endl;
			return;
		}
	}
	
	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
			
	return 0;
}