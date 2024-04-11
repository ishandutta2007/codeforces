#include <bitset>
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
int p[N];
bool used[N];

int lcnt[N];
bool cb[N];
bitset <N> bcb;

const int BG = 400;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i] );
		if (p[i] <= 0 || p[i] > N) throw;
		p[i]--;
	}
	if (n > N) throw;
	if (k < 0 || k > N) throw;
	for (int i = 0; i < n; i++)
	{
		if (used[i] ) continue;
		int x = i;
		int cnt = 0;
		while (!used[x] )
		{
			used[x] = true;
			cnt++;
			x = p[x];
		}
		lcnt[cnt]++;
	}
	
	int cnt1 = 0;
	int cnt2 = 0;
	for (int x = 2; x <= n; x++)
	{
		for (int i = 0; i < lcnt[x]; i++)
		{
			cnt2 += x / 2;
			cnt1 += x % 2;
		}
	}
	int take2 = min(k, cnt2);
	int MX = take2 * 2 + min(cnt1, k - take2);
	
	int MN = k + 1;
	cb[0] = true;
	int mx = 0;
	
	
	for (int x = 2; x < BG; x++)
	{
		int cnt = lcnt[x];
		if (cnt == 0) continue;
		for (int i = mx; i >= 0; i--)
		{
			if (!cb[i] ) continue;
			int pos = i + x;
			for (int j = 0; j < cnt; j++)
			{
				if (cb[pos] ) break;
				cb[pos] = true;
				pos += x;
			}
		}
		mx += x * cnt;
		if (mx > N) throw;
	}
	for (int i = 0; i <= mx; i++)
		bcb[i] = cb[i];

	for (int x = BG; x <= n; x++)
		for (int i = 0; i < lcnt[x]; i++)
		{
			bcb |= (bcb << x);
		}

	if (bcb[k] )
		MN = k;

	printf("%d %d\n", MN, MX);

	return 0;
}