#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1505, inf = 1e9+5;
int n, s, m, k, a[MX], b[MX], dp[MX][MX], fin[MX], sig[MX];
ii v[MX];
multiset<int> st;
vi ini[MX];

int obtRes (int i, int j) {
	if (j <= 0) return 0;
	if (i > n) return inf;

	int &res = dp[i][j];
	if (res != -1) return res;

	res = obtRes(i+1, j);
	if (sig[i] != -1)
		res = min(res, obtRes(sig[i]+1, j - (b[sig[i]] - b[i-1])) + 1);
	return res; 
}

bool esPos (int x) {
	memset(b, 0, sizeof(b));
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		if (a[i] <= x)
			b[i] = 1;
		b[i] += b[i-1];
	}

	return obtRes(1, k) <= m;
} 

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(sig, -1, sizeof(sig));

	cin >> n >> s >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= s; i++) {
		cin >> v[i].fi >> v[i].se;
		fin[v[i].se]++;
		ini[v[i].fi].pb(v[i].se);
	}

	for (int i = n; i > 0; i--) {
		while (fin[i]--)
			st.insert(i);

		if (st.size()) {
			auto it = st.end();
			it--;
			sig[i] = *it;
		}

		for (int x : ini[i])
			st.erase(st.find(x));
	}

	int i = 1, j = inf, rep = 32;

	while (rep--) {
		int m = (i+j)/2;
		if (esPos(m)) j = m;
		else i = m;
	}

	if (esPos(j)) cout << j << endl;
	else cout << -1 << endl;

	return 0;
}