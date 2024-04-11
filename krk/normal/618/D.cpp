#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int n, x, y;
vector <int> neigh[Maxn];
int res;

ii Get(int v, int p = 0)
{
	ii my = ii(1, 0);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u != p) {
			ii oth = Get(u, v);
			my.first += oth.second; my.second += oth.first;
		}
	}
	return my;
}

int Traverse(int v, int p = 0)
{
	int cur = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		cur += Traverse(u, v);
	}
	if (cur <= 1) return 1;
	res += 1 + (cur - 2);
	return 0;
}

int main()
{
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	if (y <= x) {
		ii g = Get(1);
		if (g.first >= 2 && g.second >= 2)
			printf("%I64d\n", ll(y) * (n - 1));
		else printf("%I64d\n", ll(y) * (n - 2) + x);
	}
	else {
		if (Traverse(1)) res++;
		printf("%I64d\n", ll(res - 1) * y + ll(n - res) * x);
	}
	return 0;
}