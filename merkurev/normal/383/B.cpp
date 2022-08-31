#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int INF = (int)1e9 + 10000;

int n, m;
map<int, vector<int> > pos;
set<pair<int, int> > segs;

void fail()
{
	printf("-1\n");
	exit(0);
}

void print(set<pair<int, int> > s)
{
	printf("------\n");
	for (auto p : s)
		printf("%d %d\n", p.first, p.second);
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	scanf("%d%d", &n, &m);
	vector<int> x_list;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x_list.push_back(x);
		pos[x].push_back(y);
	}

	sort(x_list.begin(), x_list.end());
	x_list.erase(unique(x_list.begin(), x_list.end()), x_list.end());

	for (auto x : x_list)
	{
		pos[x].push_back(0);
		pos[x].push_back(n + 1);
		sort(pos[x].begin(), pos[x].end());
	}

	segs.insert({1, 1});
	int last_x = 0;
	
	for (auto x : x_list)
	{
		if (segs.empty())
			fail();

		if (x - last_x > 1)
		{
			int l = (*segs.begin()).first;
			segs.clear();
			segs.insert({l, n});
		}
		last_x = x;

		//printf("x = %d\n", x);
		//print(segs);
		
		set<pair<int, int> > new_segs;
		auto gaps = pos[x];
		for (int i = 1; i < (int)gaps.size(); i++)
		{
			int l = gaps[i - 1] + 1;
			int r = gaps[i] - 1;
			
			if (l > r)
				continue;
			
			pair<int, int> s = {l, r};
			int best_l = INF;

			auto it = segs.lower_bound(s);
			if (it != segs.end())
			{
				int a = it->first;
				int b = it->second;
				if (b >= l)
					best_l = min(best_l, max(l, a));
			}

			if (it != segs.begin())
			{
				it--;
				int a = it->first;
				int b = it->second;
				if (b >= l)
					best_l = min(best_l, max(l, a));
			}
			
			if (best_l <= r)
				new_segs.insert({best_l, r});
		}

		segs = new_segs;
	}

	int last = 0;
	if (pos.count(n))
	{
		pos[n].pop_back();
		last = pos[n].back();
	}

	bool good = false;
	for (auto s : segs)
		if (s.first > last)
			good = true;

	if (good)
		printf("%d\n", 2 * (n - 1));
	else	
		fail();

	return 0;
}