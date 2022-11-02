// Problem: CF708C Centroids
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF708C
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 2022-02-16 16:46:38
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
const int maxn=5e5+5,M=34005;
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
int sz[maxn],rt,Max[maxn][2],s[maxn],x,y,n;
vector<int>e[maxn];
void dfs(int x,int fa)
{
	sz[x]=1;int F=1;
	for(auto i:e[x])
		if(i^fa)
		{
			dfs(i,x);sz[x]+=sz[i];
			if(sz[i]>n/2)F=0;
		}
		if(n-sz[x]>n/2)F=0;
	if(F)rt=x;
}
void dfs2(int x,int fa)
{
	sz[x]=1;
	for(auto i:e[x])
		if(i^fa)
		{
			dfs2(i,x);sz[x]+=sz[i];if(sz[i]>n/2)continue;
			if(Max[x][0]<sz[i])Max[x][1]=Max[x][0],Max[x][0]=sz[i];
			else Max[x][1]=max(Max[x][1],sz[i]);
		}
}
void dfs3(int x,int fa,int sum)
{
	s[x]=sum;if(n-sz[x]<=n/2)sum=max(sum,n-sz[x]);
	for(auto i:e[x])
		if(i^fa)
		{
			
			if(Max[x][0]!=sz[i])dfs3(i,x,max(sum,Max[x][0]));
			else dfs3(i,x,max(sum,Max[x][1]));
		}
} 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)x=read(),y=read(),e[x].pb(y),e[y].pb(x);
	dfs(1,0);dfs2(rt,0),dfs3(rt,0,0);
	for(int i=1;i<=n;i++)
		if(n-sz[i]-s[i]<=n/2)printf("1 ");
		else printf("0 ");
 	return 0;
}