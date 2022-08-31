#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int MOD = (int) 1e9 + 7;
int mul(int a, int b)
{
	return (a * 1LL * b) % MOD;
}

const int N = (int) 1e6 + 100;
vector <pair <int, int> > list[N];
int p[N];
int color[N];
int fact[N];

int ID;
int curColor;

bool cmpID(int a, int b)
{
	return list[a][ID] < list[b][ID];
}

void mySort(int l, int r, int id)
{
	/*
	eprintf("curCompare : %d\n", id);
	for (int i = l; i <= r; i++)
		eprintf("%d ", p[i] );
	eprintf("\n");
*/
	if (id == (int) list[p[l] ].size() ) return;
	ID = id;
	sort(p + l, p + r + 1, cmpID);
	curColor++;
	for (int i = l; i <= r; i++)
	{
		if (i > l && cmpID(p[i - 1], p[i] ) )
			curColor++;
		color[i] = curColor;
	}
	for (int i = l; i <= r;)
	{
		int j = i;
		while (j <= r && color[j] == color[i] ) j++;
		mySort(i, j - 1, id + 1);
		i = j;
	}
}

bool cmpLen(int a, int b)
{
	return list[a].size() < list[b].size();
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = mul(fact[i - 1], i);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		vector <int> v;
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			x--;
			v.push_back(x);
		}
		sort(v.begin(), v.end() );
		int lst = -1, cnt = 0;
		for (int x : v)
		{
			if (x == lst)
				cnt++;
			else
			{
				if (cnt != 0)
					list[lst].emplace_back(i, cnt);
				lst = x;
				cnt = 1;
			}
		}
		if (cnt != 0)
			list[lst].emplace_back(i, cnt);
	}
	for (int i = 0; i < m; i++)
		p[i] = i;
	sort(p, p + m, cmpLen);

	curColor++;
	for (int i = 0; i < m; i++)
	{
		if (i > 0 && cmpLen(p[i - 1], p[i] ) )
			curColor++;
		color[i] = curColor;
	}
	for (int i = 0; i < m;)
	{
		int j = i;
		while (j < m && color[j] == color[i] ) j++;
		mySort(i, j - 1, 0);
		i = j;
	}
/*	for (int i = 0; i < m; i++)
		eprintf("%d ", color[i]);
	eprintf("\n");
*/
	int ans = 1;
	for (int i = 0; i < m;)
	{
		int j = i;
		while (j < m && color[j] == color[i] ) j++;
		int len = j - i;
		ans = mul(ans, fact[len] );
		i = j;
	}
	printf("%d\n", ans);

	return 0;
}