#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int T;
int n;
vector <int> neigh1[Maxn], neigh2[Maxn];
int cur, lef[Maxn], rig[Maxn];
set <ii> S;
ii ret[Maxn];
bool add[Maxn];
int res;

void Traverse(int v)
{
	lef[v] = ++cur;
	for (int i = 0; i < neigh2[v].size(); i++)
		Traverse(neigh2[v][i]);
	rig[v] = cur;
}

void Solve(int v)
{
	ret[v] = ii(-1, -1);
	auto it = S.lower_bound(ii(lef[v], 0));
	if (it != S.end())
		if (it->first <= rig[v]) add[v] = false;
		else add[v] = true;
	else add[v] = true;
	if (add[v]) {
		if (it != S.begin()) {
			it--;
			if (lef[v] <= it->second) {
				ret[v] = *it;
				S.erase(it);
			}
		}
		S.insert(ii(lef[v], rig[v]));
	}
	res = max(res, int(S.size()));
	for (int i = 0; i < neigh1[v].size(); i++)
		Solve(neigh1[v][i]);
	if (add[v]) S.erase(ii(lef[v], rig[v]));
	if (ret[v] != ii(-1, -1))
		S.insert(ret[v]);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			neigh1[i].clear();
			neigh2[i].clear();
		}
		cur = 0;
		for (int i = 2; i <= n; i++) {
			int p; scanf("%d", &p);
			neigh1[p].push_back(i);
		}
		for (int i = 2; i <= n; i++) {
			int p; scanf("%d", &p);
			neigh2[p].push_back(i);
		}
		Traverse(1);
		S.clear();
		res = 0;
		Solve(1);
		printf("%d\n", res);
	}
    return 0;
}