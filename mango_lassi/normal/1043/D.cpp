#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = (int)1e5;
int nxt[N];
int len[N];

int dfs(int i) {
	if (len[i] != -1) return len[i];
	if (nxt[i] == -1) len[i] = 1;
	else len[i] = 1 + dfs(nxt[i]);
	return len[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) nxt[i] = -1;
	for (int i = 0; i < n; ++i) len[i] = -1;
	for (int j = 0; j < m; ++j) {
		int p;
		cin >> p;
		--p;
		for (int i = 1; i < n; ++i) {
			int a;
			cin >> a;
			--a;
			if (j == 0) nxt[p] = a;
			else if (nxt[p] != a) nxt[p] = -1;
			p = a;
		}
		nxt[p] = -1;
	}

	ll res = 0;
	for (int i = 0; i < n; ++i) res += dfs(i);
	cout << res << '\n';
}