#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Inf = 1000000000;

int n, k;
int c[Maxn];

bool Rich(int x)
{
	ll coll = 0;
	ll abz = 0;
	for (int i = 0; i < n; i++)
		if (c[i] > x) coll += c[i] - x;
		else abz += x - c[i];
	return coll <= k && abz >= coll;
}

bool Poor(int x)
{
	ll coll = 0;
	ll abz = 0;
	for (int i = 0; i < n; i++)
		if (c[i] < x) coll += x - c[i];
		else abz += c[i] - x;
	return coll <= k && abz >= coll;
}

int getMax()
{
	int l = 0, r = Inf;
	int res = Inf;
	while (l <= r) {
		int m = l + r >> 1;
		if (Rich(m)) { res = m; r = m - 1; }
		else l = m + 1;
	}
	return res;
}

int getMin()
{
	int l = 0, r = Inf;
	int res = 0;
	while (l <= r) {
		int m = l + r >> 1;
		if (Poor(m)) { res = m; l = m + 1; }
		else r = m - 1;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	printf("%d\n", getMax() - getMin());
	return 0;
}