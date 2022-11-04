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

int n, m, mk[25], adj[25], a, b, mn = 30, res;
bitset<((1<<23)+2)> esCon;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 0, j = 1; i <= 23; i++, j *= 2) {
		mk[i] = j;
		adj[i] = j;
		esCon[j] = 1;
	}

	cin >> n >> m;
	
	if (n * (n - 1) / 2 == m) {
		cout << 0 << endl;
		return 0;
	}

	while (m--) {
		cin >> a >> b;
		a--, b--;

		adj[a] |= mk[b];
		adj[b] |= mk[a];
	}

	for (int i = 1; i < mk[n+1]; i++) {
		if (!esCon[i])
			continue;

		int x = 0, amk = 0;

		for (int j = 0; j < n; j++) {
			if (mk[j] & i) {
				amk |= adj[j];
				x++;
			}
		}

		for (int j = 0; j < n; j++) {
			if (amk & mk[j]) {
				esCon[i|mk[j]] = 1;
			}
		}

		if (amk == mk[n] - 1) {
			if (x < mn) {
				mn = x;
				res = i;
			}
		}
	}

	cout << mn << endl;
	for (int i = 0; i < n; i++)
		if (res & mk[i])
			cout << i + 1 << " ";
	cout << endl;

	return 0;
}