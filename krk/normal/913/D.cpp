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

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, T;
int a[Maxn], t[Maxn];
ii seq[Maxn];
int slen;

bool Pos(int x)
{
	slen = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] >= x) seq[slen++] = ii(t[i], i);
	sort(seq, seq + slen);
	if (slen < x) return false;
	int tot = 0;
	for (int i = 0; i < x; i++)
		tot += seq[i].first;
	return tot <= T;
}

void Print(int x)
{
	slen = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] >= x) seq[slen++] = ii(t[i], i);
	sort(seq, seq + slen);
	printf("%d\n", x);
	printf("%d\n", x);
	for (int i = 0; i < x; i++)
		printf("%d%c", seq[i].second, i + 1 < x? ' ': '\n');
}

int main()
{
	scanf("%d %d", &n, &T);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i], &t[i]);
	int lef = 1, rig = n;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Pos(mid)) lef = mid + 1;
		else rig = mid - 1;
	}
	Print(lef - 1);
	return 0;
}