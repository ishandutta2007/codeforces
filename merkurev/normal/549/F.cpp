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


const int maxn = (int) 3e5 + 100;
int a[maxn];
int sum[maxn];

int lb[maxn], rb[maxn];
int st[maxn];
int sz = 0;

const int MX = (int) 1e6 + 100;
vector <int> pos[MX];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	scanf("%d%d", &n, &k);

	pos[0].push_back(0);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i] );
		sum[i] = (sum[i - 1] + a[i] ) % k;
		pos[sum[i] ].push_back(i);
	}

	for (int i = 1; i <= n; i++)
	{
		while (sz > 0 && a[st[sz - 1] ] < a[i] )
			sz--;
		lb[i] = 0;
		if (sz != 0)
			lb[i] = st[sz - 1];
		st[sz++] = i;
	}
	sz = 0;
	for (int i = n; i >= 1; i--)
	{
		while (sz > 0 && a[st[sz - 1] ] <= a[i] )
			sz--;
		rb[i] = n + 1;
		if (sz != 0)
			rb[i] = st[sz - 1];
		st[sz++] = i;
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
//		eprintf("lb = %d, i = %d, rb = %d\n", lb[i], i, rb[i] );
		int dl = i - lb[i];
		int dr = rb[i] - i;
		if (dl < dr)
		{
			for (int j = lb[i] + 1; j <= i; j++)
			{
				int needSum = (sum[j - 1] + a[i] ) % k;
				int cnt = lower_bound(pos[needSum].begin(), pos[needSum].end(), rb[i] ) -
					lower_bound(pos[needSum].begin(), pos[needSum].end(), i);
//				eprintf("j = %d, need = %d, cnt = %d\n", j, needSum, cnt);
				ans += cnt;
			}
		}
		else
		{
			for (int j = i; j < rb[i]; j++)
			{
				int needSum = ( (sum[j] - a[i] ) % k + k) % k;
				int cnt = lower_bound(pos[needSum].begin(), pos[needSum].end(), i) -
					lower_bound(pos[needSum].begin(), pos[needSum].end(), lb[i] );
//				eprintf("j = %d, need = %d, cnt = %d\n", j, needSum, cnt);
				ans += cnt;
			}
		}
	}

	printf("%lld\n", ans - n);


	return 0;
}