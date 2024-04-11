#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <bitset>


using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 120000;

int n, q;

int rmq[MAXN * 4][61];

int arr[MAXN];



void init(int v, int x)
{
	for (int i = 0; i < 60; ++i)
	{
		if (i % arr[x] == 0)
			rmq[v][i] = 2;
		else
			rmq[v][i] = 1;
	}
}

void mer(int v)
{
	for (int i = 0; i < 60; ++i)
		rmq[v][i] = rmq[v * 2 + 1][i] + rmq[v * 2 + 2][(i + rmq[v * 2 + 1][i]) % 60];
}



void build(int v, int tl, int tr)
{
	if (tl + 1 == tr)
	{
		init(v, tl);
		return;
	}
	int m = (tl + tr) >> 1;
	
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	
	mer(v);
}

int get(int v, int tl, int tr, int l, int r, int st)
{
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r)
		return rmq[v][st];
	int m = (tl + tr) >> 1;
	int x = get(v * 2 + 1, tl, m, l, r, st);
	return get(v * 2 + 2, m, tr, l, r, (st + x) % 60) + x;
}

int get(int l, int r)
{
	return get(0, 0, n, l, r, 0);
}


void upd(int v, int tl, int tr, int x)
{
	if (tl + 1 == tr)
	{
		init(v, tl);
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x);
	else
		upd(v * 2 + 2, m, tr, x);
	
	mer(v);
}

void upd(int x)
{
	upd(0, 0, n, x);
}






int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &q);
	
	build(0, 0, n);

	for (int i = 0; i < q; ++i)
	{
		char c;
		int x, y;
		scanf(" %c%d%d", &c, &x, &y);
		if (c == 'A')
		{
			--x;
			--y;
			printf("%d\n", get(x, y));
		}
		else
		{
			--x;
			arr[x] = y;
			upd(x);
		}
	}
	
	
	return 0;
}