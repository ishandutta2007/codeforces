
// Problem : E. Boring Segments
// Contest : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1555/problem/E
// Memory Limit : 256 MB
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
	
	void init () {
		memset(mn, 0, sizeof(mn));
		memset(lz, 0, sizeof(lz));
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}
		
		mn[pos] += lz[pos];
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
	}
}st;

int n, m;
vvi v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	forn (i, n) {
		int l, r, w;
		cin >> l >> r >> w;
		v.pb({w, l, r - 1});
	}
	
	sort(all(v));
	
	int i = 0, j = -1, res = 1e9;
	
	st.init();
	while (i < n) {
		while (j + 1 < n && st.mn[1] <= 0) {
			j++;
			st.update(1, m - 1, 1, v[j][1], v[j][2], 1);
		}
		
		if (st.mn[1] > 0)
			res = min(res, v[j][0] - v[i][0]);
		
		st.update(1, m - 1, 1, v[i][1], v[i][2], -1);
		i++;
	}
	
	cout << res << endl;
	
	return 0;
}