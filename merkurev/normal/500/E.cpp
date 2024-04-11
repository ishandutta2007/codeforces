#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


bool cmp(const pair <int, int> &a, const pair <int, int> &b)
{
	return a > b;
}

const int maxn = 2e5 + 100;
int pos[maxn];
int len[maxn];
int ans[maxn];
vector <pair <int, int> > q[maxn];
vector <pair <int, int> > st;
vector <int> cost;
const int inf = (int) 2e9 + 100;

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &pos[i], &len[i] );
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		q[a].push_back(make_pair(b, i) );
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int r = pos[i] + len[i];
		while (!st.empty() && r >= pos[st.back().first] )
		{
			r = max(r, st.back().second);
			st.pop_back();
			cost.pop_back();
		}
		if (st.empty() )
			cost.push_back(0);
		else
		{
			int lc = cost.back();
			cost.push_back(pos[st.back().first] - r + lc);
		}
		st.push_back(make_pair(i, r) );



		for (int j = 0; j < (int) q[i].size(); j++)
		{
			int id = q[i][j].second;
			int x = q[i][j].first;
			int pid = lower_bound(st.begin(), st.end(), make_pair(x, inf), cmp) - st.begin();
			ans[id] = cost.back() - cost[pid];
		}
	}

	for (int i = 0; i < k; i++)
		printf("%d\n", ans[i] );

	return 0;
}