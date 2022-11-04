#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, q, a, h;
ll l[1000005];
vvi num, acu;

void dfs (int u) {
	if (u > n)
		return;

	dfs(u*2);
	dfs(u*2+1);

	num[u] = vi(1);

	int i = 0, j = 0;
	while (i < num[u*2].size() || j < num[u*2+1].size())
		if (i < num[u*2].size() && (j == num[u*2+1].size() || num[u*2][i] + l[u*2] < num[2*u+1][j] + l[u*2+1]))
			num[u].push_back(num[u*2][i++] + l[u*2]);
		else
			num[u].push_back(num[u*2+1][j++] + l[u*2+1]);

	acu[u] = vi(num[u].size());
	for (i = 1; i < num[u].size(); i++)
		acu[u][i] = acu[u][i-1] + num[u][i];
}

ll obtRes (int u, ll h) {
	ll res = 0;

	int i = upper_bound(num[u].begin(), num[u].end(), h) - num[u].begin() - 1;
	res = (i + 1) * h - acu[u][i];

	h -= l[u];
	while (u > 1 && h > 0) {
		res += h;
		if ((u ^ 1) <= n && h - l[u^1] > 0) {
			i = upper_bound(num[u^1].begin(), num[u^1].end(), h - l[u^1]) - num[u^1].begin() - 1;
			res += (i + 1) * (h - l[u^1]) - acu[u^1][i];
		}
		u /= 2;
		h -= l[u];
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 2; i <= n; i++)
		cin >> l[i];
	num = acu = vvi(2*n+5);

	dfs(1);
	while (q--) {
		cin >> a >> h;
		cout << obtRes(a, h) << endl;
	}

	return 0;
}