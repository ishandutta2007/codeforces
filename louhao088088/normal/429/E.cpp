// Problem: CF429E Points and Segments
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF429E
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 2022-03-21 19:59:44
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
int n,l,r,a[maxn],b[maxn],c[maxn],m,sum[maxn],vis[maxn],ans[maxn],tot;
vector<pi>e[maxn];
void dfs(int x)
{
	//cout<<x<<" "<<endl;
	vis[x]=1;
	for(auto i:e[x])
		if(!ans[i.se])
		{
			if(x>i.fi)ans[i.se]=2;else ans[i.se]=1;
			dfs(i.fi);
		}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),b[i]=read(),c[++tot]=a[i],c[++tot]=b[i]+1;
	sort(c+1,c+tot+1);m=unique(c+1,c+tot+1)-c-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(c+1,c+m+1,a[i])-c;
		b[i]=lower_bound(c+1,c+m+1,b[i]+1)-c;
		//cout<<a[i]<<" "<<b[i]<<endl;
		e[a[i]].pb({b[i],i});e[b[i]].pb({a[i],i});
		sum[a[i]]++;sum[b[i]]--;
	}
	tot=n;
	for(int i=1;i<m;i++)
	{
		sum[i]+=sum[i-1];
		if(sum[i]&1)e[i].pb({i+1,++tot}),e[i+1].pb({i,tot});
	}
	for(int i=1;i<=m;i++)
		if(!vis[i])dfs(i);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]-1);
 	return 0;
}