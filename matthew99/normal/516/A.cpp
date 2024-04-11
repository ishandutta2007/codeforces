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

int n;
char s[20];
int cnt[10];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", s);
	REP(i, 0, n)
	{
		int t = s[i] - '0';
		REP(j, 2, t + 1)
		{
			int x = j;
			for (int k = 2; k * k <= x; ++k)
				while (!(x % k))
				{
					++cnt[k];
					x /= k;
				}
			if (x > 1) ++cnt[x];
		}
	}
	for (int i = 9; i >= 1; --i)
		while (cnt[i])
		{
			printf("%d", i);
			int t = i;
			REP(j, 2, t + 1)
			{
				int x = j;
				for (int k = 2; k * k <= x; ++k)
					while (!(x % k))
					{
						--cnt[k];
						x /= k;
					}
				if (x > 1) --cnt[x];
			}
		}
	return 0;
}