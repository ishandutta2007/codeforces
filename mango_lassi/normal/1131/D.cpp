#include <iostream>
#include <vector>
using namespace std;

const int N = 2000;
string dat[N];
int comp[N];
int ord[N];
int res[N];

vector<int> dirs[N];
bool visited[N];

int coll(int i) {
	if (comp[i] != i) comp[i] = coll(comp[i]);
	return comp[i];
}
void join(int a, int b) {
	a = coll(a);
	b = coll(b);
	comp[b] = a;
}


void dfs(int i, vector<int>& topo) {
	if (visited[i]) return;
	visited[i] = true;
	for (auto t : dirs[i]) dfs(t, topo);
	topo.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+m; ++i) comp[i] = i;
	
	for (int y = 0; y < n; ++y) {
		cin >> dat[y];
		for (int x = 0; x < m; ++x) {
			if (dat[y][x] == '=') {
				join(x+n, y);
			}
		}
	}
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (dat[y][x] == '>') {
				dirs[coll(x + n)].push_back(coll(y));
			} else if (dat[y][x] == '<') {
				dirs[coll(y)].push_back(coll(x + n));
			}
		}
	}

	vector<int> topo;
	for (int i = 0; i < n+m; ++i) {
		dfs(coll(i), topo);
	}
	for (int j = 0; j < topo.size(); ++j) ord[topo[j]] = j;

	bool fail = false;
	for (int j = (int)topo.size() - 1; j >= 0; --j) {
		int i = topo[j];
		for (auto t : dirs[i]) {
			res[t] = max(res[t], res[i] + 1);
			if (ord[t] >= j) fail = true;
		}
	}
	if (fail) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		for (int i = 0; i < n; ++i) {
			cout << res[coll(i)]+1 << ' ';
		}
		cout << '\n';
		for (int i = 0; i < m; ++i) {
			cout << res[coll(i+n)]+1 << ' ';
		}
		cout << '\n';
	}
}