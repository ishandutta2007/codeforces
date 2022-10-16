#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define zh(n,m) (((n)<(m))?0:(csh[(n)][0]*csh[(m)][1]%mod*csh[(n)-(m)][1]%mod))
using namespace std;
int csh[200001][2];
inline int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y%2)ans=ans*x%mod;
		y/=2;
		x=x*x%mod;
	}
	return ans;
}
signed main()
{
	int w,f,h;
	cin>>f>>w>>h;
	int n=w+f,ans=0;
	if(w==0)return puts("1");
	csh[0][0]=1;
	for(int x=1;x<=n;x++)
	csh[x][0]=csh[x-1][0]*x%mod;
	csh[n][1]=qpow(csh[n][0],mod-2);
	for(int x=n-1;x>=0;x--)
	csh[x][1]=csh[x+1][1]*(x+1)%mod;
	for(int x=1;x*(h+1)<=w;x++)
	ans=(ans+zh(f+1,x)*zh(w-x*h-1,x-1))%mod;
	cout<<ans*qpow(zh(n,w),mod-2)%mod;
}