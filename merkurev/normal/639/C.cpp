#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


const int N = (int) 2e5 + 500;

int a[N];
int b[N];

int sgn(int x)
{
	if (!x) return 0;
	return x > 0 ? 1 : -1;
}

int main()
{
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; i++)
		scanf("%d", &a[i] );

	for (int i = 0; i <= n; i++)
	{
		int ptr = i;
		int s = sgn(a[i] );
		int x = abs(a[i] );
		while (x > 0)
		{
			b[ptr++] += s * (x & 1);
			x >>= 1;
		}
	}
	int mx = n + 100;
	for (int i = 0; i < mx; i++)
	{
		while (b[i] < 0)
		{
			b[i] += 2;
			b[i + 1]--;
		}
		while (b[i] >= 2)
		{
			b[i] -= 2;
			b[i + 1]++;
		}
	}
	while (b[mx] == 0)
		mx--;
	while (b[mx] == -1 && mx > 0 && b[mx - 1] == 1)
	{
		b[mx] = 0;
		b[mx - 1] = -1;
		mx--;
	}
	int mn = 0;
	while (b[mn] == 0)
		mn++;

	int answer = 0;
	for (int i = 0; i <= n; i++)
	{
		if (mn < i) continue;
		if (mx > i + 40) continue;
		long long cans = 0;
		for (int j = mx; j >= i; j--)
		{
			cans *= 2;
			cans += b[j];
		}
		long long need = -cans + a[i];
		if (llabs(need) > k) continue;
		if (need == 0 && i == n) continue;
//		eprintf("i = %d, need = %lld\n", i, need);
		answer++;
	}
	printf("%d\n", answer);

	return 0;
}