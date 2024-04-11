//
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
//#define int ll
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int sz,ls,rs;ll vl,lk,lb;unsigned key;}t[500005];int rt,tt,n,a[500005];
inline void pushup(int x) {t[x].sz=t[t[x].ls].sz+t[t[x].rs].sz+1;}
inline void allc(int x,ll k,ll b) {if(x) t[x].lk+=k,t[x].lb+=b,t[x].vl+=k*(1+t[t[x].ls].sz)+b;}
inline void pushdw(int x) {if(t[x].lk||t[x].lb) allc(t[x].ls,t[x].lk,t[x].lb),allc(t[x].rs,t[x].lk,t[x].lb+t[x].lk*(t[t[x].ls].sz+1)),t[x].lk=t[x].lb=0;}
mt19937 getrnd(time(0));inline unsigned rnd() {return getrnd();}
inline void split(int x,int k,int &a,int &b)
{
	if(!x) return a=b=0,void();else pushdw(x);
	if(k<=t[t[x].ls].sz) b=x,split(t[x].ls,k,a,t[b].ls),pushup(b);
	else a=x,split(t[x].rs,k-t[t[x].ls].sz-1,t[a].rs,b),pushup(a);
}
inline int mrg(int x,int y)
{
	if(!x||!y||!(x^y)) return x|y;else pushdw(x),pushdw(y);
	if(t[x].key<t[y].key) return t[x].rs=mrg(t[x].rs,y),pushup(x),x;
	else return t[y].ls=mrg(x,t[y].ls),pushup(y),y;
}
inline void paint(int x) {if(x) pushdw(x),paint(t[x].ls),printf("%lld ",t[x].vl),paint(t[x].rs);}
inline ll getK(int x,int k) {return pushdw(x),k<=t[t[x].ls].sz?getK(t[x].ls,k):(k>t[t[x].ls].sz+1?getK(t[x].rs,k-t[t[x].ls].sz-1):t[x].vl);}
inline void ins(int k,ll w) {int a,b;split(rt,k,a,b),rt=mrg(a,mrg((t[++tt]=(node){1,0,0,w,0,0,rnd()},tt),b));}//k+1
inline void mdf(int k,ll p,ll q) {int a,b;split(rt,k,a,b),allc(b,p,q),rt=mrg(a,b);}//(k,n]
inline ll getm(int x) {return x?(pushdw(x),max(max(getm(t[x].ls),getm(t[x].rs)),t[x].vl)):0;}
signed main()
{
	read(n),rt=tt=1,t[1]=(node){1,0,0,0,0,0,rnd()};for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	{
		int le=0,ri=i-2,rs=i-1;
		while(le<=ri) {int md=(le+ri)>>1;if(getK(rt,md+1)+1ll*(md+1)*a[i]>getK(rt,md+2)) rs=md,ri=md-1;else le=md+1;}
		ll qwq=getK(rt,rs+1);ins(rs+1,qwq),mdf(rs+1,a[i],1ll*a[i]*rs);
	}
	return printf("%lld\n",getm(rt)),0;
}