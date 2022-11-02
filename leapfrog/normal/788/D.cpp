//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int a[20005],at,rx[10005],xt,ry[10005],yt,qw;
inline int ask(int x,int y)
{
	cout<<"0 "<<x<<" "<<y<<endl,fflush(stdout);
	int rs;read(rs);return rs;
}
inline void solve(int l,int r)
{
	int md,vl;if(l>r) return;else md=(l+r)>>1,vl=ask(md,md);
	if(!vl) a[++at]=md,solve(l,md-1),solve(md+1,r);
	else qw=md,solve(l,md-vl),solve(md+vl,r);
}
int main()
{
	solve(-100000000,100000000);for(int i=1;i<=at;i++)
	{
		if(!ask(a[i],qw)) rx[++xt]=a[i];
		if(!ask(qw,a[i])) ry[++yt]=a[i];
	}
	printf("1 %d %d\n",xt,yt);
	for(int i=1;i<=xt;i++) printf("%d%c",rx[i],i==xt?'\n':' ');
	for(int i=1;i<=yt;i++) printf("%d%c",ry[i],i==yt?'\n':' ');
	return 0;
}