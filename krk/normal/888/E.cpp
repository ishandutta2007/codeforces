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

const int Maxn = 38;

int n, m;
int a[Maxn];
set <int> S;
int res;

int main()
{
	scanf("%d %d", &n, &m);
	int st = (n + 1) / 2;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 1 << st; i++) {
		int cur = 0;
		for (int j = 0; j < st; j++)
			if (i & 1 << j) cur = (cur + a[j]) % m;
		S.insert(cur);
	}
	int st2 = n - st;
	for (int i = 0; i < 1 << st2; i++) {
		int cur = 0;
		for (int j = 0; j < st2; j++)
			if (i & 1 << j) cur = (cur + a[st + j]) % m;
		int nd = (m - (cur + 1)) % m;
		set <int>::iterator it = S.upper_bound(nd); it--;
		res = max(res, (*it + cur) % m);
	}
	printf("%d\n", res);
	return 0;
}