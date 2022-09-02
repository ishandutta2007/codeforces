#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6;
vector<int> conns[N];
int ins[N];
bool reached[N];
bool ban[N];
vector<int> que;
vector<int> oth;
vector<int> ans;

void dfs1(int i, int d = 1) {
	if (d == 0 && reached[i]) return;
	reached[i] = true;

	for (auto t : conns[i]) {
		if (d == 0) {
			--ins[t];
			if (ins[t] == 0) que.push_back(t);
		} else {
			dfs1(t, d-1);
		}
	}
}

void dfs2(int i) {
	ban[i] = true;
	for (auto t : conns[i]) ban[t] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		++ins[b];
		conns[a].push_back(b);
	}
	for (int i = 0; i < n; ++i) {
		if (ins[i] == 0) que.push_back(i);
		else oth.push_back(i);
	}
	for (int i = 0;; ++i) {
		if (i == que.size()) {
			if (oth.empty()) break;
			que.push_back(oth.back());
			oth.pop_back();
		}
		if (! reached[que[i]]) {
			dfs1(que[i]);
			ans.push_back(que[i]); 
		}
	}

	for (int i = (int)ans.size() - 1; i >= 0; --i) {
		if (ban[ans[i]]) {
			ans[i] = ans.back();
			ans.pop_back();
		} else {
			dfs2(ans[i]);
		}
	}
	cout << ans.size() << '\n';
	for (auto it : ans) cout << (it + 1) << ' '; cout << '\n';
}