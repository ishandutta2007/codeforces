// Powered by CP Editor (https://cpeditor.org)

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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105, mod = 998244353;
int n, vis[MX], mn[MX];
ll mem[MX][MX];
ii a[MX];
vi v, cl[MX];

int dis (ii &a, ii &b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

ll dp (int i, int j) {
	if (i == v.size()) return 1;
	
	ll &res = mem[i][j];
	if (res != -1) return res;
	
	res = dp(i + 1, j - v[i]);
	forn (k, v[i])
		(res *= j - k) %= mod;
	
	if (v[i] > 1)
		(res += j * dp(i + 1, j - 1)) %= mod;
	
	return res;
}

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i].fi >> a[i].se;
	
	forn (i, n) {
		int p = 2e9;
		vi v;
		
		forn (j, n) {
			if (i == j) continue;
			int d = dis(a[i], a[j]);
			
			if (d == p) v.pb(j);
			else if (d < p) {
				p = d;
				v = {j};
			}
		}
		
		mn[i] = p;
		cl[i] = v;
	}
	
	forn (i, n) {
		if (vis[i]) continue;
		
		set<int> st;
		int f = 1;
		
		st.insert(i);
		for (int j : cl[i]) {
			st.insert(j);
			
			if (mn[i] != mn[j])
				f = 0;
			
			if (cl[i].size() != cl[j].size())
				f = 0;
		}
	
		for (int u : st)
			for (int v : cl[u])
				f &= st.count(v);
		
		if (f) {
			for (int u : st)
				vis[u] = 1;
			v.pb(st.size());
		} else {
			vis[i] = 1;
			v.pb(1);
		}
	}
	
	memset(mem, -1, sizeof(mem));
	cout << dp(0, n) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}