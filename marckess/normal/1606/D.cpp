
// Problem : D. Red-Blue Matrix
// Contest : Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1606/problem/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
typedef vector<vii> vvii;

int n, m;
vvi a;
vvii pre, suf;

void main_() {
	cin >> n >> m;
	
	a = vvi(n, vi(m));
	pre = suf = vvii(n, vii(m));
	
	forn (i, n)
		forn (j, m)
			cin >> a[i][j];
	
	forn (i, n) {
		pre[i][0] = {a[i][0], a[i][0]};
		for (int j = 1; j < m; j++) {
			pre[i][j].fi = min(pre[i][j - 1].fi, a[i][j]);
			pre[i][j].se = max(pre[i][j - 1].se, a[i][j]);
		}
		
		suf[i][m - 1] = {a[i][m - 1], a[i][m - 1]};
		for (int j = m - 2; j >= 0; j--) {
			suf[i][j].fi = min(suf[i][j + 1].fi, a[i][j]);
			suf[i][j].se = max(suf[i][j + 1].se, a[i][j]);
		}
	}
	
	forn (k, m - 1) {
		vii v;
		forn (i, n)
			v.pb({pre[i][k].fi, i});
		sort(all(v), greater<ii>());
		
		vii izq(n), der(n);
		
		forn (i, n) {
			izq[i] = pre[v[i].se][k];
			der[i] = suf[v[i].se][k + 1];
		}
		
		for (int i = 1; i <= n - 1; i++) {
			izq[i].fi = min(izq[i].fi, izq[i - 1].fi);
			der[i].se = max(der[i].se, der[i - 1].se);
		}
		
		for (int i = n - 2; i >= 0; i--) {
			izq[i].se = max(izq[i].se, izq[i + 1].se);
			der[i].fi = min(der[i].fi, der[i + 1].fi);
		}
		
		forn (i, n - 1) {
			if (izq[i].fi > izq[i + 1].se)
			if (der[i].se < der[i + 1].fi) {
				cout << "YES" << endl;
				
				string res(n, 'B');
				forn (j, i + 1)
					res[v[j].se] = 'R';
				cout << res << " " << k + 1 << endl;
				return;
			}
		}
	}
	
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}