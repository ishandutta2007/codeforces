// Problem: CF771C Bear and Tree Jumps
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF771C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-12-03 21:15:27
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=2e5+5,M=34005;
#define int long long
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
int n,m,x,y,f[maxn][7],ans,siz[maxn],k,g[7];
vector<int>e[maxn];
void dfs(int x,int fa)
{
	siz[x]=1;
	for(auto i:e[x])
		if(i^fa)
		{
			dfs(i,x);siz[x]+=siz[i];
			f[x][0]+=f[i][k-1];
			for(int j=1;j<k;j++)
				f[x][j]+=f[i][j-1];
		}
	f[x][0]+=siz[x]-1;
}
void dfs2(int x,int fa)
{
	memset(g,0,sizeof g);
	if(fa)
	{
		g[0]=f[fa][0]-f[x][k-1]-siz[x];
		for(int i=1;i<k;i++)g[i]=f[fa][i]-f[x][i-1];
		for(int i=1;i<k;i++)f[x][i]+=g[i-1];
		f[x][0]+=g[k-1]+siz[1]-siz[x];
	}
	for(auto i:e[x])
		if(i^fa)
		dfs2(i,x);
		
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<n;i++)
		x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);dfs2(1,0);
	for(int i=1;i<=n;i++)
	{
		ans+=f[i][0];
	//	for(int j=0;j<=k;j++)cout<<f[i][j]<<" ";cout<<endl;
	}
	cout<<ans/2<<endl;
 	return 0;
}