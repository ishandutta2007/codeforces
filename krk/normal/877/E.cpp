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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
	int zers, ones;
	bool flag;
	node(): zers(0), ones(0), flag(false) {}
};

int n;
vector <int> neigh[Maxn];
int t[Maxn];
int cur, lef[Maxn], rig[Maxn];
int inplace[Maxn];
node st[Maxm];

void Traverse(int v)
{
	lef[v] = ++cur; inplace[lef[v]] = t[v];
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i]);
	rig[v] = cur;
}

void downOn(int v)
{
	swap(st[v].zers, st[v].ones);
	st[v].flag ^= true;
}

void Down(int v)
{
	if (st[v].flag) {
		downOn(2 * v); downOn(2 * v + 1);
		st[v].flag = false;
	}
}

node Union(const node &a, const node &b)
{
	node c; 
	c.zers = a.zers + b.zers;
	c.ones = a.ones + b.ones;
	return c;
}

void Create(int v, int l, int r)
{
	if (l == r)
		if (inplace[l]) st[v].zers = 0, st[v].ones = 1;
		else st[v].zers = 1, st[v].ones = 0;
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

void Update(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) downOn(v);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v].ones;
	else {
		Down(v);
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	Traverse(1);
	Create(1, 1, n);
	int q; scanf("%d", &q);
	char str[10];
	while (q--) {
		int v; scanf("%s %d", str, &v);
		if (str[0] == 'g') printf("%d\n", Get(1, 1, n, lef[v], rig[v]));
		else Update(1, 1, n, lef[v], rig[v]);
	}
	return 0;
}