#include <iostream>
#include <vector>
using namespace std;

const int N = 10 + 2 * (int)1e5;
const int M = 10 + 2 * (int)1e5;
vector<int> conns[N];
int bip[N];

int es[M];
int et[M];

bool dfs(int i) {
	for (auto t : conns[i]) {
		if (bip[t] == 0) {
			bip[t] = -bip[i];
			if (! dfs(t)) return false;
		} else {
			if (bip[t] == bip[i]) return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		cin >> es[j] >> et[j];
		--es[j]; --et[j];
		conns[es[j]].push_back(et[j]);
		conns[et[j]].push_back(es[j]);
	}
	bip[0] = 1;
	bool fail = !dfs(0);
	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int j = 0; j < m; ++j) {
			if (bip[es[j]] == -1) cout << "0";
			else cout << "1";
		}
		cout << '\n';
	}
}