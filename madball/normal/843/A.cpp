#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <cstring>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = (int)1e5 + 10;

pair<int, int> ar1[MAXN];
int ar[MAXN];
bool been[MAXN];
vector<vector<int> > ans;

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &ar1[i].first);
		ar1[i].second = i;
	}
	sort(ar1, ar1 + n);
	for (int i = 0; i < n; ++i)
		ar[i] = ar1[i].second;

	for (int i = 0; i < n; ++i)
	{
		if (been[i])
			continue;
		ans.push_back(vector<int>());
		int cur = i;
		do
		{
			been[cur] = true;
			ans.back().push_back(cur);
			cur = ar[cur];
		} while (cur != i);
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i)
	{
		printf("%d", (int)ans[i].size());
		for (int j = 0; j < (int)ans[i].size(); ++j)
			printf(" %d", ans[i][j] + 1);
		printf("\n");
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	printf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}