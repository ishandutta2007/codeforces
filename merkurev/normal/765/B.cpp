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


const int N = (int) 505;
char str[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", str);
	int n = strlen(str);

	int cur = 'a';
	for (int i = 0; i < n; i++)
	{
		if (str[i] < cur) continue;
		if (str[i] > cur)
		{
			printf("NO\n");
			return 0;
		}
		if (str[i] == cur)
		{
			cur++;
		}
	}
	printf("YES\n");



	return 0;
}