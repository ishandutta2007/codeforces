#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
int res;

int Get(int v, int p)
{
	vector <int> seq;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		seq.push_back(Get(u, v) + 1);
	}
	if (seq.empty()) return 0;
	sort(seq.rbegin(), seq.rend());
	for (int i = 0; i + 1 < seq.size(); i++)
		res = max(res, seq[i] + 1);
	return seq.back();
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			neigh[i].clear();
		res = 0;
		for (int i = 0; i < n - 1; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].push_back(b);
			neigh[b].push_back(a);
		}
		vector <int> seq;
		for (int i = 0; i < neigh[1].size(); i++)
			seq.push_back(Get(neigh[1][i], 1) + 1);
		sort(seq.begin(), seq.end());
		for (int i = 0; i + 1 < seq.size(); i++)
			res = max(res, seq[i] + 1);
		res = max(res, seq.back());
		printf("%d\n", res);
	}
    return 0;
}