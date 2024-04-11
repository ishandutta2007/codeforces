#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 3005;
int n, k, w[MX];
ll mem[20][MX], res, v[MX];
vi a[MX], pre[MX];

void dp (int lvl, int l, int r) {
	if (l == r) {
		for (int i = 0; i <= w[l]; i++)
			res = max(res, mem[lvl - 1][k - i] + pre[l][i]);
		return;
	}
	
	int m = (l + r) / 2;
	
	forn (i, k) mem[lvl][i + 1] = mem[lvl - 1][i + 1];
	for (int i = l; i <= m; i++)
		for (int j = k; j >= w[i]; j--)
			mem[lvl][j] = max(mem[lvl][j], mem[lvl][j - w[i]] + v[i]);
	dp(lvl + 1, m + 1, r);
	
	forn (i, k) mem[lvl][i + 1] = mem[lvl - 1][i + 1];
	for (int i = m + 1; i <= r; i++)
		for (int j = k; j >= w[i]; j--)
			mem[lvl][j] = max(mem[lvl][j], mem[lvl][j - w[i]] + v[i]);
	dp(lvl + 1, l, m);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	forn (i, n) {
		int t;
		cin >> t;
		
		a[i].resize(t);
		forn (j, t)
			cin >> a[i][j];
		
		while (a[i].size() > k)
			a[i].pop_back();
		w[i] = a[i].size();
		
		pre[i] = {0};
		forn (j, w[i])
			pre[i].pb(pre[i].back() + a[i][j]);
		v[i] = pre[i].back();
	}
	
	forn (i, k) mem[0][i + 1] = -1e18;
	dp(1, 0, n - 1);
	
	cout << res << endl;
	
	return 0;
}