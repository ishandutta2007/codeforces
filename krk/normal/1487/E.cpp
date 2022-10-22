#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxd = 4;

int n[Maxd];
int a[Maxd][Maxn];
int m[Maxd];
set <ii> S[Maxd];
vector <ii> best[Maxd];

int main()
{
	for (int i = 0; i < Maxd; i++)
		scanf("%d", &n[i]);
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < n[i]; j++)
			scanf("%d", &a[i][j]);
	for (int j = 0; j < n[0]; j++)
		best[0].push_back(ii(a[0][j], j));
	sort(best[0].begin(), best[0].end());
	for (int i = 1; i < Maxd; i++) {
		scanf("%d", &m[i]);
		for (int j = 0; j < m[i]; j++) {
			int u, v; scanf("%d %d", &u, &v); u--; v--;
			S[i].insert(ii(u, v));
		}
		for (int j = 0; j < n[i]; j++) {
			int pnt = 0;
			while (pnt < best[i - 1].size() && S[i].find(ii(best[i - 1][pnt].second, j)) != S[i].end())
				pnt++;
			if (pnt < best[i - 1].size())
				best[i].push_back(ii(best[i - 1][pnt].first + a[i][j], j));
		}
		sort(best[i].begin(), best[i].end());
	}
	printf("%d\n", best[Maxd - 1].empty()? -1: best[Maxd - 1][0].first);
    return 0;
}