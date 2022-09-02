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

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200000;

int n;
int a[maxn + 5];

int sum[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 1, n + 1) scanf("%d", a + i);
	for (int j = 2; j <= n; ++j)
	{
		int tmp = j - 2;
		for (int i = 1, l, r; ; i = r + 1)
		{
			int tmp0 = (tmp / i) + 1;
			l = tmp / tmp0 + 1, r = (tmp0 == 1 ? n : tmp / (tmp0 - 1));
			if (::a[j] < ::a[tmp0]) ++sum[l], --sum[r + 1];
			if (i > tmp) break;
		}
	}
	int Sum = 0;
	for (int i = 1; i <= n - 1; ++i)
	{
		Sum += sum[i];
		printf("%d ", Sum);
	}
	return 0;
}