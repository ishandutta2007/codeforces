#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 123 * 123 + 1;

vector <vector <int>> G(maxn);
vector <int> ans, find_start(maxn);

void dfs(int v) {
	while (!G[v].empty()) {
		int u = G[v].back();
		G[v].pop_back();
		dfs(u);
	}
	ans.push_back(v % 123);
}

bool find_ans() {
	int sum = 0, v_check = 0;
	for (int i = 0; i < maxn; i++)
		if (find_start[i] > 0) {
			sum++;
			v_check = i;
		}
	if (sum > 1 || find_start[v_check] > 1)
		return false;
	int v_start = -1;
	for (int i = 0; i < maxn; i++) {
		if (find_start[i] > 0) {
			v_start = i;
			break;
		}
		if (G[i].size() != 0 && v_start == -1)
			v_start = i;
	}
	dfs(v_start);
	ans.push_back(v_start / 123);
	reverse(ans.begin(), ans.end());
	return true;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		int v = a * 123 + b, u = b * 123 + c;
		G[v].push_back(u);
		find_start[v]++, find_start[u]--;
	}
	if (!find_ans() || ans.size() != n + 2) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (auto i : ans)
		cout << (char)i;
	cout << '\n';
	return 0;
}