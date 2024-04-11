#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int n, m, k;
set<pair<int, int> > used;
map<int, vector<int> > graph;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &m, &k);
	vector<int> list;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		used.insert(make_pair(a, b));
		used.insert(make_pair(b, a));
		graph[a].push_back(b);
		graph[b].push_back(a);
		list.push_back(a);
		list.push_back(b);
	}

	sort(list.begin(), list.end());
	list.erase(unique(list.begin(), list.end()), list.end());

	for (int id : list)
	{
		vector<int> ans;
		for (int y : list)
		{
			if (y == id || used.count(make_pair(id, y)) == 1)
				continue;
			int cnt = 0;
			for (int to : graph[y])
				if (used.count(make_pair(id, to)))
					cnt++;
			if (cnt * 100 >= k * (int)graph[id].size())
				ans.push_back(y);
		}

		printf("%d: %d", id, (int)ans.size());
		for (int y : ans)
			printf(" %d", y);
		printf("\n");
	}


	return 0;
}