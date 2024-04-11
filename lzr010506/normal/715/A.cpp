#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

ll gcd(ll a, ll b)
{
	while(a)
	{
		ll c = a;
		a = b % a;
		b = c;
	}
	return b;
}

int main()
{
	n = read();
	ll now = 2, ans, b;
	for(int i = 2; i <= n + 1; i ++)
	{
		b = (i - 1) / gcd(i - 1, i) * i;
		ans = b / gcd(i - 1, i) * i - now / (i - 1);
		now = b;
		printf("%I64d\n",ans);
	}
	return 0;
}