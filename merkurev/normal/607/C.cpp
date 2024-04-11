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

const int N = (int) 1e6 + 100;

char a[2 * N], b[N];

char rev(char x)
{
	if (x == 'N')
		return 'S';
	if (x == 'S')
		return 'N';
	if (x == 'E')
		return 'W';
	if (x == 'W')
		return 'E';
	throw;
}

int z[2 * N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	n--;
	scanf("%s%s", a, b);

	for (int i = 0; i < n; i++)
		b[i] = rev(b[i] );
	reverse(a, a + n);
	a[n] = 0;
	for (int i = 0; i < n; i++)
		a[n + i + 1] = b[i];
	n = 2 * n + 1;

	int lw = 0, rw = 0;
	for (int i = 1; i < n; i++)
	{
		if (i < rw)
			z[i] = min(z[i - lw], rw - i);
		while (i + z[i] < n && a[z[i] ] == a[i + z[i] ] )
			z[i]++;
		if (i + z[i] > rw)
		{
			lw = i;
			rw = i + z[i];
			if (i + z[i] == n)
			{
				printf("NO\n");
				return 0;
			}
		}
	}


	printf("YES\n");


	return 0;
}