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


char str[100];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int ans;
	int x;
	scanf("%d%*s%s", &x, str);

	if (string(str) == "week")
	{
		ans = 52;
		if (x == 5 || x == 6)
			ans++;
	}
	else if (string(str) == "month")
	{
		if (x <= 29)
			ans = 12;
		if (x == 30)
			ans = 11;
		if (x == 31)
			ans = 7;
	}
	else throw;

	printf("%d\n", ans);

	return 0;
}