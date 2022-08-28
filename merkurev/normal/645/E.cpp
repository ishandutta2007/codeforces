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

const int MOD = (int) 1e9 + 7;
const int N = (int) 2e6 + 100;
char str[N];

void add(int &a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}

const int ALP = 30;
int val[ALP];
int lastUse[ALP];
int answer = 1;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str);
	int m = strlen(str);

	for (int i = 0; i < k; i++)
	{
		val[i] = 1;
		lastUse[i] = -1;
	}
	for (int i = 0; i < n + m; i++)
	{
		int x;
		if (i < m)
			x = str[i] - 'a';
		else
		{
			x = 0;
			for (int j = 1; j < k; j++)
				if (lastUse[j] < lastUse[x] )
					x = j;
		}
		lastUse[x] = i;
		int curVal = val[x];
		add(answer, curVal);
		val[x] = 0;
		for (int j = 0; j < k; j++)
			add(val[j], curVal);
	}

	printf("%d\n", answer);

	return 0;
}