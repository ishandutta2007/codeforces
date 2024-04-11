#include<bits/stdc++.h>
using namespace std;
#define re register
#define ui unsigned int
#define ull unsigned long long
const ui mod=998244353;
ui f[2510][2510],ex[2510],bl[2510][2510],tt[2510],n,cl[2510],cm;
char Bs[1<<22],*Ss=Bs,*Ts=Bs;
#define getchar()(Ss==Ts&&(Ts=(Ss=Bs)+fread(Bs,1,1<<22,stdin),Ss==Ts)?EOF:*Ss++)
inline ui r()
{
	re ui a=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())a=a*10+c-'0';
	return a;
}
ui ff[2510],ff1[2510];
void ad(re ui a){for(;a<=n;a+=(a&-a))ff[a]++;}
ui sm(re ui a){re ui mm=0;for(;a;a-=(a&-a))mm+=ff[a];return mm;}
ui scm(re ui a){re ui mm=0;for(;a;a-=(a&-a))mm+=ff1[a];return mm;}
void add(re ui a)
{
	if((++cl[a])==2){cm++;for(;a<=n;a+=(a&-a))ff1[a]++;}
}
int main()
{
	re ui ans=0,x,y,z,v;f[0][0]=1;n=r();
	for(re ui i=1;i<=n;i++)
	{
		f[i][0]=(ull)f[i-1][0]*i%mod;
		for(re ui j=1;j<=i;j++)
		{
			f[i][j]=(f[i][j-1]>f[i-1][j-1]?f[i][j-1]-f[i-1][j-1]:(f[i][j-1]+mod-f[i-1][j-1]));
		}
	}ex[0]=1;
	for(re ui i=1;i<=n;i++)ex[i]=(ull)ex[i-1]*f[n][n]%mod;
	for(re ui i=1;i<=n;i++)for(re ui j=1;j<=n;j++)bl[i][j]=r();
	for(re ui i=1;i<=n;i++)
	{
		ad(bl[1][i]);x=sm(bl[1][i]);
		ans=(ans+(ull)f[n-i][0]*(bl[1][i]-x)%mod*ex[n-1])%mod;
	}
	for(re ui i1=2;i1<=n;i1++)
	{
		memset(ff,0,sizeof(ff));memset(cl,0,sizeof(cl));memset(ff1,0,sizeof(ff1));
		v=cm=0;
		for(re ui i=n;i;i--)
		{
			ad(bl[i1][i]);add(bl[i1][i]);add(bl[i1-1][i]);
			y=scm(bl[i1][i]-1);x=sm(bl[i1][i]-1)-y;z=cm;
			if(cl[bl[i1-1][i]]==2){z--;if(bl[i1-1][i]<bl[i1][i])y--;}
			if(x)v=(v+(ull)x*f[n-i][z])%mod;
			if(y)v=(v+(ull)y*f[n-i][z-1])%mod;
		}
		ans=(ans+(ull)v*ex[n-i1])%mod;
	}
	printf("%d\n",ans);
}