#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int Maxn = 100005;

int n, m;
vector <vector <int> > B;
map <int, vector <int> > M[Maxn];
map <int, vector <int> >::iterator it[Maxn];
int seen[Maxn];
int ready[Maxn];
vector <int> res;

void giveReady(int c) { if (++ready[c] == n) res.push_back(c); }

void delCol(int r, int c)
{
	if (B[r][c] == -1) return;
	if (++seen[r] == it[r]->second.size()) {
		it[r]++; seen[r] = 0;
		if (it[r] != M[r].end())
			for (int i = 0; i < it[r]->second.size(); i++)
				giveReady(it[r]->second[i]);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	B.assign(n + 1, vector <int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &B[i][j]);
			if (B[i][j] == -1) giveReady(j);
			else M[i][B[i][j]].push_back(j);
		}
		it[i] = M[i].begin();
		if (it[i] != M[i].end())
			for (int j = 0; j < it[i]->second.size(); j++)
				giveReady(it[i]->second[j]);
	}
	for (int i = 0; i < res.size(); i++)
		for (int j = 1; j <= n; j++)
			delCol(j, res[i]);
	if (res.size() < m) printf("-1\n");
	else for (int i = 0; i < m; i++)
			printf("%d%c", res[i], i + 1 < m? ' ': '\n');
	return 0;
}