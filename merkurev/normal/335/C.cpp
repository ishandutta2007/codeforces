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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int maxn = (int) 105;
int f[maxn][2];

int ansFull[maxn];
int ansOne[maxn];
int ansEq[maxn];
int ansDiff[maxn];
bool used[maxn * maxn];

int getFirst()
{
	int x = 0;
	while (used[x] )
		x++;
	memset(used, false, sizeof used);

	return x;
}

void init()
{
	for (int i = 1; i < maxn; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int cur = ansOne[j] ^ ansOne[i - j - 1];
			used[cur] = true;
		}
		ansFull[i] = getFirst();
	
		for (int j = 0; j < i; j++)
		{
			int cur = ansEq[j] ^ ansOne[i - j - 1];
			used[cur] = true;
			if (j != 0)
			{
				cur = ansDiff[j] ^ ansOne[i - j - 1];
				used[cur] = true;
			}
		}
		ansOne[i] = getFirst();

		for (int j = 0; j < i; j++)
		{
			int cur = ansEq[j] ^ ansEq[i - j - 1];
			used[cur] = true;
			if (j != 0 && j != i - 1)
			{
				cur = ansDiff[j] ^ ansDiff[i - j - 1];
				used[cur] = true;
			}
		}
		ansEq[i] = getFirst();

		for (int j = 0; j < i; j++)
		{
			if (j != 0)
			{
				int cur = ansDiff[j] ^ ansEq[i - j - 1];
				used[cur] = true;
			}
			if (j != i - 1)
			{
				int cur = ansEq[j] ^ ansDiff[i - j - 1];
				used[cur] = true;
			}
		}
		ansDiff[i] = getFirst();
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	init();

	int r, n;
	scanf("%d%d", &r, &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		f[x][y] = 1;
	}

	int ans = 0;
	for (int i = 0; i < r; i++)
	{
		if (f[i][0] != 0 || f[i][1] != 0)
			continue;
		int ni = i;
		while (ni + 1 < r && f[ni + 1][0] == 0 && f[ni + 1][1] == 0)
			ni++;
		int len = ni - i + 1;
		int cur;
		if (i == 0 && ni == r - 1)
			cur = ansFull[len];
		else if (i == 0 || ni == r - 1)
			cur = ansOne[len];
		else if (f[i - 1][0] == f[ni + 1][0] )
			cur = ansEq[len];
		else
			cur = ansDiff[len];
		ans ^= cur;
		i = ni;
	}
	printf(ans == 0 ? "LOSE" : "WIN");

	return 0;
}