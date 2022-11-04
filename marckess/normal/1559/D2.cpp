// Problem : D2. Mocha and Diana (Hard Version)
// Contest : Codeforces - Codeforces Round #738 (Div. 2)
// URL : https://codeforces.com/contest/1559/problem/D2
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int MX = 100005;
int n, m1, m2, p1[MX], p2[MX];
vii res;

int parent (int p[], int a) {
	return p[a] == a ? a : p[a] = parent(p, p[a]);
}

void join (int p[], int a, int b) {
	p[parent(p, a)] = parent(p, b);
}

bool same (int p[], int a, int b) {
	return parent(p, a) == parent(p, b);	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	iota(p1, p1 + MX, 0);
	iota(p2, p2 + MX, 0);
	
	cin >> n >> m1 >> m2;
	
	while (m1--) {
		int u, v;
		cin >> u >> v;
		join(p1, u, v);
	}
	
	while (m2--) {
		int u, v;
		cin >> u >> v;
		join(p2, u, v);
	}
	
	for (int i = 2; i <= n; i++)
		if (!same(p1, 1, i) && !same(p2, 1, i)) {
			res.pb({1, i});
			join(p1, 1, i);
			join(p2, 1, i);
		}
		
	set<int> s1, s2;
	for (int i = 2; i <= n; i++) {
		if (!same(p1, 1, i)) s1.insert(parent(p1, i));
		if (!same(p2, 1, i)) s2.insert(parent(p2, i));
	}
	
	for (auto it = s1.begin(), jt = s2.begin(); it != s1.end() && jt != s2.end(); it++, jt++)
		res.pb({*it, *jt});
	
	cout << res.size() << endl;
	for (ii &p : res)
		cout << p.fi << " " << p.se << endl;
	
	return 0;
}