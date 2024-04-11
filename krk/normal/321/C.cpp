#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

int n;
vector <int> neigh[Maxn];
int has[Maxn][Maxl];
char res[Maxn];

void Fill(int v, int p)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Fill(u, v);
		for (int j = 0; j < Maxl; j++)
			has[v][j] += has[u][j];
	}
	int i = 0;
	while (i + 1 < Maxl && has[v][i + 1] < 2) i++;
	while (has[v][i]) i--;
	has[v][i]++; res[v] = 'A' + i;
	for (i++; i < Maxl; i++) has[v][i] = false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	Fill(1, 0);
	for (int i = 1; i <= n; i++)
		printf("%c%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}