//Coded by Kamiyama_Shiki on 2021.11.09 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=1000005;int n,q;ll p,a[N];
struct segm{vector<ll>v;ll sm;int ln;}T[N<<2];
inline void pushup(int x)
{
	int ls=x<<1,rs=x<<1|1;T[x].sm=T[ls].sm+T[rs].sm;
	T[x].v.resize(T[x].ln+2),T[x].v[0]=-1e18;
	for(int i=1;i<=T[x].ln+1;i++) T[x].v[i]=1e18;
	for(int il=0,ir=0;il<=T[ls].ln;il++)
	{
		if(ir>T[rs].ln) ir--;
		for(;ir<=T[rs].ln;ir++)
		{
			ll nw=T[rs].v[ir]+il*p-T[ls].sm;
			if(T[ls].v[il+1]-1-il*p+T[ls].sm<T[rs].v[ir]) {ir?ir--:0;break;}
			T[x].v[il+ir]=min(T[x].v[il+ir],max(T[ls].v[il],nw));
		}
	}
}
inline void build(int x,int l,int r)
{
	T[x].ln=r-l+1;if(l^r) build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
	else T[x].sm=a[l],T[x].v.resize(3),T[x].v[0]=-1e18,T[x].v[1]=p-a[l],T[x].v[2]=1e18;
}
inline int fndps(vector<ll>&v,ll w) {return upper_bound(v.begin(),v.end(),w)-v.begin()-1;}
inline ll query(int x,int l,int r,int dl,int dr,ll dc)
{
	int md=(l+r)>>1;if(dl<=l&&r<=dr) return dc+T[x].sm-p*fndps(T[x].v,dc);
	if(dr<=md) return query(x<<1,l,md,dl,dr,dc);
	else if(dl>md) return query(x<<1|1,md+1,r,dl,dr,dc);
	else return query(x<<1|1,md+1,r,dl,dr,query(x<<1,l,md,dl,dr,dc));
}
int main()
{
	read(n,q,p);for(int i=1;i<=n;i++) read(a[i]);
	build(1,1,n);for(int l,r;q--;) read(l,r),printf("%lld\n",query(1,1,n,l,r,0));
	return 0;
}