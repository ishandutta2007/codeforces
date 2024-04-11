#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,x,f[(1<<22)+1],g[(1<<22)+1],m,s,ans,T;
int Pow(int x,int y){int res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y>>=1;}return res;}
int getnum(int x){int num=0;while(x){if(x&1)num++;x>>=1;}return num;}
signed main()
{
	n=read();memset(f,0,sizeof f);
	s=pow(2,21)-1;ans=0;
	for(int i=1;i<=n;i++)x=read(),f[x]++;
	for(int i=0;i<21;i++)
		for(int j=0;j<=s;j++)
			if(!(j&(1<<i)))
				f[j]=(f[j^(1<<i)]+f[j])%mod;
	for(int j=0;j<=s;j++)
		g[j]=Pow(2,f[j])-1,g[j]=(g[j]+mod)%mod;
	for(int i=0;i<=s;i++)ans=(ans+((getnum(i)&1)?-1:1)*g[i]+mod)%mod;
	printf("%lld\n",ans);
}