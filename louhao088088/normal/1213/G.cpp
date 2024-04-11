#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
#define int long long
inline int read() {
	int x=0;bool f=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=1;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if(f)x=-x; return x;
}
const int maxn=2e5+5;
struct node
{
	int u,v,x;
}e[maxn];
struct que
{
	int x,id;
}q[maxn];
int n,m,x,y,w,f[maxn],s[maxn],ans=0,res[maxn];
bool cmp(que a,que b)
{
	return a.x<b.x;
}
bool cmp1(node a,node b)
{
	return a.x<b.x;
}
int getf(int x)
{
	if(f[x]==x)return x;return f[x]=getf(f[x]);
}
void gett(int x,int y)
{
	x=getf(x),y=getf(y);
	if(x==y)return;
	//cout<<x<<" "<<y<<" "<<s[x]<<" "<<s[y]<<endl;
	ans+=s[x]*s[y];
	s[y]+=s[x];f[x]=y;
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
	for(int i=1;i<n;i++)e[i].u=read(),e[i].v=read(),e[i].x=read();
	sort(e+1,e+n,cmp1);
	for(int i=1;i<=m;i++)
	{
		q[i].id=i,q[i].x=read();
	}
	sort(q+1,q+m+1,cmp);int l=1;
	for(int i=1;i<=m;i++)
	{
		while(e[l].x<=q[i].x&&l<n)gett(e[l].u,e[l].v),l++;
		res[q[i].id]=ans;//cout<<l<<" "<<ans<<endl;
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",res[i]);
	return 0;
}