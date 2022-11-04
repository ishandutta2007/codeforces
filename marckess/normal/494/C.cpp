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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, LG = 18;
int n, m, a[MX], st[MX][LG], l[MX], r[MX], o[MX], mx[MX], vis[5005][5005];
vi adj[MX];
ld p[MX], mem[5005][5005];

int query (int i, int j) {
	int k = log2(j - i + 1);
	return max(st[i][k], st[j - (1 << k) + 1][k]);
}

ld dp (int u, int k) {
	k = min(k, m);
	ld &res = mem[u][k];
	if (vis[u][k]) return res;
	vis[u][k] = 1;
	res = 0;

	ld x = 1 - p[u];
	for (int v : adj[u])
		x *= dp(v, k + mx[u] - mx[v]);
	res = x;

	if (k) {
		x = p[u];
		for (int v : adj[u])
			x *= dp(v, k - 1 + mx[u] - mx[v]);
		res += x;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i][0] = a[i];
		mx[m] = max(mx[m], a[i]);
	}

	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);

	forn (i, m) {
		cin >> l[i] >> r[i] >> p[i];
		mx[i] = query(l[i], r[i]);
	}

	iota(o, o + m, 0);
	sort(o, o + m, [&] (int i, int j) {
		return l[i] ^ l[j] ? l[i] < l[j] : r[i] > r[j];
	});

	stack<ii> st;
	forn (_, m) {
		int i = o[_];
		while (st.size() && st.top().fi < l[i]) st.pop();
		if (st.size()) adj[st.top().se].pb(i);
		else adj[m].pb(i);
		st.emplace(r[i], i);
	}

	ld res = mx[m] * dp(m, 0);
	for (int i = 1; i <= m; i++)
		res += (mx[m] + i) * (dp(m, i) - dp(m, i - 1));
	cout << res << endl;

	return 0;
}