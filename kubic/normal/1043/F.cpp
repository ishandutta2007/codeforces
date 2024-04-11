#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define LIM 1000005
#define MOD1 1000000007
#define MOD2 1000000009
#define ull unsigned long long
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const int lim=3e5;
char *P1,*P2,buf[LIM];
int n,m,a[N],fc1[N],fc2[N],invF1[N],invF2[N],ans1[N],ans2[N],dp1[N][8],dp2[N][8];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res; 
}
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int add1(int x,int y) {x+=y;return x<MOD1?x:x-MOD1;}
int add2(int x,int y) {x+=y;return x<MOD2?x:x-MOD2;}
int qPow1(int x,int y)
{int res=1;for(;y;y/=2,x=1ll*x*x%MOD1) if(y&1) res=1ll*res*x%MOD1;return res;}
int qPow2(int x,int y)
{int res=1;for(;y;y/=2,x=1ll*x*x%MOD2) if(y&1) res=1ll*res*x%MOD2;return res;}
int C1(int x,int y) {return x<y?0:1ll*fc1[x]*invF1[y]%MOD1*invF1[x-y]%MOD1;}
int C2(int x,int y) {return x<y?0:1ll*fc2[x]*invF2[y]%MOD2*invF2[x-y]%MOD2;}
int main()
{
	n=rd();for(int i=1,x;i<=n;++i) x=rd(),++a[x];
	for(int i=1;i<=lim;++i) ans1[i]=ans2[i]=-1;
	fc1[0]=invF1[0]=fc2[0]=invF2[0]=1;
	for(int i=1;i<=lim;++i) fc1[i]=1ll*fc1[i-1]*i%MOD1,fc2[i]=1ll*fc2[i-1]*i%MOD2;
	invF1[lim]=qPow1(fc1[lim],MOD1-2);invF2[lim]=qPow2(fc2[lim],MOD2-2);
	for(int i=lim-1;i;--i)
		invF1[i]=1ll*invF1[i+1]*(i+1)%MOD1,invF2[i]=1ll*invF2[i+1]*(i+1)%MOD2;
	for(int i=1,cnt,t;i<=lim;++i)
	{
		cnt=t=0;for(int j=i;j<=lim;j+=i) if(a[j]) cnt+=a[j],t=gcd(t,j);
		if(t==i) ans2[i]=cnt;
	}
	for(int i=lim,cnt;i;--i)
	{
		cnt=0;for(int j=i;j<=lim;j+=i) if(a[j]) ++cnt;
		for(int j=1;j<8;++j)
		{
			dp1[i][j]=C1(cnt,j);dp2[i][j]=C2(cnt,j);
			for(int k=i*2;k<=lim;k+=i)
			{
				dp1[i][j]=add1(dp1[i][j],MOD1-dp1[k][j]);
				dp2[i][j]=add2(dp2[i][j],MOD2-dp2[k][j]);
			}if(ans1[i]==-1 && dp1[i][j] && dp2[i][j]) ans1[i]=j;
		}
	}printf("%d\n",ans1[1]);return 0;
}