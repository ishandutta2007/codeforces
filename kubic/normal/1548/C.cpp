#include <bits/stdc++.h>
using namespace std;
#define N 4000005
#define MOD 1000000007
const int lim=4e6;
int n,m,fc[N],invF[N],f[N],g[N];
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res; 
}
int C(int x,int y) {return x<y?0:1ll*fc[x]*invF[y]%MOD*invF[x-y]%MOD;}
int main()
{
	scanf("%d %d",&n,&m);fc[0]=invF[0]=1;
	for(int i=1;i<=lim;++i) fc[i]=1ll*fc[i-1]*i%MOD;
	invF[lim]=qPow(fc[lim],MOD-2);
	for(int i=lim-1;i;--i) invF[i]=1ll*invF[i+1]*(i+1)%MOD;
	for(int i=0;i<=n*3+2;++i) f[i]=C(n*3+3,i+1);
	for(int i=n*3;i>=0;--i)
	{
		g[i]=f[i+2];f[i+2]=0;
		f[i]=(f[i]-3ll*g[i])%MOD;
		f[i+1]=(f[i+1]-3ll*g[i])%MOD;
	}for(int i=1,x;i<=m;++i) scanf("%d",&x),printf("%d\n",(g[x]+MOD)%MOD);
	return 0;
}