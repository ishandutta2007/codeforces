#include <cstdio>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
bool vis[Maxn];
int to[Maxn];

void Go(int v)
{
	if (vis[v]) return;
	vis[v] = true;
	int u = (v + n / 2) % n;
	if (vis[u]) {
		to[v] = to[u] == 2 * v % n? (2 * v + 1) % n: 2 * v % n;
		Go(to[v]);
	} else {
		to[v] = 2 * v % n; Go(to[v]);
		if (!vis[u]) {
			to[v] = (2 * v + 1) % n; Go(to[v]); 
		}
	}
}

int main()
{
	scanf("%d", &n);
	if (n % 2) { printf("-1\n"); return 0; }
	Go(0);
	int v = 0;
	do {
		printf("%d ", v);
		v = to[v];
	} while (v);
	printf("0\n");
	return 0;
}