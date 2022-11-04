
// Problem : A. Web of Lies
// Contest : Codeforces - Codeforces Round #736 (Div. 1)
// URL : https://codeforces.com/contest/1548/problem/A
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

const int MX = 200005;
int n, m, res;
set<int> fr[MX];

int query (int u) {
	return *fr[u].rbegin() < u;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	res = n;
	
	for (int i = 1; i <= n; i++)
		fr[i].insert(-1);
		
	while (m--) {
		int u, v;
		cin >> u >> v;
		
		res -= query(u);
		res -= query(v);
		
		fr[u].insert(v);
		fr[v].insert(u);
		
		res += query(u);
		res += query(v);
	}
	
	int q;
	cin >> q;
	
	while (q--) {
		int op;
		cin >> op;
		
		if (op == 1) {
			int u, v;
			cin >> u >> v;
			
			res -= query(u);
			res -= query(v);
			
			fr[u].insert(v);
			fr[v].insert(u);
			
			res += query(u);
			res += query(v);
		} else if (op == 2) {
			int u, v;
			cin >> u >> v;
			
			res -= query(u);
			res -= query(v);
			
			fr[u].erase(v);
			fr[v].erase(u);
			
			res += query(u);
			res += query(v);
		} else {
			cout << res << endl;
		}
	}
	
	return 0;
}