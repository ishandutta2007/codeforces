// Problem: CF337D Book of Evil
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF337D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-12-03 20:08:22
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
const int maxn=1e5+5,M=34005;
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
int n,m,dis1[maxn],dis2[maxn],flag[maxn],g,id,a,b,ans,x,y,d;
vector<int>e[maxn];
void dfs(int x,int fa,int dis)
{
	if(g<dis&&flag[x]){id=x;g=dis;}
	for(auto i:e[x])
		if(i^fa)
			dfs(i,x,dis+1);
}
void dfsa(int x,int fa,int dis)
{
	//cout<<x<<" "<<dis<<endl;
	dis1[x]=dis;
	for(auto i:e[x])
		if(i^fa)
			dfsa(i,x,dis+1);
}
void dfsb(int x,int fa,int dis)
{
	//cout<<x<<" "<<dis<<endl;
	dis2[x]=dis;
	for(auto i:e[x])
		if(i^fa)
			dfsb(i,x,dis+1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();d=read();
	for(int i=1;i<=m;i++)x=read(),flag[x]=1;
	for(int i=1;i<n;i++)
		x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	for(int i=1;i<=n;i++)
		if(flag[i])
		{
			dfs(i,0,1);a=id;g=0;
			dfs(id,0,1);b=id;
			break;
		}
	//cout<<a<<" "<<b<<endl;
	dfsa(a,0,0);
	dfsb(b,0,0);
	//for(int i=1;i<=n;i++)cout<<dis1[i]<<" "<<dis2[i]<<endl;
	for(int i=1;i<=n;i++)if(dis1[i]<=d&&dis2[i]<=d)ans++;
	cout<<ans<<endl;
 	return 0;
}