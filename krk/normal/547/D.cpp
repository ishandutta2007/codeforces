#include <cstdio>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxm = 200000;
const int Maxn = 400005;

int n;
set <ii> neigh[Maxn];
char res[Maxn];

void Solve(int v, bool cur)
{
	if (neigh[v].size()) {
		ii u = *neigh[v].begin(); 
		neigh[v].erase(u); neigh[u.first].erase(ii(v, u.second));
		res[u.second] = cur? 'r': 'b'; cur = !cur;
		Solve(u.first, cur);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y); y += Maxm;
		neigh[x].insert(ii(y, i));
		neigh[y].insert(ii(x, i));
	}
	for (int i = 0; i < Maxn; i++)
		if (neigh[i].size() % 2) Solve(i, false);
	for (int i = 0; i < Maxn; i++)
		while (neigh[i].size()) Solve(i, false);
	for (int i = 0; i < n; i++)
		printf("%c", res[i]);
	printf("\n");
	return 0;
}