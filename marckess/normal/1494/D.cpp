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

const int MX = 505;
int n, sz, a[MX][MX];
vi s;
vii res;

void go (vi &v, int mx, int p) {
	if (v.size() == 1) {
		res.emplace_back(v[0], p);
		return;
	}
	
	int act = -1;
	for (int i : v)
		forn (j, n)
			if (a[i][j] < mx && a[i][j] > act)
				act = a[i][j];
	
	map<vi, vi> mp;
	for (int i : v) {
		vi w;
		forn (j, n)
			if (a[i][j] == act)
				w.pb(j);
		mp[w].pb(i);
	}
	
	int u = sz++;
	s.pb(act);
	if (p != -1)
		res.emplace_back(u, p);
	
	for (auto it = mp.begin(); it != mp.end(); it++)
		go(it->se, act, u);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n)
		forn (j, n)
			cin >> a[i][j];
	
	forn (i, n)
		s.pb(a[i][i]);
	
	int r = n + 1;
	sz = n;
	
	vi v;
	forn (i, n)
		v.pb(i);
	go(v, 1e9, -1);
	
	cout << sz << endl;
	
	for (int x : s)
		cout << x << " ";
	cout << endl;
	
	cout << r << endl;
	
	for (auto &[u, v] : res)
		cout << u + 1 << " " << v + 1 << endl;
	
	return 0;
}