#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f[1000];
ll Do(ll n)
{
	f[1] = 1;
	f[2] = 1;
	int i = 3;
	while(1)
	{
		f[i] = f[i - 1] + f[i - 2];
		if(f[i] > n)return i - 3;
		i ++;
	}
}

int main()
{
	ll n;
	scanf("%I64d", &n);
	printf("%I64d", Do(n));
	return 0;
}