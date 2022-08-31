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

const int N = (int)2e6 + 100;

int n, m;
int str1[N], str2[N];

int pos[N];

bool in_seg(int x, int l, int r)
{
	if (l < r)
		return l <= x && x < r;
	return x >= l || x < r;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &str1[i]);
	for (int i = 0; i < n; i++)
		str1[n + i] = str1[i];

	for (int i = 0; i < m; i++)
		scanf("%d", &str2[i]);

	for (int i = 0; i < N; i++)
		pos[i] = -1;
	for (int i = 0; i < m; i++)
		pos[str2[i]] = i;

	int ans = 0;

	int r1 = 0;
	int l2 = -1;
	int r2 = -1;

	for (int l1 = 0; l1 < n; l1++)
	{
		//printf("l1 = %d r1 = %d l2 = %d r2 = %d\n", l1, r1, l2, r2);
		
		while (true)
		{
			int c = str1[r1];
			int p = pos[c];

			if (p == -1)
				break;
			
			if (l2 != -1 && in_seg(p, l2, r2))
				break;

			if (l2 == -1)
				l2 = p;
			
			r2 = (p + 1) % m;
			r1++;
		}
		
		//printf("l1 = %d r1 = %d l2 = %d r2 = %d\n", l1, r1, l2, r2);

		ans = max(ans, r1 - l1);
		
		if (l1 == r1)
		{
			r1++;
			continue;
		}

		if (l1 == r1 - 1)
		{
			l2 = -1;
			r2 = -1;
			continue;
		}
		
		int c = str1[l1 + 1];
		l2 = pos[c] % m;
	}

	printf("%d\n", ans);

	return 0;
}