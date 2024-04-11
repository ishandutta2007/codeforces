#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MAXN = 410000;
int was[MAXN];
vector<pair<int, int>> eds[MAXN];

vector<int> ans;
int n, m;
int d[MAXN];

int dfs1(int v) {
	was[v] = 1;
	int cur = d[v];
	for (auto e: eds[v]) {
		int u = e.first;
		if (was[u])
			continue;
		if (dfs1(u))
			ans.push_back(e.second), cur ^= 1;
	}
	if (d[v] == -1)
		return 0;
	return cur;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", d + i);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(make_pair(b, i));
		eds[b].push_back(make_pair(a, i));
	}
	int st = -1;
	int sm = 0;
	for (int i = 0; i < n; ++i) {
		if (d[i] == -1) {
			st = i;
		}
		else {
			sm ^= d[i];
		}
	}
	if (st == -1 && sm == 1) {
		cout << -1 << "\n";
		return 0;
	}
	if (st == -1)
		st = 0;
	dfs1(st);
	printf("%d\n", (int)ans.size());
	for (int i: ans)
		printf("%d ", i + 1);
	printf("\n");
    return 0;
}