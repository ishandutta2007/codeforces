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

void solve(char s[], int l, int r)
{
	int len = (r - l);
	if (len % 2 == 1)
		return;
	int m = (l + r) / 2;
	solve(s, l, m);
	solve(s, m, r);
	bool sw = false;
	for (int i = 0; i < len / 2; i++)
	{
		if (s[l + i] != s[m + i] )
		{
			if (s[m + i] < s[l + i] )
				sw = true;
			break;
		}
	}
	if (sw)
		for (int i = 0; i < len / 2; i++)
			swap(s[l + i], s[m + i] );
}

void readNorm(char s[] )
{
	scanf("%s", s);
	int n = strlen(s);
	solve(s, 0, n);
}

const int maxn = (int) 2e5 + 100;
char sa[maxn];
char sb[maxn];


void solve()
{
	readNorm(sa);
	readNorm(sb);
	int len = strlen(sa);
	for (int i = 0; i < len; i++)
		if (sa[i] != sb[i] )
		{
			printf("NO");
			return;
		}
	printf("YES");
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}