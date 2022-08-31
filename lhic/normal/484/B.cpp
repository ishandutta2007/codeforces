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

const int MAX_N = 210000;

int rmq[MAX_N * 4];
int pos[MAX_N * 4];
int arr[MAX_N];

int d;
int n;

void upd(int v, int tl, int tr, int x, int d)
{
	if (tl + 1 == tr)
	{
		rmq[v] = d;
		return;
	}
	int m = (tl + tr) >> 1;
	
	if (x < m)
		upd(v * 2 + 1, tl, m, x, d);
	else
		upd(v * 2 + 2, m, tr, x, d);
	
	if (rmq[v * 2 + 1] > rmq[v * 2 + 2])
		pos[v] = pos[v * 2 + 1], rmq[v] = rmq[v * 2 + 1];
	else
		pos[v] = pos[v * 2 + 2], rmq[v] = rmq[v * 2 + 2];
}

void upd(int x, int d)
{
	upd(0, 0, n, x, d);
}

void build(int v, int tl, int tr)
{
	pos[v] = tl;
	rmq[v] = -1000000000;
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}


int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	n = unique(arr, arr + n) - arr;
	
	build(0, 0, n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		d = arr[i];
		upd(i, -d);
		while (rmq[0] + d >= arr[pos[0]] && rmq[0] + d > ans)
			upd(pos[0], (rmq[0] + d) % arr[pos[0]] - d);
		if (rmq[0] + d > ans)
			ans = rmq[0] + d;
	}
	
	cout << ans;
	
	
	return 0;
}