#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, k, p;
vector <int> neigh[Maxn];
int lvl[Maxn];
int seq[Maxn], slen;
int res;

int main()
{
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	fill(lvl + 1, lvl + n + 1, Maxn); lvl[1] = 0;
	seq[slen++] = 1;
	for (int i = 0; i < slen; i++) {
		int v = seq[i];
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			if (lvl[v] + 1 < lvl[u]) { lvl[u] = lvl[v] + 1; seq[slen++] = u; }
		}
	}
	int l = 1, r = 1;
	int cost = 0;
	while (r < slen) {
		cost += r - l;
		int tlvl = lvl[seq[r]];
		while (r < slen && tlvl == lvl[seq[r]]) r++;
		while (r - l > k || cost > p) {
			cost -= tlvl - lvl[seq[l]]; l++;
		}
		res = max(res, r - l);
	}
	printf("%d\n", res);
	return 0;
}