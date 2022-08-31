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

const int MAX_N = 101000;

int l[MAX_N];
int r[MAX_N];
int q[MAX_N];

int dd[MAX_N * 4];
int rmq[MAX_N * 4];

int arr[MAX_N];

int n, m;

void add(int v, int tl, int tr, int l, int r, int x)
{
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r)
	{
		dd[v] |= x;
		return;
	}
	
	int m = (tl + tr) >> 1;
	
	add(v * 2 + 1, tl, m, l, r, x);
	add(v * 2 + 2, m, tr, l, r, x);
	
}


int get(int v, int tl, int tr, int x)
{
	if (tl + 1 == tr)
		return dd[v];
	int m = (tl + tr) >> 1;
	if (x < m)
		return dd[v] | get(v * 2 + 1, tl, m, x);
	else
		return dd[v] | get(v * 2 + 2, m, tr, x);
}


void build(int v, int tl, int tr)
{
	if (tl + 1 == tr)
	{
		rmq[v] = arr[tl];
		return;
	}
	
	int m = (tl + tr) >> 1;
	
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	
	rmq[v] = rmq[v * 2 + 1] & rmq[v * 2 + 2];
}


int get2(int v, int tl, int tr, int l, int r)
{
	if (r <= tl || tr <= l)
		return (1 << 30) - 1;
	
	if (l <= tl && tr <= r)
		return rmq[v];
	
	int m = (tl + tr) >> 1;
	
	return get2(v * 2 + 1, tl, m, l, r) & get2(v * 2 + 2, m, tr, l, r);	
}




int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> l[i] >> r[i] >> q[i];
	
	for (int i = 0; i < m; ++i)
		add(0, 0, n, l[i] - 1, r[i], q[i]);
	
	
	for (int i = 0; i < n; ++i)
		arr[i] = get(0, 0, n, i);
	
	build(0, 0, n);
	
	for (int i = 0; i < m; ++i)
	{
		if (get2(0, 0, n, l[i] - 1, r[i]) != q[i])
		{
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES\n";
	
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	
	
	
	return 0;
}