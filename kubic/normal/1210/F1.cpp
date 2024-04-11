#include <bits/stdc++.h>
using namespace std;
#define N 105
#define M 1<<20
#define MOD 1000000007
int n,tp,tp1,ans,st[N],id[N],st1[N],f1[M],f2[M],a[N][N];
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
bool chk(int x,int y)
{
	tp1=0;for(int i=0;i<6;++i) if(y>>i&1) st1[tp1++]=i;
	if(x>>st1[0]&1 && x>>6+st1[1]&1 && x>>12+st1[2]&1) return 1;
	if(x>>st1[0]&1 && x>>6+st1[2]&1 && x>>12+st1[1]&1) return 1;
	if(x>>st1[1]&1 && x>>6+st1[0]&1 && x>>12+st1[2]&1) return 1;
	if(x>>st1[1]&1 && x>>6+st1[2]&1 && x>>12+st1[0]&1) return 1;
	if(x>>st1[2]&1 && x>>6+st1[0]&1 && x>>12+st1[1]&1) return 1;
	if(x>>st1[2]&1 && x>>6+st1[1]&1 && x>>12+st1[0]&1) return 1;
	return 0;
}
void FWT_and(bool fl,int a[])
{
	for(int i=1;i<1<<20;i*=2) for(int j=0;j<1<<20;j+=i*2)
		for(int k=0;k<i;++k) W(a[j+k],fl?MOD-a[i+j+k]:a[i+j+k]);
}
int main()
{
	scanf("%d",&n);ans=1;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j)
		scanf("%d",&a[i][j]);for(int i=n;i<6;++i) a[i][i]=100;
	for(int i=0,t=0;i<64;++i,t=0)
	{for(int j=0;j<6;++j) t+=i>>j&1;if(t==3) st[id[i]=tp++]=i;}
	for(int i=0,t=0,w=1;i<1<<18;++i,t=0,w=1)
	{
		for(int j=0;j<3;++j) for(int k=0;k<6;++k)
			if(i>>j*6+k&1) w=1ll*w*a[j][k]%MOD;
			else w=1ll*w*(100-a[j][k])%MOD;
		for(int j=0;j<20;++j)
			if(chk(i,st[j])) t|=1<<j;W(f1[t],w);
	}
	for(int i=0,t=0,w=1;i<1<<18;++i,t=0,w=1)
	{
		for(int j=0;j<3;++j) for(int k=0;k<6;++k)
			if(i>>j*6+k&1) w=1ll*w*a[3+j][k]%MOD;
			else w=1ll*w*(100-a[3+j][k])%MOD;
		for(int j=0;j<20;++j)
			if(chk(i,st[j])) t|=1<<id[st[j]^63];W(f2[t],w);
	}FWT_and(0,f1);FWT_and(0,f2);
	for(int i=0;i<1<<20;++i) f1[i]=1ll*f1[i]*f2[i]%MOD;
	FWT_and(1,f1);ans=MOD-1ll*f1[0]*qPow(100,MOD-37)%MOD;
	W(ans,1);printf("%d\n",ans);return 0;
}