#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int N = 1050;
const int INF = (int)2e9;

int n;
int a[N], b[N];

int solve(int h)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int cur_add = INF;
		if (a[i] <= h)
			cur_add = min(cur_add, b[i]);
		if (b[i] <= h)
			cur_add = min(cur_add, a[i]);
		if (cur_add == INF)
			return -1;
		sum += cur_add;
	}
	return h * sum;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);

	vector<int> list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(a[i]);
		list.push_back(b[i]);
	}

	sort(list.begin(), list.end());
	list.erase(unique(list.begin(), list.end()), list.end());

	int ans = INF;

	for (int h : list)
	{
		int cur_ans = solve(h);
		if (cur_ans != -1)
			ans = min(ans, cur_ans);
	}

	printf("%d", ans);

	return 0;
}