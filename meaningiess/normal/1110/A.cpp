#include<bits/stdc++.h>
#define int long long
#define LL long long
using namespace std;
const int maxn = 1e6 + 10,mod = 2;
int b,k,a[maxn];
inline int qpow(int x,int t)
{
	if(!t)return 1;
	int res = 1;
	while(t)
	{
		if(t & 1)res = res * x % mod;
		x = x * x % mod;
		t = t >> 1;
	}return res;
}
signed main()
{
	cin>>b>>k;
	for (int i=1;i<=k;i++) cin>>a[i];
	int res = 0;
	for(int i=1;i<=k;i++)
	{
		res = res + qpow(b,k-i) * a[i];
		res %= mod;
	}
	puts(res ? "odd" : "even");
}