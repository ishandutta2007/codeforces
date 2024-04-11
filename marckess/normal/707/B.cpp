#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m, k, u[100005], v[100005], w[100005], a;
	bitset<100005> bs;

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
		cin >> u[i] >> v[i] >> w[i];

	while (k--) {
		cin >> a;
		bs[a] = 1;
	}

	int res = 2e9;
	for (int i = 0; i < m; i++) {
		if (bs[u[i]] ^ bs[v[i]] == 1) {
			res = min(res, w[i]);
		}
	}

	if (res == 2e9)
		res = -1;

	cout << res << endl;

	return 0;
}