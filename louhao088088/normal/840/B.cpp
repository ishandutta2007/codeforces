// Problem: CF840B Leha and another game about graph
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF840B
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 2021-12-10 20:10:11
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
int n,m,a[maxn],rt,vis[maxn],b[maxn],ans[maxn],tot=0,x,y,s;
vector<pi>e[maxn];
void dfs(int x,int id,int fa)
{
	vis[x]=1;
	for(auto i:e[x])
		if(!vis[i.fi])
			dfs(i.fi,i.se,x);
	if(a[x]+b[x]==1)b[x]^=1,b[fa]^=1,ans[++tot]=id;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();rt=-1;
	for(int i=1;i<=n;i++)
		a[i]=read(),a[i]==-1?rt=i:s+=a[i];
	for(int i=1;i<=m;i++)
		x=read(),y=read(),e[x].push_back(mp(y,i)),e[y].push_back(mp(x,i));
	if(rt==-1&&s%2==1)cout<<"-1",exit(0);
	if(rt==-1)rt=1;dfs(rt,0,0);
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++)printf("%d\n",ans[i]);
 	return 0;
}