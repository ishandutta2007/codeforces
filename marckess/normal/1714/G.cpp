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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], b[MX], p[MX], res[MX];
vi adj[MX], st;

int dfs (int u, ll sa, ll sb) {
	sa += a[u];
	sb += b[u];
	
	st.pb(sb);
	
	auto it = upper_bound(all(st), sa);
	it--;
	res[u] = it - st.begin();
	
	for (int v : adj[u])
		dfs(v, sa, sb);
	
	st.pop_back();
}

void main_() {
	cin >> n;
	forr (i, 1, n) {
		adj[i].clear();
	}
	
	forr (i, 2, n) {
		cin >> p[i] >> a[i] >> b[i];
		adj[p[i]].pb(i);
	}
	
	st.clear();
	dfs(1, 0, 0);
	
	forr (i, 2, n)
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