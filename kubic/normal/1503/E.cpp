#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define MOD 998244353
const int lim=5e3;
int n,m,ans,fc[N],invF[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
int f(int x,int y) {return 1ll*fc[x+y]*invF[x]%MOD*invF[y]%MOD;}
int main()
{
	scanf("%d %d",&n,&m);fc[0]=invF[0]=1;
	for(int i=1;i<=lim;++i) fc[i]=1ll*fc[i-1]*i%MOD;
	invF[lim]=qPow(fc[lim],MOD-2);
	for(int i=lim-1;i;--i) invF[i]=1ll*invF[i+1]*(i+1)%MOD;
	for(int i=1,t;i<n;++i) for(int j=1,t=0;j<m;++j)
	{
		t=add(t,1ll*f(i,j-1)*f(i-1,m-j)%MOD);
		ans=add(ans,1ll*f(n-i-1,j)*f(n-i,m-j-1)%MOD*t%MOD);
	}
	for(int i=1,t;i<m;++i) for(int j=1,t=0;j<n;++j)
	{
		ans=add(ans,1ll*f(m-i-1,j)*f(m-i,n-j-1)%MOD*t%MOD);
		t=add(t,1ll*f(i,j-1)*f(i-1,n-j)%MOD);
	}printf("%d\n",ans*2%MOD);return 0;
}