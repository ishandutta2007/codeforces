#include<bits/stdc++.h>
#define N 1000000
#define int long long
using namespace std;
int fac[N+5],n,mod=1e9+7;
int quickPower(int a, int b)
{
	int ans = 1, base = a;
	while(b > 0)
    {
		if(b & 1)
			(ans *= base)%=mod;
        (base *= base)%=mod;
		b >>= 1;
	}
	return ans;
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%mod;
	cin>>n;
	cout<<(fac[n]-quickPower(2,n-1)+mod)%mod<<endl;
}