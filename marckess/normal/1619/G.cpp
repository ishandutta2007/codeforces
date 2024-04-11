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

const int MX = 200005;
int n, k, p[MX];
vvi v;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

void main_() {
	cin >> n >> k;
	
	v.clear();
	iota(p, p + n, 0);
	
	forn (i, n) {
		int x, y, t;
		cin >> x >> y >> t;
		v.pb({x, y, t, i});
	}
	
	sort(all(v), [&] (const vi &a, const vi &b) {
		if (a[0] == b[0]) return a[1] < b[1];
		return a[0] < b[0];
	});
	
	for (int i = 1; i < n; i++)
		if (v[i - 1][0] == v[i][0])
			if (abs(v[i - 1][1] - v[i][1]) <= k)
				join(v[i - 1][3], v[i][3]);
	
	sort(all(v), [&] (const vi &a, const vi &b) {
		if (a[1] == b[1]) return a[0] < b[0];
		return a[1] < b[1];
	});
	
	for (int i = 1; i < n; i++)
		if (v[i - 1][1] == v[i][1])
			if (abs(v[i - 1][0] - v[i][0]) <= k)
				join(v[i - 1][3], v[i][3]);
	
	sort(all(v), [&] (const vi &a, const vi &b) {
		return a[3] < b[3];
	});
	
	map<int, int> mp;
	forn (i, n) {
		if (!mp.count(parent(i)))
			mp[parent(i)] = 1e9;
		mp[parent(i)] = min(mp[parent(i)], v[i][2]);
	}
	
	vi v;
	for (auto it : mp)
		v.pb(it.se);
	sort(all(v));
	
	forn (i, v.size()) {
		int t = int(v.size()) - i - 1;
		if (v[i] >= t) {
			cout << t << endl;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}