#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Maxm = 200005;

int n, m, q;
int dist[Maxn][Maxn];
int a[Maxm], b[Maxm];
int l[Maxm], r[Maxm], s[Maxm], t[Maxm];
vector <int> has[Maxm];
bool res[Maxm];

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = (i != j) * Maxm;
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &a[i], &b[i]);
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d %d", &l[i], &r[i], &s[i], &t[i]);
		has[l[i]].push_back(i);
	}
	for (int i = m; i >= 1; i--) {
		dist[b[i]][a[i]] = i; dist[a[i]][b[i]] = i;
		for (int j = 1; j <= n; j++) if (j != a[i] && j != b[i])
			if (dist[a[i]][j] < dist[b[i]][j]) dist[b[i]][j] = dist[a[i]][j];
			else dist[a[i]][j] = dist[b[i]][j];
		for (int j = 0; j < has[i].size(); j++) {
			int ind = has[i][j];
			res[ind] = dist[s[ind]][t[ind]] <= r[ind];
		}
	}
	for (int i = 0; i < q; i++)
		printf("%s\n", res[i]? "Yes": "No");
	return 0;
}