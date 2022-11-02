#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define fi first
#define se second 
#define mp make_pair
const int maxn=2e5+5,M=455;
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
int n,m,a[maxn],b[maxn],c[M][M],op,t,ans=0,f[maxn],g[maxn],x;
vector<pair<int,int>>d[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();t=sqrt(m);
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
	for(int i=1;i<=m;i++)
	{
		op=read();x=read(); 
		if(op==1)
		{
			if(a[x]+b[x]>t)
			{
				f[x]=i;
				for(int j=i;j<=m;)
				{
					j+=a[x];
					if(j>m)break;g[j]++;
					j+=b[x];
					if(j>m)break;g[j]--;
				}
			}
			else
			{
				f[x]=i;
				int u=a[x]+b[x];
				c[u][i%u]--;c[u][(i+a[x])%u]++;ans++;
			} 
		}
		else
		{
			int u=a[x]+b[x];
			int h=i-f[x];
			if(h%u>a[x])ans--;
			if(h%u==0)ans--;
			if(a[x]+b[x]>t)
			{
				for(int j=f[x];j<=m;)
				{
					j+=a[x];
					if(j>m)break;g[j]--;
					j+=b[x];
					if(j>m)break;g[j]++;
				}	
			}
			else
			{
				c[u][f[x]%u]++,c[u][(f[x]+a[x])%u]--;
				
			}
		}
		ans+=g[i];
		for(int j=1;j<=t;j++)
		{
			ans+=c[j][i%j];
		}
		printf("%d\n",ans);
	} 
 	return 0;
}