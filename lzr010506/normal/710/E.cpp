#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, x, y, f[10000010];
int main()
{
	cin >> n >> x >> y;
	f[1] = x;
	for(int i = 2; i <= n; i ++)
	{
		if(i & 1) f[i] = f[((i + 1) >> 1)] + x + y;
		else f[i] = f[(i >> 1)] + y;
		f[i] = min(f[i], f[i - 1] + x);
	}
	printf("%I64d", f[n]);
	return 0;
}