#include <bits/stdc++.h>
using namespace std;
#define N 10000005
#define MOD 998244353
const int lim=1e7,inv2=499122177;
int T,n,m,c,pwN,ans,pw[N],invPw[N],w[N],s[N],invW[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
void slv()
{
	scanf("%d %d %d",&n,&m,&c);ans=1;
	if(!c)
	{
		if(n>m) {puts("0");return;}
		for(int i=0;i<n;++i) ans=1ll*ans*add(pw[m],MOD-pw[i])%MOD;
		printf("%d\n",ans);return;
	}pwN=qPow(2,n);
	for(int i=1,t=1,t1=1;i<m;++i)
	{
		t=1ll*t*add(pw[m],MOD-pw[i])%MOD;
		t1=1ll*t1*add(1ll*pwN*invPw[i-1]%MOD,MOD-1)%MOD;
		t1=1ll*t1*invW[i]%MOD;ans=add(ans,1ll*t*t1%MOD);
	}printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);pw[0]=invPw[0]=s[0]=1;
	for(int i=1;i<=lim;++i)
		pw[i]=add(pw[i-1],pw[i-1]),w[i]=add(pw[i],MOD-1);
	for(int i=1;i<=lim;++i) invPw[i]=1ll*invPw[i-1]*inv2%MOD;
	for(int i=1;i<=lim;++i) s[i]=1ll*s[i-1]*w[i]%MOD;
	invW[lim]=qPow(s[lim],MOD-2);
	for(int i=lim-1;i;--i) invW[i]=1ll*invW[i+1]*w[i+1]%MOD;
	for(int i=1;i<=lim;++i) invW[i]=1ll*invW[i]*s[i-1]%MOD;
	while(T--) slv();return 0;
}