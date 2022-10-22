#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n, m, w;
int wi[Maxn];
int bi[Maxn];
int cur, col[Maxn];
vector <int> neigh[Maxn];
vector <int> seq;
int dp[Maxn];

int Get()
{
	for (int i = 1; i <= n; i++)
		if (!col[i]) return i;
	return 0;
}

void Fill(int v, int c)
{
	col[v] = c; seq.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (!col[u]) Fill(u, c);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &w);
	for (int i = 1; i <= n; i++)
		scanf("%d", &wi[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &bi[i]);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	int ind;
	while ((ind = Get()) != 0) {
		seq.clear(); Fill(ind, ++cur);
		int myw = 0, myb = 0;
		for (int i = 0; i < seq.size(); i++) {
			myw += wi[seq[i]]; myb += bi[seq[i]];
		}
		for (int i = w; i >= 0; i--) {
			if (i + myw <= w) dp[i + myw] = max(dp[i + myw], dp[i] + myb);
			for (int j = 0; j < seq.size(); j++) {
				int v = seq[j];
				if (i + wi[v] <= w) dp[i + wi[v]] = max(dp[i + wi[v]], dp[i] + bi[v]);
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= w; i++)
		res = max(res, dp[i]);
	printf("%d\n", res);
	return 0;
}