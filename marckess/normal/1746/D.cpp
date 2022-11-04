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
int n, k, p[MX];
ll s[MX];
vi adj[MX];
map<ii, ll> mem;

ll dp (int u, int k) {
	if (!k) return 0;
	
	if (mem.count({u, k})) return mem[{u, k}];
	
	ll &res = mem[{u, k}];
	res = s[u] * k;
	int sz = adj[u].size();
	
	if (!sz) return res;
	
	int a = k / sz;
	int b = (k + sz - 1) / sz;
	int r = k % sz;
	
	vi dif;
	for (int v : adj[u]) {
		res += dp(v, a);
		dif.pb(dp(v, b) - dp(v, a));
	}
	
	sort(all(dif), greater<ll>());
	forn (i, r)
		res += dif[i];
	
	return res;
}

void main_() {
	cin >> n >> k;

	forr (i, 1, n) {
		adj[i].clear();
	}
	mem.clear();
	
	forr (i, 2, n) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	
	forr (i, 1, n)
		cin >> s[i];
	
	cout << dp(1, k) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}