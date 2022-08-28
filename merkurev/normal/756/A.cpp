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


const int N = (int) 2e5 + 100;
int p[N];
int b[N];
bool used[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i] );
		p[i]--;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i] );

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (used[i] ) continue;
		int x = i;
		while (!used[x] )
		{
			used[x] = true;
			x = p[x];
		}
		cnt++;
	}
	int ans = ( (cnt > 1) ? cnt : 0);
	int sumb = 0;
	for (int i = 0; i < n; i++)
		sumb += b[i];
	ans += ( (sumb % 2) ? 0 : 1);
	printf("%d\n", ans);

	return 0;
}