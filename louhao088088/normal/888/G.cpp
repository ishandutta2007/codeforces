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
int n,m,son[maxn*40][2],L[maxn*40],R[maxn*40],tot=0,a[maxn],ans;
void ins(int x,int len,int id)
{
	int now=0;
	for(int i=len;i>=0;i--)
		if((1<<i)&x)
		{
			if(!son[now][1])son[now][1]=++tot,L[tot]=id;
			now=son[now][1];R[now]=id;
		}
		else 
		{
			if(!son[now][0])son[now][0]=++tot,L[tot]=id;
			now=son[now][0];R[now]=id;
		}
}
int query(int now,int x,int len)
{
	int res=0;//cout<<now<<" "<<x<<" "<<len<<endl;
	for(int i=len;i>=0;i--)
		if((1<<i)&x)
		{
			if(!son[now][1])now=son[now][0],res+=(1<<i);
			else now=son[now][1];
		}
		else 
		{
			if(!son[now][0])now=son[now][1],res+=(1<<i);
			else now=son[now][0];
		}
	//cout<<res<<endl;
	return res;
}
int dfs(int x,int len)
{
	if(len<0) return 0;
	//cout<<son[x][0]<<" "<<son[x][1]<<endl;
	if(!son[x][0])return dfs(son[x][1],len-1);
	if(!son[x][1])return dfs(son[x][0],len-1);
	int res=1e15;
	for(int i=L[son[x][0]];i<=R[son[x][0]];i++)	
		res=min(res,query(son[x][1],a[i],len-1));
	//cout<<res<<" "<<(1<<len)<<" "<<L[son[x][0]]<<" "<<R[son[x][0]]<<" "<<endl;
	return (1<<len)+res+dfs(son[x][0],len-1)+dfs(son[x][1],len-1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)ins(a[i],30,i);
	ans=dfs(0,30);cout<<ans<<endl;
 	return 0;
}