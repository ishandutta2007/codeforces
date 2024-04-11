#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


int readTime()
{
	int h, m, s;
	scanf("%d:%d:%d", &h, &m, &s);
	return s + 60 * (m + 60 * h);
}


set <pair <int, int> > open;
vector <int> ans;
int cnt = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	bool win = false;
	
	for (int i = 0; i < n; i++)
	{
		int curt = readTime();
		while (!open.empty() && open.begin()->first < curt)
		{
			open.erase(open.begin() );
		}
		int id;
		if ( (int) open.size() == m)
		{
			id = open.rbegin()->second;
			open.erase(*open.rbegin() );
		}
		else
			id = ++cnt;
		ans.push_back(id);
		open.insert(make_pair(curt + t - 1, id) );
		if ( (int) open.size() == m)
			win = true;
	}
	if (!win)
	{
		printf("No solution\n");
		return 0;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i] );


	return 0;
}