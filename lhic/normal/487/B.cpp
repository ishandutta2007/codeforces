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


using namespace std;

typedef long long ll;
typedef long double ld;

int s, n;
int l;



const int MAX_N = 120000;
int rmq1n[MAX_N * 4];
int rmq1m[MAX_N * 4];
int rmq[MAX_N * 4];

int go[MAX_N];
int dp[MAX_N];
int arr[MAX_N];



void build(int v, int tl, int tr)
{
	if (tl + 1 == tr)
	{
		rmq1n[v] = arr[tl];
		rmq1m[v] = arr[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	
	rmq1n[v] = min(rmq1n[v * 2 + 1], rmq1n[v * 2 + 2]);
	rmq1m[v] = max(rmq1m[v * 2 + 1], rmq1m[v * 2 + 2]);	
}


int getm(int v, int tl, int tr, int l, int r)
{
	if (r <= tl || tr <= l)
		return -1000000000;
	
	if (l <= tl && tr <= r)
		return rmq1m[v];
	
	int m = (tl + tr) >> 1;
	return max(getm(v * 2 + 1, tl, m, l, r), getm(v * 2 + 2, m, tr, l, r));
}

int getn(int v, int tl, int tr, int l, int r)
{
	if (r <= tl || tr <= l)
		return 1000000000;
	
	if (l <= tl && tr <= r)
		return rmq1n[v];
	
	int m = (tl + tr) >> 1;
	return min(getn(v * 2 + 1, tl, m, l, r), getn(v * 2 + 2, m, tr, l, r));
}

bool ch(int l, int r)
{
	if (getm(0, 0, n, l, r) - getn(0, 0, n, l, r) > s)
		return false;
	else
		return true;
}



void upd(int v, int tl, int tr, int x)
{
	if (tl + 1 == tr)
	{
		rmq[v] = dp[x];
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x);
	else
		upd(v * 2 + 2, m, tr, x);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void upd(int x)
{
	upd(0, 0, n, x);
}

int get(int v, int tl, int tr, int l, int r)
{
	if (r <= tl || tr <= l)
		return 1000000000;
	if (l <= tl && tr <= r)
		return rmq[v];
	
	int m = (tl + tr) >> 1;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m , tr, l, r));
	
}

int get(int l, int r)
{
	return get(0, 0, n, l, r);
}


int main()
{
	scanf("%d%d%d", &n, &s, &l);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	
	build(0, 0, n);
	

	go[0] = 0;
	int lll = 0;
	for (int i = 1; i < n; ++i)
	{
		while (!ch(lll, i + 1))
			++lll;
		go[i] = lll;
	}
	
	dp[0] = 0;
	
	
	
	for (int i = 0; i < n; ++i)
	{
		if (i - go[i] + 1 < l)
		{
			dp[i + 1] = 1000000000;
			upd(i + 1);
			continue;
		}
		
		dp[i + 1] = get(go[i], i - l + 2) + 1;
		
		upd(i + 1);
	}
	
	if (dp[n] > n)
		cout << -1;
	else
		cout << dp[n];
	
	
	return 0;
}