// Problem: A. Find Array
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 2021-12-11 18:06:55
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
int n,T,x,y,dfn[maxn],tot,st[maxn],top,vis[maxn],id[maxn],s[maxn],tim,low[maxn];
struct node
{
	int x,y,id;
}a[maxn];
vector<int>e[maxn];
bool cmp(node a,node b){return a.x<b.x;}
bool cmp2(node a,node b){return a.y<b.y;}
void tarjan(int x)
{
	dfn[x]=low[x]=++tim;st[++top]=x;vis[x]=1;
	for(auto i:e[x])
	{
		if(!dfn[i])tarjan(i),low[x]=min(low[x],low[i]);
		else if(vis[i])low[x]=min(low[x],dfn[i]);
	}
	//cout<<dfn[x]<<" "<<low[x]<<endl;
	if(dfn[x]==low[x])
	{
		++tot;
		while(st[top]!=x)id[st[top]]=tot,s[tot]++,vis[st[top]]=0,top--;
		id[st[top]]=tot,s[tot]++,vis[st[top]]=0,top--;
	}
}
void solve()
{
	memset(dfn,0,sizeof dfn),memset(low,0,sizeof low);
	for(int i=1;i<=n;i++)e[i].clear();
	n=read();
	for(int i=1;i<=n;i++)a[i].x=read();
	for(int i=1;i<=n;i++)a[i].y=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)e[a[i+1].id].pb(a[i].id);
	sort(a+1,a+n+1,cmp2);
	int g=a[n].id;
	for(int i=1;i<n;i++)e[a[i+1].id].pb(a[i].id);
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	//for(int i=1;i<=n;i++)cout<<id[i]<<" ";
	for(int i=1;i<=n;i++)
		if(id[i]==id[g])putchar('1');else putchar('0');puts("");
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)solve();
 	return 0;
}