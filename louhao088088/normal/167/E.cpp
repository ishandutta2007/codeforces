#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=2005;
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
int n,m,F,a[5],sum[605][605],in2[maxn],ans,T,x,y,mod,in1[maxn],c[maxn],d[maxn],tot1=0,tot2=0,vis[maxn]; 
long long f[605][605];
vector<int>e[605];
long long Pow(long long x,int y){long long res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y=y>>1;};return res;}
void getans()
{
	long long ans=1;a[1]=tot1;
	for(int i=1;i<=a[1];i++)
	{
		if(!f[i][i])
		{
			for(int j=i+1;j<=a[1];j++)
				if(f[j][i])
				{
					ans=(mod-ans)%mod;
					swap(f[i],f[j]);
					break;
				}
		}
		int s=Pow(f[i][i],mod-2);//cout<<s<<" "<<Pow(2,5)<<endl;
		for(int j=a[1];j>i;j--)
		{
			int p=f[j][i]*s%mod;
			for(int k=a[1];k>=i;k--)
				f[j][k]=(f[j][k]-p*f[i][k]%mod+mod)%mod;
		}
			
		ans=ans*f[i][i]%mod;
		//cout<<f[i][i]<<endl;
	}
	cout<<ans<<endl;
}
void dfs(int x)
{
	vis[x]=1;
	if(!in2[x]){sum[x][x]=1;return;}
	for(auto i:e[x])
	{
		if(!vis[i])dfs(i);
		for(int j=1;j<=tot1;j++)
			sum[x][d[j]]=(sum[x][d[j]]+sum[i][d[j]])%mod;
	}
}
signed main()
{
	//freopen("sa.in","r",stdin);
	n=read();m=read();mod=read();tot1=0,tot2=0;
	for(int i=1;i<=m;i++)x=read(),y=read(),e[x].push_back(y),in2[x]=1,in1[y]=1;
	for(int i=1;i<=n;i++)
	{
		if(!in1[i])c[++tot1]=i;
		if(!in2[i])d[++tot2]=i;
	}	
	for(int i=1;i<=tot1;i++)
		dfs(c[i]);
	for(int i=1;i<=tot1;i++)
		for(int j=1;j<=tot2;j++)
			f[i][j]=sum[c[i]][d[j]];//,cout<<f[i][j]<<" ";
	//cout<<tot1<<" "<<tot2<<endl;
	//if(m==0)puts("1"),exit(0);
	getans();
 	return 0;
}