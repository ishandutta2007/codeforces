#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;
const int Maxs = 21;

int n;
vector <int> neigh[Maxn];
int mx[Maxn][Maxs], my[Maxn][Maxs];
ll res;

int Solve1(int v, int p)
{
	int h = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		h = max(h, Solve1(u, v) + 1);
	}
	res += h;
	return h;
}

void Solve(int v, int p)
{
	vector <int> V[Maxs];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v);
		for (int j = 0; j < Maxs; j++) {
			mx[v][j] = max(mx[v][j], mx[u][j]);
			V[j].push_back(my[u][j]);
		}
	}
	my[v][0] = int(neigh[v].size()) - (p != 0);
	for (int j = 0; j + 1 < Maxs; j++) {
		sort(V[j].rbegin(), V[j].rend());
		int l = 0;
		while (l < V[j].size() && V[j][l] >= l + 1) l++;
		my[v][j + 1] = l;
	}
	res += n;
	for (int j = 0; j < Maxs; j++) {
		mx[v][j] = max(mx[v][j], my[v][j]);
		res += max(0, mx[v][j] - 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Solve1(1, 0);
	Solve(1, 0);
	cout << res << endl;
	return 0;
}