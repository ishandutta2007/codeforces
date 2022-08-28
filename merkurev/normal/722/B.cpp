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


const int N = 105;
int p[N];
char s[N];

bool good(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i] );

	for (int i = 0; i < n; i++)
	{
		scanf("%*c%[^\n]", s);
		int len = strlen(s);
		for (int j = 0; j < len; j++)
			if (good(s[j] ) )
				p[i]--;
		if (p[i] != 0)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
}