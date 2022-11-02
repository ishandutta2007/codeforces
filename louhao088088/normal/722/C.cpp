#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=2e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,f[maxn],b[maxn],a[maxn],ans,s[maxn],g[maxn],res[maxn],y;
int getf(int x)
{
	if(f[x]==x)return x;return f[x]=getf(f[x]); 
}
void gett(int x)
{
	int u=getf(x-1),v=getf(x+1);
	f[u]=v;a[v]+=a[u]+a[x];ans=max(ans,a[v]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),f[i]=i;
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=n;i>=1;i--)
	{
		res[i]=ans;g[b[i]]=1;
		if(g[b[i]-1]&&g[b[i]+1])gett(b[i]);
		else if(g[b[i]-1])y=getf(b[i]-1),f[b[i]]=f[y],a[y]+=a[b[i]],ans=max(ans,a[y]);
		else if(g[b[i]+1])y=getf(b[i]+1),f[b[i]]=f[y],a[y]+=a[b[i]],ans=max(ans,a[y]);
		else ans=max(ans,a[b[i]]);
	}
	for(int i=1;i<=n;i++)printf("%lld\n",res[i]);
 	return 0;
}