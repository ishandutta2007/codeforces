
// Problem : G. Kuzya and Homework
// Contest : Codeforces - Codeforces Round #750 (Div. 2)
// URL : https://codeforces.com/contest/1582/problem/G
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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
		forn (i, 4 * MX)
			mn[i] = MX;
	}
	
	void update (int i, int j, int pos, int a, int b, int k) {
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			mn[pos] = min(mn[pos], k);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);
	}
	
	int query (int i, int j, int pos, int a) {
		if (i == j) return mn[pos];
		
		int m = (i + j) / 2;
		if (a <= m)
			return min(mn[pos], query(i, m, pos * 2, a));
		return min(mn[pos], query(m + 1, j, pos * 2 + 1, a));
	}
}st;

int n, a[MX], bs[MX];
string s;
vi pos[MX], cn[MX];

void main_() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> s;
	s = " " + s;
	
	st.init();
	st.update(1, n, 1, 1, n, n);
	
	forn (i, MX) {
		pos[i].pb(0);
		cn[i].pb(0);
	}
	
	for (int i = 1; i <= n; i++)
		while (bs[a[i]] > 1) {
			if (pos[bs[a[i]]].back() != i) {
				pos[bs[a[i]]].pb(i);
				cn[bs[a[i]]].pb(0);
			}
			cn[bs[a[i]]].back()++;
			
			a[i] /= bs[a[i]];
		}
		
	forn (i, MX) {
		int acu = 0;
		vi &v = pos[i], &c = cn[i];
		stack<ii> mp;
		
		mp.emplace(0, v.size());
		
		for (int j = (int)v.size() - 1; j > 0; j--) {
			if (s[v[j]] == '*') acu += c[j];
			else acu -= c[j];
			
			while (mp.size() && mp.top().fi <= acu)
				mp.pop();
			
			int to = n;
			if (mp.size())
				to = min(to, v[mp.top().se - 1] - 1);
			
			mp.emplace(acu, j);
			st.update(1, n, 1, v[j - 1] + 1, v[j], to);
		}
	}
	
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int to = st.query(1, n, 1, i);
		res += to - i + 1;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			
			for (ll j = 1ll * i * i; j < MX; j += i)
				bs[j] = i;
		}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}