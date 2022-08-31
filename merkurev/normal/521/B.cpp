#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int mod = (int)1e9 + 9;
const int N = (int)2e5;

int add(int a, int b)
{
	return (a + b) % mod;
}

int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}

int n;
int x[N], y[N];
map<pair<int, int>, int> to_ind;
set<int> can_del;

int down_cnt(int cx, int cy)
{
	int cnt = 0;
	for (int dx = -1; dx <= 1; dx++)
	{
		int new_x = cx + dx;
		int new_y = cy - 1;
		if (to_ind.count(make_pair(new_x, new_y)) == 1)
			cnt++;
	}
	return cnt;
}

int down_cnt(int i)
{
	return down_cnt(x[i], y[i]);
}

bool good(int cx, int cy)
{
	bool good = true;
	for (int dx = -1; dx <= 1; dx++)
	{
		int new_x = cx + dx;
		int new_y = cy + 1;
		auto it = to_ind.find(make_pair(new_x, new_y));
		if (it != to_ind.end() && down_cnt(it->second) == 1)
			good = false;
	}
	return good;
}

bool good(int i)
{
	return good(x[i], y[i]);
}

void dump()
{
	printf("can_del\n");
	for (int i : can_del)
		printf("%d ", i);
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		to_ind[make_pair(x[i], y[i])] = i;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (good(i))
		{
			can_del.insert(i);
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		int del_ind = *can_del.begin();
		if (i % 2 == 0)
			del_ind = *can_del.rbegin();


		can_del.erase(del_ind);
		to_ind.erase(make_pair(x[del_ind], y[del_ind]));
		ans.push_back(del_ind);
		
		for (int dx = -2; dx <= 2; dx++)
			for (int dy = -2; dy <= 2; dy++)
			{
				int new_x = x[del_ind] + dx;
				int new_y = y[del_ind] + dy;
				auto it = to_ind.find(make_pair(new_x, new_y));
				if (it != to_ind.end())
				{
					if (good(it->second))
						can_del.insert(it->second);
					else
						can_del.erase(it->second);
				}	
			}
	}
	
	int res = 0;
	reverse(ans.begin(), ans.end());
	int p = 1;
	for (int i : ans)
	{
		res = add(res, mul(i, p));
		p = mul(p, n);
	}

	printf("%d\n", res);

	return 0;
}