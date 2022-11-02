#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=2e5+5,mod=1e9+7;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(long long x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
map<int,int>g[maxn];
int n,m,p[maxn],f[maxn],tot=0,sum[maxn],x,y;
long long ans=1;
void add(int y,int x)
{
	for(int i=1;i<=tot&&p[i]<=sqrt(x);i++)
	{
		if(x%p[i]==0)
		{
			x=x/p[i];if(!g[y][p[i]])sum[p[i]]++;
			g[y][p[i]]++;
			if(sum[p[i]]==n)
			{
				for(int j=1;j<=n;j++)
				{
					g[j][p[i]]--;
					if(!g[j][p[i]])sum[p[i]]--;
				}
				ans=ans*p[i]%mod;
			}
			//cout<<p[i]<<" "<<x<<endl;
			i--;
		}
	}
	if(x>1)
	{
		if(!g[y][x])sum[x]++;
		g[y][x]++;
		if(sum[x]==n)
		{
			for(int j=1;j<=n;j++)
			{
				g[j][x]--;
				if(!g[j][x])sum[x]--;
			}
			ans=ans*x%mod;
		}
		//cout<<x<<endl;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int i=2;i<=200000;i++)
	{
		if(!f[i])p[++tot]=i;
		for(int j=1;j<=tot&&p[j]*i<=200000;j++)
			f[p[j]*i]=1;
	}//cout<<tot<<endl;
	n=read(),m=read();
	for(int i=1;i<=n;i++)add(i,read());
	for(int i=1;i<=m;i++)x=read(),y=read(),add(x,y),print(ans),puts("");
 	return 0;
}