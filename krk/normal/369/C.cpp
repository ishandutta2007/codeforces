#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
vector <ii> neigh[Maxn];
vector <int> res;

bool Traverse(int v, int p, int rep)
{
	bool was = false;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (p != u.first) {
			bool got = Traverse(u.first, v, u.second);
			was |= got;
		}
	}
	if (!was && rep) res.push_back(v);
	return was || rep;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, t; scanf("%d %d %d", &a, &b, &t);
		neigh[a].push_back(ii(b, t - 1)); neigh[b].push_back(ii(a, t - 1));
	}
	Traverse(1, 0, 0);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}