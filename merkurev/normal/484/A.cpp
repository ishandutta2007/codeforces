#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;



const int K = 70;
int a[K];
int b[K];

void solve()
{
	long long l, r;
	scanf("%I64d%I64d", &l, &r);

	long long _r = r;

	for (int i = 0; i < K; i++)
	{
		a[i] = l % 2;
		l /= 2;
		b[i] = r % 2;
		r /= 2;
	}
	int ans1 = 0;
	
	for (int i = K - 1; i >= 0; i--)
	{
		ans1 += b[i];	
	}
	int ans2 = 0;
	long long X = 0;
	for (int i = K - 1; i >= 0; i--)
	{
		if (a[i] != b[i] )
		{
			ans2 += i;
			X <<= i + 1;
			X |= (1LL << i) - 1;
			break;
		}
		X *= 2;
		X |= a[i];
		ans2 += a[i];
	}
	if (ans1 > ans2)
	{
		printf("%I64d\n", _r);
	}
	else
	{
		printf("%I64d\n", X);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		solve();
	return 0;
}