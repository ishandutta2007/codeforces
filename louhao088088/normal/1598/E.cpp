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
const int maxn=1e3+5,M=34005;
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
int n,m,f[maxn][maxn],x,y,g[maxn][maxn],tx,ty,q,ans=0;
int get(int x,int y)
{
	if(x==y)
	{
		return (2*x-1)*2-1;
	}
	else
	{
		if(x>y)swap(x,y);
		return 2*x+2*x-2;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			g[i][j]=1;
			f[i][j]=get(n-i+1,m-j+1);
			ans+=f[i][j];
		}
	//cout<<ans<<endl;
	for(int i=1;i<=q;i++)
	{
		x=read(),y=read();tx=x,ty=y;int sum=0,sum2=0;
		if(g[x][y]==1)
		{
			g[x][y]=0;sum++;ans-=f[x][y];f[x][y]=0;
			for(int a1=1,a2=0;;a1^=1,a2^=1)
			{
				tx+=a1,ty+=a2;
				if(!g[tx][ty])break;
				sum++;	
			}tx=x,ty=y;sum2++;
			for(int a1=0,a2=1;;a1^=1,a2^=1)
			{
				tx-=a1,ty-=a2;
				if(!g[tx][ty])break;
				f[tx][ty]-=sum;ans-=sum;
			}
			tx=x,ty=y;sum=0;sum++;
			for(int a1=0,a2=1;;a1^=1,a2^=1)
			{
				tx+=a1,ty+=a2;
				if(!g[tx][ty])break;
				sum++;	
			}tx=x,ty=y;sum2++;
			for(int a1=1,a2=0;;a1^=1,a2^=1)
			{
				tx-=a1,ty-=a2;
				if(!g[tx][ty])break;
				f[tx][ty]-=sum;ans-=sum;
			}
		}
		else if(g[x][y]==0)
		{
			g[x][y]=1;sum++;
			for(int a1=1,a2=0;;a1^=1,a2^=1)
			{
				tx+=a1,ty+=a2;
				if(!g[tx][ty])break;
				sum++;	
			}tx=x,ty=y;sum2++;
			for(int a1=0,a2=1;;a1^=1,a2^=1)
			{
				tx-=a1,ty-=a2;
				if(!g[tx][ty])break;
				f[tx][ty]+=sum;ans+=sum;
			}ans+=sum;f[x][y]+=sum;
			tx=x,ty=y;sum=0;sum++;
			for(int a1=0,a2=1;;a1^=1,a2^=1)
			{
				tx+=a1,ty+=a2;
				if(!g[tx][ty])break;
				sum++;	
			}tx=x,ty=y;sum2++;
			for(int a1=1,a2=0;;a1^=1,a2^=1)
			{
				tx-=a1,ty-=a2;
				if(!g[tx][ty])break;
				f[tx][ty]+=sum;ans+=sum;
			}ans+=sum-1;f[x][y]+=sum-1;
		}printf("%lld\n",ans);
		
	}
 	return 0;
}