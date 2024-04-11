#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 35005;
const int Maxm = 52;
const int Maxs = 262144;

int n, k;
int a[Maxn];
int mx[Maxm][Maxs], flag[Maxm][Maxs];
int lst[Maxn];

void downOn(int t, int v, int val)
{
	mx[t][v] += val; flag[t][v] += val;
}

void Down(int t, int v)
{
	if (flag[t][v]) {
		downOn(t, 2 * v, flag[t][v]);
		downOn(t, 2 * v + 1, flag[t][v]);
		flag[t][v] = 0;
	}
}

void Union(int t, int v)
{
	mx[t][v] = max(mx[t][2 * v], mx[t][2 * v + 1]);
}

void Create(int t, int v, int l, int r)
{
	mx[t][v] = -Inf; flag[t][v] = 0;
	if (l < r) {
		int m = l + r >> 1;
		Create(t, 2 * v, l, m); 
		Create(t, 2 * v + 1, m + 1, r);
	}
}

void Insert(int t, int v, int l, int r, int p, int val)
{
	if (l == r) { mx[t][v] = val; flag[t][v] = 0; }
	else {
		Down(t, v);
		int m = l + r >> 1;
		if (p <= m) Insert(t, 2 * v, l, m, p, val);
		else Insert(t, 2 * v + 1, m + 1, r, p, val);
		Union(t, v);
	}
}

void Inc(int t, int v, int l, int r, int a, int b)
{
	if (l == a && r == b) downOn(t, v, 1);
	else {
		Down(t, v);
		int m = l + r >> 1;
		if (a <= m) Inc(t, 2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) Inc(t, 2 * v + 1, m + 1, r, max(m + 1, a), b);
		Union(t, v);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	fill(lst, lst + Maxn, -1);
	for (int i = 0; i <= k; i++)
		Create(i, 1, 0, n - 1);
	Insert(1, 1, 0, n - 1, 0, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 1; j <= k; j++) {
			if (j < k) Insert(j + 1, 1, 0, n - 1, i, mx[j][1]);
			Inc(j, 1, 0, n - 1, lst[a[i]] + 1, i);
		}
		lst[a[i]] = i;
	}
	printf("%d\n", mx[k][1]);
	return 0;
}