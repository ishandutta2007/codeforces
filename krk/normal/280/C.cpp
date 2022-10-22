#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
ld res;

void Traverse(int v, int p, int d)
{
	res += 1.0l / ld(d);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v, d + 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	Traverse(1, 0, 1);
	printf("%.10lf\n", double(res));
	return 0;
}