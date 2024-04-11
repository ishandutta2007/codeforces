#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
int B[2][Maxn];
vector <ii> my[Maxn];
vector <ii> neigh[Maxn];
int tk[Maxn];
vector <int> pos, neg;
vector <int> res;

bool Traverse(int v, int c)
{
	if (tk[v]) return tk[v] == c;
	tk[v] = c;
	if (c > 0) pos.push_back(v);
	else neg.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		int nc = neigh[v][i].second == 0? c: -c;
		if (!Traverse(neigh[v][i].first, nc))
			return false;
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			my[i].clear();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &B[i][j]);
				my[B[i][j]].push_back(ii(i, j));
			}
		bool fall = false;
		for (int i = 1; i <= n; i++)
			if (my[i].size() != 2) fall = true;
		if (fall) { printf("-1\n"); continue; }
		for (int j = 0; j < n; j++) {
			neigh[j].clear();
			tk[j] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int a = my[i][0].second, b = my[i][1].second;
			int c = my[i][0].first == my[i][1].first;
			neigh[a].push_back(ii(b, c));
			neigh[b].push_back(ii(a, c));
		}
		res.clear();
		for (int i = 0; i < n; i++) if (!tk[i]) {
			neg.clear();
			pos.clear();
			if (!Traverse(i, 1)) { fall = true; break; }
			if (pos.size() > neg.size()) swap(pos, neg);
			for (int j = 0; j < pos.size(); j++)
				res.push_back(pos[j]);
		}
		if (fall) { printf("-1\n"); continue; }
		printf("%d\n", int(res.size()));
		if (res.empty()) printf("\n");
		else for (int i = 0; i < res.size(); i++)
				printf("%d%c", res[i] + 1, i + 1 < res.size()? ' ': '\n');
	}
    return 0;
}