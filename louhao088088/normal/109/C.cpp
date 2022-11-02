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
int n,m,f[maxn],g[maxn],s[maxn],x,y,z,ans;
vector<pi>e[maxn];
bool check(int x)
{
	while(x)
	{
		if(x%10!=4&&x%10!=7)return false;x=x/10;
	}return true;
}
void dfs(int x,int fa)
{
	s[x]=1;
	for(auto i:e[x])
		if(i.fi^fa)
		{
			dfs(i.fi,x);
			if(check(i.se))f[x]+=s[i.fi];
			else f[x]+=f[i.fi];
			s[x]+=s[i.fi];
		}
}
void dfs2(int x,int fa)
{
	for(auto i:e[x])
		if(i.fi^fa)
		{
			
			if(check(i.se))f[i.fi]+=s[1]-s[i.fi];
			else f[i.fi]=f[x];
			dfs2(i.fi,x);
		}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)x=read(),y=read(),z=read(),e[x].pb(mp(y,z)),e[y].pb(mp(x,z));
	dfs(1,0);dfs2(1,0);
	for(int i=1;i<=n;i++)ans+=f[i]*(f[i]-1);
	cout<<ans;
 	return 0;
}