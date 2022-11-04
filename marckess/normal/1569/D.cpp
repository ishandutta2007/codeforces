
// Problem : D. Inconvenient Pairs
// Contest : Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1569/problem/D
// Memory Limit : 256 MB
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
int n, m, k, ft[MX];
set<int> sx, sy;
map<int, vi> mx, my;
ll res;

void update (int i, int k) { i += 2;
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) { i += 2;
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

void solve (map<int, vi> &mp, set<int>& st) {
	for (auto it = mp.begin(); it != mp.end(); it++) {
		for (int x : it->se) {
			auto nex = st.upper_bound(x);
			auto ant = nex; ant--;
			
			res += query(*nex - 1) - query(*ant);
		}
		
		for (int x : it->se) {
			update(x, 1);
		}
	}
	
	for (auto it = mp.begin(); it != mp.end(); it++) {
		for (int x : it->se) {
			update(x, -1);
		}
	}
}

void main_() {
	sx.clear(); sx.insert(-1), sx.insert(1e6 + 1);
	sy.clear(); sy.insert(-1), sy.insert(1e6 + 1);
	
	cin >> n >> m >> k;
	
	forn (i, n) {
		int x;
		cin >> x;
		sx.insert(x);
	}
	
	forn (i, m) {
		int y;
		cin >> y;
		sy.insert(y);
	}
	
	mx.clear(), my.clear();
	while (k--) {
		int x, y;
		cin >> x >> y;
		
		if (!sx.count(x)) mx[y].pb(x);
		if (!sy.count(y)) my[x].pb(y);
	}
	
	res = 0;
	solve(mx, sx);
	solve(my, sy);
	
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