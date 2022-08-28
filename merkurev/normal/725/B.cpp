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




int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	long long n;
	char s[2];
	scanf("%lld%s", &n, s);
	n--;
	char x = s[0];
	long long ans = n / 4 * (12 + 4);
	n %= 4;
	if (n % 2 == 1)
		ans += (6 + 1);
	if (x >= 'd')
		ans += 'f' - x;
	else
		ans += 3 + x - 'a';
	printf("%lld\n", ans + 1);



	return 0;
}