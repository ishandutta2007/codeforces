#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 4005;
const int Maxm = 16384;
const int Maxq = 20005;

int n, p;
iii item[Maxn];
int q;
int qa[Maxq], qb[Maxq];
int L[Maxq], R[Maxq];
vector <int> my[Maxm];
int res[Maxq];
int dp[Maxn][Maxn];

void Add(int v, int l, int r, int a, int b, int ind)
{
	if (l == r) my[v].push_back(ind);
	else {
		int m = l + r >> 1;
		if (a <= m && m + 1 <= b) my[v].push_back(ind);
		else if (a <= m) Add(2 * v, l, m, a, b, ind);
		else Add(2 * v + 1, m + 1, r, a, b, ind);
	}
}

void Solve(int v, int l, int r)
{
	if (l == r)
		for (int i = 0; i < my[v].size(); i++) {
			int ind = my[v][i];
			res[ind] = item[l].second.first <= qb[ind]? item[l].second.second: 0;
		}
	else {
		int m = l + r >> 1;
		if (!my[v].empty()) {
			for (int j = 0; j < item[m].second.first; j++)
				dp[m][j] = 0;
			for (int j = item[m].second.first; j < Maxn; j++)
				dp[m][j] = item[m].second.second;
			for (int i = m - 1; i >= l; i--)
				for (int j = 0; j < Maxn; j++) {
					dp[i][j] = dp[i + 1][j];
					if (j >= item[i].second.first)
						dp[i][j] = max(dp[i][j], dp[i + 1][j - item[i].second.first] + item[i].second.second);
				}
			for (int j = 0; j < item[m + 1].second.first; j++)
				dp[m + 1][j] = 0;
			for (int j = item[m + 1].second.first; j < Maxn; j++)
				dp[m + 1][j] = item[m + 1].second.second;
			for (int i = m + 2; i <= r; i++)
				for (int j = 0; j < Maxn; j++) {
					dp[i][j] = dp[i - 1][j];
					if (j >= item[i].second.first)
						dp[i][j] = max(dp[i][j], dp[i - 1][j - item[i].second.first] + item[i].second.second);
				}
			for (int i = 0; i < my[v].size(); i++) {
				int ind = my[v][i];
				for (int a = 0; a <= qb[ind]; a++)
					res[ind] = max(res[ind], dp[L[ind]][a] + dp[R[ind]][qb[ind] - a]);
			}
		}
		Solve(2 * v, l, m);
		Solve(2 * v + 1, m + 1, r);
	}
}

int main()
{
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &item[i].second.first, &item[i].second.second, &item[i].first);
	sort(item, item + n);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &qa[i], &qb[i]);
		int lef = lower_bound(item, item + n, iii(qa[i] - p + 1, ii(0, 0))) - item;
		int rig = lower_bound(item, item + n, iii(qa[i] + 1, ii(0, 0))) - item;
		if (lef < rig) {
			Add(1, 0, n - 1, lef, rig - 1, i);
			L[i] = lef;
			R[i] = rig - 1;
		}
	}
	Solve(1, 0, n - 1);
	for (int i = 0; i < q; i++)
		printf("%d\n", res[i]);
    return 0;
}