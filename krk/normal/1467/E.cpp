#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 21;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int P[Maxn][Maxm], L[Maxn];
map <int, vector <ii> > M;
int BIT[Maxn];
int res;

void Traverse(int v)
{
	lef[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == P[v][0]) continue;
		P[u][0] = v; L[u] = L[v] + 1;
		Traverse(u);
	}
	rig[v] = cur;
}

void Add(int x, int val)
{
	for (int i = x; i <= n; i += i & -i)
		BIT[i] += val;
}

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int getLst(int a, int b)
{
	for (int i = Maxm - 1; i >= 0; i--) if (L[a] - (1 << i) > L[b])
		a = P[a][i];
	return a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	for (int i = 1; i <= n; i++)
		M[a[i]].push_back(ii(lef[i], i));
	for (auto it = M.begin(); it != M.end(); it++) if (it->second.size() >= 2) {
		sort(it->second.begin(), it->second.end());
		vector <ii> seq;
		seq.push_back(it->second[0]);
		for (int j = 1; j < it->second.size(); j++) {
			while (seq.size() >= 2 && rig[seq.back().second] < it->second[j].first) {
				int a = seq.back().second;
				Add(lef[a], 1);
				Add(rig[a] + 1, -1);
				seq.pop_back();
			}
			int a = seq.back().second, b = it->second[j].second;
			if (lef[a] <= lef[b] && lef[b] <= rig[a]) {
				int lst = getLst(b, a);
				Add(1, 1);
				Add(lef[lst], -1);
				Add(rig[lst] + 1, 1);
				Add(lef[b], 1);
				Add(rig[b] + 1, -1);
			} else {
				Add(lef[a], 1);
				Add(rig[a] + 1, -1);
				Add(lef[b], 1);
				Add(rig[b] + 1, -1);
			}
			seq.push_back(it->second[j]);
		}
	}
	for (int i = 1; i <= n; i++)
		res += Get(i) == 0;
	printf("%d\n", res);
    return 0;
}