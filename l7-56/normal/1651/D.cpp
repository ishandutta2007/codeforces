#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 2e5 + 10;
int n;
pii a[maxn],ans[maxn];
map <pii, int> id;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct node {
	pii st, nw;
};
queue <node> q;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second), id[a[i]] = i, ans[i] = make_pair(-1, -1);
	vector <pii> tmp;
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k < 4; ++k) {
			pii nx = make_pair(a[i].first + dx[k], a[i].second + dy[k]);
			auto it = id.find(nx);
			if (it != id.end()) continue;
			tmp.push_back(nx);
		}
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for (pii p : tmp) q.push((node) {p, p});
	while (!q.empty()) {
		pii nw = q.front().nw, st = q.front().st; q.pop();
		for (int k = 0; k < 4; ++k) {
			pii nx = make_pair(nw.first + dx[k], nw.second + dy[k]);
			auto it = id.find(nx);
			if (it == id.end() || ans[it -> second] != make_pair(-1, -1)) continue;
			ans[it -> second] = st;
			q.push((node) {st, nx});
		}
	}
	for (int i = 1; i <= n; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}