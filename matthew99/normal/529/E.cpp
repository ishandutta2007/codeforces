#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <set>
#include <map>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 5000;

int n, k;

int a[maxn + 5];

map<int, int> Min;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		for (int j = 0; j <= k; ++j) 
			if (!Min.count(a[i] * j)) Min[a[i] * j] = j;
			else Min[a[i] * j] = min(Min[a[i] * j], j);
	}
	static int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		static int x;
		scanf("%d", &x);
		int ans = k + 1;
		REP(i, 0, n)
			REP(j, 0, k + 1)
				if (Min.count(x - a[i] * j)) ans = min(ans, j + Min[x - a[i] * j]);
		printf("%d\n", ans == k + 1 ? -1 : ans);
	}
	return 0;
}