#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 500005;

int n, m;
vector <int> neigh[Maxn];
bool taken[Maxn];
vector <int> cur, forb;
vector <vector <int> > res;

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(neigh[i].begin(), neigh[i].end());
	for (int i = 1; i <= n; i++) if (!taken[i]) {
		cur.clear(); cur.push_back(i); taken[i] = true;
		forb.clear();
		for (int j = 0; j < neigh[i].size(); j++)
			forb.push_back(neigh[i][j]);
		int l = 0;
		for (int j = 1; j <= n; j++) {
			if (l < neigh[i].size() && neigh[i][l] < j) l++;
			if ((l == neigh[i].size() || j < neigh[i][l]) && j != i)
				cur.push_back(j);
		}
		for (int i = 1; i < cur.size(); i++) {
			int v = cur[i]; taken[v] = true;
			vector <int> tmp;
			int l = 0, r = 0;
			while (l < forb.size() && r < neigh[v].size())
				if (forb[l] < neigh[v][r]) cur.push_back(forb[l++]);
				else if (neigh[v][r] < forb[l]) r++;
				else { tmp.push_back(forb[l]); l++; r++; }
			while (l < forb.size()) cur.push_back(forb[l++]);
			forb = tmp;
		}
		res.push_back(cur);
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%d", res[i].size());
		for (int j = 0; j < res[i].size(); j++)
			printf(" %d", res[i][j]);
		printf("\n");
	}
	return 0;
}