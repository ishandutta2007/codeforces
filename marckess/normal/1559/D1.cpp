
// Problem : D1. Mocha and Diana (Easy Version)
// Contest : Codeforces - Codeforces Round #738 (Div. 2)
// URL : https://codeforces.com/contest/1559/problem/D1
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

const int MX = 1005;
int n, m1, m2, p1[MX], p2[MX];
vii v;

int parent (int p[], int a) {
	return p[a] == a ? a : p[a] = parent(p, p[a]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	iota(p1, p1 + MX, 0);
	iota(p2, p2 + MX, 0);
	
	cin >> n >> m1 >> m2;
	
	while (m1--) {
		int u, v;
		cin >> u >> v;
		p1[parent(p1, u)] = parent(p1, v);
	}
	
	while (m2--) {
		int u, v;
		cin >> u >> v;
		p2[parent(p2, u)] = parent(p2, v);
	}
	
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (parent(p1, i) != parent(p1, j) && parent(p2, i) != parent(p2, j)) {
				res++;
				p1[parent(p1, i)] = parent(p1, j);
				p2[parent(p2, i)] = parent(p2, j);
				
				v.pb({i, j});
			}
	
	cout << res << endl;
	for (ii &p : v)
		cout << p.fi << " " << p.se << endl;
	
	return 0;
}