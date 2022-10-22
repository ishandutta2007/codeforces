#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int res;

int Traverse(int v, int p = 0)
{
	int cnt = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (Traverse(u, v) == 0) res++;
		else cnt++; 
	}
	cnt %= 2;
	return cnt;
}

int main()
{
	scanf("%d", &n);
	if (n % 2) { printf("-1\n"); return 0; }
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	printf("%d\n", res);
	return 0;
}