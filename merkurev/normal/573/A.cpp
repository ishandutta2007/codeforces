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



void solve()
{
	int n;
	scanf("%d", &n);
	int x = -1;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		while (a % 2 == 0)
			a /= 2;
		while (a % 3 == 0)
			a /= 3;
		if (i == 0)
			x = a;
		else if (x != a)
		{
			printf("No");
			return;
		}
	}
	printf("Yes");
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