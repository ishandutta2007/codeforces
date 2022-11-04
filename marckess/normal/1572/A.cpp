
// Problem : A. Book
// Contest : Codeforces - Codeforces Round #743 (Div. 1)
// URL : https://codeforces.com/contest/1572/problem/A
// Memory Limit : 256 MB
// Time Limit : 1500 ms
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
int n, x[MX];
vi adj[MX];

void main_() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		x[i] = 0;
		adj[i].clear();
	}
	
	set<int> st;
	
	for (int i = 1; i <= n; i++)  {
		cin >> x[i];
		
		forn (j, x[i]) {
			int u;
			cin >> u;
			adj[u].pb(i);
		}
		
		if (!x[i])
			st.insert(i);
	}
	
	int res = 0;
	while (st.size()) {
		res++;
		
		for (auto it = st.begin(); it != st.end();) {
			for (int v : adj[*it]) {
				x[v]--;
				if (!x[v])
					st.insert(v);
			}
			
			auto jt = it;
			it++;
			st.erase(jt);
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (x[i]) {
			cout << -1 << endl;
			return;
		}
	
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