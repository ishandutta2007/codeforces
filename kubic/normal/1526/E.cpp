#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define MOD 998244353
const int lim=5e5;
int n,m,cnt,fc[N],invF[N],a[N],ps[N];
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
int C(int x,int y)
{return x<y?0:1ll*fc[x]*invF[y]%MOD*invF[x-y]%MOD;} 
int main()
{
	scanf("%d %d",&n,&m);fc[0]=invF[0]=1;
	for(int i=1;i<=lim;++i) fc[i]=1ll*fc[i-1]*i%MOD;
	invF[lim]=qPow(fc[lim],MOD-2);
	for(int i=lim-1;i;--i) invF[i]=1ll*invF[i+1]*(i+1)%MOD;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),++a[i],ps[a[i]]=i;
	for(int i=1;i<n;++i) if(ps[a[i]+1]<ps[a[i+1]+1]) ++cnt;
	printf("%d\n",C(m+cnt,n));return 0;
}