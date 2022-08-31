#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

vector<int> vv;

const int MAXN = 1010000;

int n;

int c;

char s[10];

int xr[MAXN];
int xl[MAXN];
int xa[MAXN];

vector<int> el[MAXN];
vector<int> er[MAXN];





void dfs(int v, int r)
{
	if (v >= r)
		return;
	if (xa[v] >= r || xl[v] >= xr[v])
	{
		printf("IMPOSSIBLE");
		exit(0);
	}
	//assert(xa[v] < r);
	
	if (xl[v] == -1)
	{
		vv.push_back(v);
		dfs(v + 1, r);
		return;
	}

	dfs(v + 1, xl[v] + 1);

	vv.push_back(v);

	dfs(xl[v] + 1, r);
}


int rmq[MAXN * 4];



void upd(int v, int tl, int tr, int x)
{
	if (tl + 1 == tr)
	{
		rmq[v] = xa[tl];
		return;
	}
	int m = (tl + tr) >> 1;

	if (x < m)
		upd(v * 2 + 1, tl, m, x);
	else
		upd(v * 2 + 2, m, tr, x);

	rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}


int get(int v, int tl, int tr, int l, int r)
{
	if (r <= tl || tr <= l || r <= l)
		return -1;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return max(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}

int main()
{
	scanf("%d%d", &n, &c);

	for (int i = 0; i < c; ++i)
	{
		int a, b;
		scanf("%d%d %s", &a, &b, s);
		--a;
		--b;
		if (a >= b)
		{
			printf("IMPOSSIBLE");
			return 0;
		}
		if (s[0] == 'L')
			el[a].push_back(b);
		else
			er[a].push_back(b);
	}



	for (int i = n - 1; i >= 0; --i)
	{
		xa[i] = i;
		xl[i] = -1;
		for (int j = 0; j < (int)el[i].size(); ++j)
			xl[i] = max(xl[i], xa[el[i][j]]);
		//for (int j = i + 1; j <= xl[i]; ++j)
		//	xl[i] = max(xl[i], xa[j]);
			
		xl[i] = get(0, 0, n, i + 1, xl[i] + 1);

		for (int j = 0; j < (int)er[i].size(); ++j)
			xa[i] = max(xa[i], xa[er[i][j]]);

		xa[i] = max(xa[i], get(0, 0, n, i + 1, xa[i] + 1));

		//for (int j = i + 1; j <= xa[i]; ++j)
		//	xa[i] = max(xa[i], xa[j]);
		
		xa[i] = max(xa[i], xl[i]);

		xr[i] = n;
		for (int j = 0; j < (int)er[i].size(); ++j)
			xr[i] = min(xr[i], er[i][j]);
		upd(0, 0, n, i);
		//cout << i << " " << xa[i] << " " << xl[i] << " " << xr[i] << "\n";
	}

	//for (int i = 0; i < n; ++i)


	dfs(0, n);




	for (int i = 0; i < (int)vv.size(); ++i)
		printf("%d ", vv[i] + 1);

	return 0;
}