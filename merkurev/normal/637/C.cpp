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


const int N = 1005;
char str[N][10];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", str[i] );
	
	int mn = 6;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int d = 0;
			for (int h = 0; h < 6; h++)
				if (str[i][h] != str[j][h] )
					d++;
			mn = min(mn, (d - 1) / 2);
		}
	printf("%d\n", mn);

	return 0;
}