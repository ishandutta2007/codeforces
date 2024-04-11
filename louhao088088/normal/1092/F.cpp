// Problem: CF1092F Tree with Maximum Cost
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1092F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-12-15 20:48:52
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
#define int long long
const int maxn=2e5+5,M=34005;
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
int n,m,x,a[maxn],y,s[maxn],d[maxn],ans[maxn],Max;
vector<int>e[maxn];
void dfs(int x,int fa)
{
	s[x]=a[x];d[x]=d[fa]+1;ans[1]+=a[x]*d[fa];
	for(auto i:e[x])
		if(i^fa)
			dfs(i,x),s[x]+=s[i];
}
void dfs1(int x,int fa)
{
	for(auto i:e[x])
		if(i^fa)
		{
			ans[i]=ans[x]-s[i]+s[1]-s[i];
			dfs1(i,x);
		}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);dfs1(1,0);
	for(int i=1;i<=n;i++)Max=max(Max,ans[i]);cout<<Max;
 	return 0;
}