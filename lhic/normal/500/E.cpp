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

const int MAXN = 300000;
const int MAXLOG = 20;
int n, q;
int go[MAXN];
int len[MAXN];
int x[MAXN];
int l[MAXN];
int up[MAXLOG][MAXN];
int upc[MAXLOG][MAXN];
int cs[MAXN];

int rmq[MAXN * 4];

int get(int v, int tl, int tr, int l, int r)
{
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	
	return max(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}


void upd(int v, int tl, int tr, int x)
{
	if (tl + 1 == tr)
	{
		rmq[v] = len[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x);
	else
		upd(v * 2 + 2, m, tr, x);
	rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &x[i], &l[i]);
	
	
	scanf("%d", &q);
	
	
	for (int i = n - 1; i >= 0; --i)
	{
		int a = upper_bound(x, x + n, x[i] + l[i]) - x;
		len[i] = max(x[i] + l[i], get(0, 0, n, 0, a));
		go[i] = upper_bound(x, x + n, len[i]) - x;
		if (go[i] == n)
		{
			go[i] = n - 1;
			cs[i] = 0;
		}
		else
			cs[i] = x[go[i]] - len[i];
		upd(0, 0, n, i);
	}
	
	
	
	for (int i = 0; i < n; ++i)
	{
		up[0][i] = go[i];
		upc[0][i] = cs[i];
	}
	
	for (int i = 1; i < MAXLOG; ++i)
		for (int j = 0; j < n; ++j)
		{
			up[i][j] = up[i - 1][up[i - 1][j]];
			upc[i][j] = upc[i - 1][up[i - 1][j]] + upc[i - 1][j];
		}
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		int now = a;
		int cnt = 0;
		for (int j = MAXLOG - 1; j >= 0; --j)
		{
			if (up[j][now] <= b)
			{
				cnt += upc[j][now];
				now = up[j][now];
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}