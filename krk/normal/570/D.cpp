#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 500005;

int n, m;
vector <int> neigh[Maxn];
char let[Maxn];
int cur, lef[Maxn], rig[Maxn];
vector <int> M[Maxn], I[Maxn];

void Traverse(int v, int lvl)
{
	lef[v] = ++cur;
	I[lvl].push_back(cur);
	if (M[lvl].empty()) M[lvl].push_back(1 << (let[v] - 'a'));
	else M[lvl].push_back(M[lvl].back() ^ (1 << (let[v] - 'a')));
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i], lvl + 1);
	rig[v] = cur;
}

int Bits(int x)
{
	int res = 0;
	while (x) {
		if (x & 1) res++;
		x >>= 1;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	scanf("%s", let + 1);
	Traverse(1, 1);
	while (m--) {
		int v, h; scanf("%d %d", &v, &h);
		int rind = upper_bound(I[h].begin(), I[h].end(), rig[v]) - I[h].begin() - 1;
		int lind = lower_bound(I[h].begin(), I[h].end(), lef[v]) - I[h].begin() - 1;
		int res1 = rind < 0? 0: M[h][rind];
		int res2 = lind < 0? 0: M[h][lind];
		if (Bits(res1 ^ res2) <= 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}