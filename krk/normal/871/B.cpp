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

const int Maxn = 5005;

int n;
int my[Maxn], my2[Maxn];
int a[Maxn], b[Maxn];
bool tk[Maxn];
int cnt, lst;

int Get(int i, int j)
{
	printf("? %d %d\n", i, j); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

bool Check(int a[])
{
	fill(tk, tk + n, false);
	for (int i = 0; i < n; i++)
		if (a[i] >= n || tk[a[i]]) return false;
		else tk[a[i]] = true;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		my[i] = Get(i, 0);
		my2[i] = Get(0, i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			a[j] = (my[i] ^ my[j]);
		if (!Check(a)) continue;
		int zer = a[0];
		for (int j = 0; j < n; j++)
			b[j] = (my2[zer] ^ my2[j]);
		if (!Check(b)) continue;
		bool ok = (a[0] ^ b[0]) == my[0];
		for (int j = 0; j < n && ok; j++)
			ok = b[a[j]] == j;
		if (ok) { cnt++; lst = i; }
	}
	printf("!\n");
	printf("%d\n", cnt);
	for (int j = 0; j < n; j++) {
		a[j] = (my[lst] ^ my[j]);
		printf("%d%c", a[j], j + 1 < n? ' ': '\n');
	}
	fflush(stdout);
	return 0;
}