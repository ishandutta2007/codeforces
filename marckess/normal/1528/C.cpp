#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, a[MX], b[MX], ini[MX], fin[MX], f[MX], cn, res, acu, ex[MX];
vi ta[MX], tb[MX];
set<int> st;

void pre (int u) {
	ini[u] = ++cn;
	f[cn] = u;
	
	for (int v : tb[u])
		pre(v);
	
	fin[u] = cn;
}

bool valid (int u) {
	auto it = st.upper_bound(ini[u]);
	return it == st.end() || fin[u] < *it;
}

void dfs (int u) {
	if (valid(u)) {
		acu++;
		ex[u] = 1;
	}
	
	st.insert(ini[u]);
	auto it = st.lower_bound(ini[u]);
	
	if (it != st.begin()) {
		it--;
		int v = f[*it];
		
		if (ex[v] && !valid(v)) {
			ex[v] = 0;
			acu--;
		}
	}
	
	res = max(res, acu);
	
	for (int v : ta[u])
		dfs(v);
		
	if (ex[u]) {
		acu--;
		ex[u] = 0;
	}
	
	st.erase(ini[u]);
	it = st.lower_bound(ini[u]);
	
	if (it != st.begin()) {
		it--;
		int v = f[*it];
		
		if (!ex[v] && valid(v)) {
			ex[v] = 1;
			acu++;
		}
	}
}

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		ta[i].clear();
		tb[i].clear();
		ex[i] = 0;
	}
	
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		ta[a[i]].pb(i);
	}
	
	for (int i = 2; i <= n; i++) {
		cin >> b[i];
		tb[b[i]].pb(i);
	}
	
	cn = 0;
	pre(1);
	
	st.clear();
	acu = res = 0;
	dfs(1);
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}