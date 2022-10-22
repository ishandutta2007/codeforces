#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
int root;
int my[Maxn];
vector <int> res;

void Traverse(int v)
{
	my[v] = neigh[v].size();
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		Traverse(u); 
		my[v] += my[u];
	}
}

void Solve(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (my[u] % 2 != 0) Solve(u); 
	}
	res.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (my[u] % 2 == 0) Solve(u);
	}
}

int main()
{
	scanf("%d", &n);
	if (n % 2 == 0) { printf("NO\n"); return 0; }
	for (int i = 1; i <= n; i++) {
		int p; scanf("%d", &p);
		if (p == 0) root = i;
		else neigh[p].push_back(i);
	}
	Traverse(root);
	Solve(root);
	printf("YES\n");
	for (int i = 0; i < res.size(); i++)
		printf("%d\n", res[i]);
	return 0;
}