
// Problem : D. Weights Assignment For Tree Edges
// Contest : Codeforces - Codeforces Round #756 (Div. 3)
// URL : https://codeforces.com/contest/1611/problem/D
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
int n, a[MX], b[MX], dis[MX], res[MX];
vi adj[MX];

void main_() {
	cin >> n;
	
	forr(i, 1, n) adj[i].clear();
	forr(i, 1, n) {
		cin >> a[i];
		if (a[i] != i)
			adj[a[i]].pb(i);
	}
	forr(i, 1, n) cin >> b[i];
	
	if (a[b[1]] != b[1]) {
		cout << -1 << endl;
		return;
	}
	
	dis[b[1]] = res[b[1]] = 0;
	set<int> st;
	
	for (int u : adj[b[1]])
		st.insert(u);
	
	forr (i, 2, n) {
		if (!st.count(b[i])) {
			cout << -1 << endl;
			return;
		}
		
		res[b[i]] = (dis[b[i]] = i) - dis[a[b[i]]];
		
		st.erase(b[i]);
		for (int u : adj[b[i]])
			st.insert(u);
	}
	
	forr (i, 1, n)
		cout << res[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}