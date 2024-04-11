#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 1e5 + 100;
char s[N];
int m, len;
int cnt[300];

bool test(char c, int k)
{
	int prv = -1;
	int toadd = -1;
	for (int i = 0; i < len; i++)
	{
		if (s[i] < c)
		{
			prv = i;
			continue;
		}
		if (s[i] == c)
			toadd = i;
		if (i - prv == m)
		{
			k--;
			prv = toadd;
		}
		if (i - prv >= m)
			return false;
	}
	if (k < 0) return false;
	return true;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%s", &m, s);
	len = strlen(s);
	for (int i = 0; i < len; i++)
		cnt[(int) s[i]]++;

	for (char c = 'a'; c <= 'z'; c++)
		if (test(c, N) )
		{
			int l = 0, r = N;
			while (r - l > 1)
			{
				int bm = (l + r) / 2;
				if (test(c, bm) )
					r = bm;
				else
					l = bm;
			}
			for (char x = 'a'; x < c; x++)
				for (int i = 0; i < cnt[(int)x]; i++)
					printf("%c", x);
			for (int i = 0; i < r; i++)
				printf("%c", c);
			printf("\n");
			return 0;
		}
	throw;
}