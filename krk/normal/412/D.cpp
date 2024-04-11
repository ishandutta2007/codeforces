#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 30005;

int n, m;
vector <int> neigh[Maxn];
bool taken[Maxn];
int seq[Maxn], pnt;

void Traverse(int v)
{
	if (taken[v]) return;
	taken[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i]);
	seq[pnt--] = v;
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[b].push_back(a);
	}
	pnt = n - 1;
	for (int i = 1; i <= n; i++) if (!taken[i])
		Traverse(i);
	for (int i = 0; i < n; i++)
		printf("%d%c", seq[i], i + 1 < n? ' ': '\n');
	return 0;
}