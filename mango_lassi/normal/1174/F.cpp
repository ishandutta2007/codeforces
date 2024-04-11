#include <iostream>
#include <vector>
using namespace std;

const int N = 2 * (int)1e5;
vector<int> conns[N];
int siz[N];
int dep[N];
int par[N];
bool active[N];

int distance(int u) {
	cout << "d " << u+1 << endl;
	int res;
	cin >> res;
	if (res == -1) exit(0);
	return res;
}
int pathNext(int u) {
	cout << "s " << u+1 << endl;
	int res;
	cin >> res;
	if (res == -1) exit(0);
	--res;
	return res;
}
void answer(int u) {
	cout << "! " << u+1 << endl;
}

int dfs(int i, int h, int p = -1) {
	siz[i] = 1;
	dep[i] = (p == -1 ? 0 : dep[p] + 1);
	par[i] = p;

	int res = -1;
	for (auto t : conns[i]) {
		if (t == p || ! active[t]) continue;
		int sub = dfs(t, h, i);
		if (sub != -1) res = sub;
		siz[i] += siz[t];
	}

	if (res == -1 && siz[i] >= h) res = i;
	return res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) active[i] = true;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	// Every step at least splits size of possible search space
	int c = 0;
	int cur_dist = distance(c);
	int cur_siz = n;
	while(cur_dist > 0) {
		dep[c] = -1;
		int t = dfs(c, (cur_siz+1)/2, c);

		if (t != c) {
			int nxt_dist = distance(t);
			if (nxt_dist + dep[t] == cur_dist) {
				c = t;
				cur_dist = nxt_dist;
				cur_siz = siz[t];
			} else {
				active[t] = false;
				cur_siz -= siz[t];
			}
		} else {
			c = pathNext(c);
			cur_siz = siz[c];
			--cur_dist;
		}
		active[par[c]] = false;
	}
	answer(c);
}