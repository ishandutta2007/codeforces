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
int fn[N];

void fn_add(int pos)
{
	pos++;
	for (; pos < N; pos = (pos | (pos - 1) ) + 1)
		fn[pos]++; 
}
int fn_sum(int pos)
{
	pos++;
	int ans = 0;
	for (; pos > 0; pos = (pos & (pos - 1) ) )
		ans += fn[pos];
	return ans;
}
int fn_sum(int l, int r)
{
	return fn_sum(r) - fn_sum(l - 1);
}
void add(int pos)
{
	fn_add(pos);
}
int sum(int l, int r)
{
	if (l <= r)
		return fn_sum(l, r);
	else return fn_sum(0, r) + fn_sum(l, N - 2);
}



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	if (2 * k > n)
		k = n - k;


	long long ans = 1;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		int nx = (x + k) % n;
		int cnt = sum( (x - k + 1 + n) % n, (x + k - 1) % n);
		ans += cnt + 1;
		add(x);
		x = nx;
		printf("%lld ", ans);
	}
	printf("\n");



	return 0;
}