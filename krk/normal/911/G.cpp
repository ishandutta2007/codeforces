#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Maxm = 105;

int n;
int a[Maxn];
int my[Maxm];
vector <int> L, R, V;
int q;
int res[Maxn];

void createNew()
{
	L.push_back(-1); R.push_back(-1); V.push_back(0);
}

int getLst() { return int(L.size()) - 1; }

void Union(int v)
{
	V[v] = (L[v] == -1? 0: V[L[v]]) + (R[v] == -1? 0: V[R[v]]);
}

void Insert(int v, int l, int r, int x)
{
	V[v]++;
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) {
			if (L[v] == -1) { createNew(); L[v] = getLst(); }
			Insert(L[v], l, m, x);
		} else {
			if (R[v] == -1) { createNew(); R[v] = getLst(); }
			Insert(R[v], m + 1, r, x);
		}
	}
}

void Assign(int v1, int v2, int l, int r, int a, int b)
{
	if (v2 == -1) return;
	if (l == a && r == b) {
		int m = l + r >> 1;
		if (L[v1] == -1) L[v1] = L[v2];
		else Assign(L[v1], L[v2], l, m, a, m);
		if (R[v1] == -1) R[v1] = R[v2];
		else Assign(R[v1], R[v2], m + 1, r, m + 1, b);
		V[v1] += V[v2]; L[v2] = -1; R[v2] = -1; V[v2] = 0;
	} else {
		int m = l + r >> 1;
		if (a <= m && L[v2] != -1) {
			if (L[v1] == -1) { createNew(); L[v1] = getLst(); }
			Assign(L[v1], L[v2], l, m, a, min(m, b)); 
		}
		if (m + 1 <= b && R[v2] != -1) {
			if (R[v1] == -1) { createNew(); R[v1] = getLst(); }
			Assign(R[v1], R[v2], m + 1, r, max(m + 1, a), b);
		}
		Union(v1); Union(v2);
	}
}

void Print(int v, int l, int r, int val)
{
	if (v == -1 || V[v] == 0) return;
	if (l == r) res[l] = val;
	else {
		int m = l + r >> 1;
		Print(L[v], l, m, val);
		Print(R[v], m + 1, r, val);
	}
}

void Print()
{
	fill(res, res + Maxn, -1);
	for (int i = 0; i < Maxm; i++)
		Print(my[i], 1, n, i);
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < Maxm; i++) {
		createNew(); my[i] = getLst();
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		Insert(my[a[i]], 1, n, i);
	}
	scanf("%d", &q);
	while (q--) {
		int l, r, x, y; scanf("%d %d %d %d", &l, &r, &x, &y);
		if (x != y)
			Assign(my[y], my[x], 1, n, l, r);
	}
	Print();
	return 0;
}