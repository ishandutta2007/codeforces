#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
vector<int> conns[N];
vector<int> inv[N];
int group[N];
int group_size[N];
bool reach[N][2];	// can you get from s to node i with j moves (mod 2)

vector<int> solve;
// can you win?
int dfs(int i, int d) {
	if (reach[i][d & 1] == true) return -1;
	reach[i][d & 1] = true;
	if (conns[i].size() == 0) {
		if (d & 1) {
			solve.push_back(i+1);
			return 1;
		}
		return -1;
	} else {
		int res = -1;
		if (group_size[group[i]] > 1) res = 0;
		for (auto t : conns[i]) {
			int sub = dfs(t, d+1);
			if (sub == 1) {
				solve.push_back(i+1);
				return 1;
			}
			res = max(sub, res);
		}
		return res;
	}
}

vector<int> help;
void dico1(int i) {
	if (group[i] == -1) return;
	group[i] = -1;
	for (auto t : conns[i]) {
		dico1(t);
	}
	help.push_back(i);
}
void dico2(int i, int g) {
	if (group[i] != -1) return;
	group[i] = g;
	++group_size[g];
	for (auto t : inv[i]) {
		dico2(t, g);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		for (int j = 0; j < c; ++j) {
			int t;
			cin >> t;
			--t;
			conns[i].push_back(t);
			inv[t].push_back(i);
			// cout << "edge " << i << ' ' << t << '\n';
		}
	}
	

	int s;
	cin >> s;
	--s;
	
	for (int i = 0; i < n; ++i) {
		if (group[i] != -1) dico1(i);
	}
	int groups = 0;
	while(! help.empty()) {
		int i = help.back();
		help.pop_back();
		if (group[i] == -1) {
			dico2(i, groups);
			++groups;
		}
	}
	// for (int i = 0; i < n; ++i) cout << group[i] << ' '; cout << '\n';

	int res = dfs(s, 0);
	if (res == 1) {
		cout << "Win\n";
		for (int i = solve.size() - 1; i >= 0; --i) cout << solve[i] << ' ';
		cout << '\n';
	} else if (res == 0) {
		cout << "Draw\n";
	} else {
		cout << "Lose\n";
	}
}