//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int ls,rs,sz;ll sm;}t[10000005];int tt,rt,n,m,a[1000005];
inline void upd(int &x,ll l,ll r,ll dw,int dc)
{
	t[x?x:x=++tt].sz+=dc,t[x].sm+=dc*dw;if(l==r) return;
	if(dw<=((l+r)>>1)) upd(t[x].ls,l,(l+r)>>1,dw,dc);else upd(t[x].rs,((l+r)>>1)+1,r,dw,dc);
}
inline double get(int x,ll l,ll r,ll rst)
{
	int sz=0;ll fz=0;while(l^r)
	{
		double md=(l+r)>>1;if(rst<md*(sz+t[t[x].ls].sz)-fz-t[t[x].ls].sm) r=md,x=t[x].ls;
		else fz+=t[t[x].ls].sm,sz+=t[t[x].ls].sz,l=md+1,x=t[x].rs;
	}
	return l+(rst-(l*(sz+t[t[x].ls].sz)-fz-t[t[x].ls].sm))*1.0/sz;
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]),upd(rt,0,1e13,a[i],1);
	ll z;for(int i=1,op,x,y;i<=m;i++)
	{
		read(op);if(op&1) read(x),read(y),upd(rt,0,1e13,a[x],-1),a[x]=y,upd(rt,0,1e13,a[x],1);
		else read(z),printf("%.10lf\n",get(rt,0,1e13,z));
	}
	return 0;
}