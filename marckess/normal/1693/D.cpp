#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 200005;
int n, p[MX], to[MX], sig[MX], ant[MX], ft[MX];
vi ps[MX], pa[MX];

void init (int ini) {
	fill(ft, ft + MX, ini);
}

void update (int i, int k) {
	while (i < MX) {
		ft[i] = min(ft[i], k);
		i += i & -i;
	}
}

int query (int i) {
	int res = MX;
	while (i) {
		res = min(res, ft[i]);
		i -= i & -i;
	}
	return res;
}

void go () {
	map<int, int> mp;
	for (int i = n; i >= 1; i--) {
		auto it = mp.lower_bound(p[i]);
		if (it != mp.end())
			sig[i] = it->se;
		else
			sig[i] = 0;
		
		while (mp.size() && mp.begin()->fi < p[i])
			mp.erase(mp.begin());
		mp[p[i]] = i;
	}
	
	mp.clear();
	forr (i, 1, n) {
		auto it = mp.lower_bound(p[i]);
		if (it != mp.begin()) {
			it--;
			ant[i] = it->se;
		} else
			ant[i] = 0;
		
		while (mp.size() && mp.rbegin()->fi > p[i])
			mp.erase(mp.rbegin()->fi);
		mp[p[i]] = i;
	}
	
	forr (i, 1, n) {
		ps[i].clear();
		pa[i].clear();
	}
	
	forr (i, 1, n) {
		ps[sig[i]].pb(i);
		pa[ant[i]].pb(i);
	}
	
	init(n);
	for (int i = n; i >= 1; i--) {
		for (int j : ps[i])
			to[j] = min(to[j], query(p[j]));
		
		for (int j : pa[i])
			update(p[j], j - 1);
	}
}

void main_() {
	cin >> n;
	forr (i, 1, n) {
		cin >> p[i];
		to[i] = n;
	}
	
	go();
	forr (i, 1, n)
		p[i] = n + 1 - p[i];
	go();
	
	ll res = 0;
	int mn = n;
	for (int i = n; i >= 1; i--) {
		mn = min(mn, to[i]);
		res += mn - i + 1;
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}