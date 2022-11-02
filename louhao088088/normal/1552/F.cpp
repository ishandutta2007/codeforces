#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define int long long
const int maxn=2e5+5,M=34005,mod=998244353;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,f[maxn],x[maxn],y[maxn],ans,sum[maxn],s;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();s=read();
		int u=lower_bound(x+1,x+i+1,y[i])-x;
		f[i]=x[i]-y[i]+sum[i-1]-sum[u-1];ans=ans+x[i]-x[i-1];
		f[i]=f[i]%mod+mod;f[i]%=mod;
		if(s==1)ans+=f[i];sum[i]=sum[i-1]+f[i];
		sum[i]=sum[i]%mod;ans=ans%mod;
	}ans++;
	ans=ans%mod;
	cout<<ans<<endl;
 	return 0;
}