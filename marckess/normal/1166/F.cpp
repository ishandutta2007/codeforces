#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, c, q, p[MX], x, y, z;
char op;
map<int, int> mp[MX];
set<int> st[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return;
	if (st[a].size() < st[b].size()) swap(a, b);
	for (int x : st[b]) st[a].insert(x);
	st[b].clear();
	p[b] = a;
}

bool same (int a, int b) {
	return parent(a) == parent(b);
}

void add () {
	if (!mp[x].count(z)) mp[x][z] = y;
	else join(mp[x][z], y);
	if (!mp[y].count(z)) mp[y][z] = x;
	else join(mp[y][z], x);
	st[parent(x)].insert(y);
	st[parent(y)].insert(x);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p+MX, 0);

	cin >> n >> m >> c >> q;
	while (m--) {
		cin >> x >> y >> z;
		add();
	}

	while (q--) {
		cin >> op >> x >> y;
		if (op == '+') {
			cin >> z;
			add();
		} else {
			if (same(x, y)) cout << "Yes" << endl;
			else if (st[parent(x)].count(y)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}