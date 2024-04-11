#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
using namespace std;

typedef long long int int64;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int N = 1e6;

int n, q;
vector<int> comp[N];
int color[N];
set<int> bad_pos;

void check(int x)
{
	if (x < 0)
		return;
	if (x >= n - 1)
		return;

	if (color[x] == color[x + 1])
		bad_pos.erase(x);
	else
		bad_pos.insert(x);
}

bool same(int a, int b)
{
	return color[a] == color[b];
}

void join(int a, int b)
{
	if (same(a, b))
		return;

	int pc = color[b];
	int nc = color[a];

	if (comp[nc].size() < comp[pc].size())
	{
		swap(a, b);
		swap(nc, pc);
	}

	for (int x : comp[pc])
	{
		comp[nc].push_back(x);
		color[x] = nc;
		check(x);
		check(x - 1);
	}
}

void join_seg(int l, int r)
{
	while (!bad_pos.empty())
	{
		auto it = bad_pos.lower_bound(l);
		if (it == bad_pos.end())
			break;
		int p = *it;
		if (p > r - 1)
			break;
		join(l, p + 1);
	}
}


int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &q);
	
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			bad_pos.insert(i);
		color[i] = i;
		comp[i].push_back(i);
	}
	
	for (int i = 0; i < q; i++)
	{
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		x--;
		y--;

		if (type == 1)
		{
			join(x, y);
		}
		else if (type == 2)
		{
			join_seg(x, y);
		}
		else
		{
			bool ans = same(x, y);
			printf("%s\n", (ans) ? "YES" : "NO");
		}
	}

	return 0;
}