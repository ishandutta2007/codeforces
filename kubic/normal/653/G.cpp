#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 1000005
#define MOD 1000000007
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
const int lim=1e6;
int n,ans,a[N],vs[N],p[N],fc[N],invF[N],s1[N],s[N],cnt[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res; 
}
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
void sieve(int n)
{
	vs[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) vs[i]=p[++p[0]]=i;
		for(int j=1;i*p[j]<=n;++j) {vs[i*p[j]]=p[j];if(!(i%p[j])) break;}
	}
}
int C(int x,int y) {return 1ll*fc[x]*invF[y]%MOD*invF[x-y]%MOD;}
int qSm(int l,int r) {return l?add(s[r],MOD-s[l-1]):s[r];}
int main()
{
	n=rd();sieve(lim);for(int i=1,x;i<=n;++i) x=rd(),++a[x];
	fc[0]=invF[0]=1;for(int i=1;i<=n;++i) fc[i]=1ll*fc[i-1]*i%MOD;
	invF[n]=qPow(fc[n],MOD-2);
	for(int i=n-1;i;--i) invF[i]=1ll*invF[i+1]*(i+1)%MOD;
	for(int i=0;i<n;++i) {s1[i]=C(n-1,i);if(i) s1[i]=add(s1[i],s1[i-1]);}
	for(int i=0;i<n;++i)
	{s[i]=add(add(MOD-s1[n-1],s1[i]),s1[i-1]);if(i) s[i]=add(s[i],s[i-1]);}
	for(int i=1,t,nw;i<=p[0];++i)
	{
		t=nw=0;cnt[0]=n;
		for(int j=p[i];;j*=p[i])
		{++t;for(int k=j;k<=lim;k+=j) cnt[t]+=a[k];if(1ll*j*p[i]>lim) break;}
		for(int j=0;j<t;++j) cnt[j]-=cnt[j+1];
		for(int j=1;j<=t;++j) cnt[j]+=cnt[j-1];
		for(int j=1;j<=t;++j) ans=(ans+1ll*qSm(cnt[j-1],cnt[j]-1)*j)%MOD;
		for(int j=0;j<=t;++j) cnt[j]=0; 
	}printf("%d\n",ans);return 0;
}