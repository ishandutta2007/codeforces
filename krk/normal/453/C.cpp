#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
bool taken[Maxn];
int par[Maxn];
int root;
vector <int> res;

void Visit(int v)
{
	par[v] = 1 - par[v];
	res.push_back(v);
}

void Traverse(int v)
{
	taken[v] = true;
	Visit(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (!taken[u]) {
			Traverse(u); Visit(v);
			if (par[u] == 1) { Visit(u); Visit(v); }
		}
	}
	if (v == root && par[root] == 1) { par[root] = 0; res.pop_back(); }
}

bool Check()
{
	for (int i = 1; i <= n; i++)
		if (par[i]) return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &par[i]);
	root = 1;
	while (root <= n && !par[root]) root++;
	Traverse(root);
	if (Check()) {
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); i++)
			printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	} else printf("-1\n");
	return 0;
}