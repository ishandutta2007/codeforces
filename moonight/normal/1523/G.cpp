#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define gc getchar()
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,V) for(int i=0;i<V.size();++i) 
#define vi vector<int>
#define ls lc[x],l,m
#define rs rc[x],m+1,r
inline int rd()
{
	int x=0,w=1;char c=gc;
	while(c!='-'&&!isdigit(c))c=gc;
	if(c=='-')w=-1,c=gc;
	while(isdigit(c))x=x*10+c-'0',c=gc;
	return x*w;
}
const int N=100005;
int n,K,ans,res[N];
struct st{int l,r,t,o;}a[N];
inline bool cmp(const st&a,const st&b){return a.t>b.t;}
namespace T1
{
	const int M=40000005;
	int cc,lc[M],rc[M],mn[M];
	inline void cov(int x,int v){if(a[mn[x]].o>a[v].o)mn[x]=v;}
	void upd(int&x,int l,int r,int p,int v)
	{
		if(!x)x=++cc;cov(x,v);if(l==r)return;
		int m=l+r>>1;p<=m?upd(ls,p,v):upd(rs,p,v);
	}
	int qry(int x,int l,int r,int tl,int tr)
	{
		if(!x||tr<l||tl>r)return 0;
		if(tl<=l&&r<=tr)return mn[x];
		int m=l+r>>1,lo=qry(ls,tl,tr),ro=qry(rs,tl,tr);
		return a[lo].o<a[ro].o?lo:ro;
	}
}
namespace T2
{
	int rt[N*2];
	void upd(int x,int l,int r,int pl,int pr,int v)
	{
		T1::upd(rt[x],1,n,pr,v);if(l==r)return;int m=l+r>>1;
		pl<=m?upd(x<<1,l,m,pl,pr,v):upd(x<<1|1,m+1,r,pl,pr,v);
	}
	int qry(int x,int l,int r,int tl,int tr,int v)
	{
		if(tl<=l&&r<=tr)return T1::qry(rt[x],1,n,1,v);if(tr<l||tl>r)return 0;int m=l+r>>1;
		int lo=qry(x<<1,l,m,tl,tr,v),ro=qry(x<<1|1,m+1,r,tl,tr,v);return a[lo].o<a[ro].o?lo:ro;
	}
}
inline void Ins(int l,int r,int p){T2::upd(1,1,n,l,r,p);}
inline int Qry(int l,int r){return T2::qry(1,1,n,l,n,r);}
inline void sol(int l,int r,int t)
{
	if(r-l+1<t)return;int id=Qry(l,r);if(!id)return;
	ans+=a[id].t;sol(l,a[id].l-1,t);sol(a[id].r+1,r,t);
}
int main()
{
	n=rd();K=rd();a[0].o=K+1;
	rep(i,1,K)a[i].l=rd(),a[i].r=rd(),a[i].t=a[i].r-a[i].l+1,a[i].o=i;
	sort(a+1,a+K+1,cmp);int p=1;
	per(i,n,1) 
	{
		while(p<=K&&a[p].t==i){Ins(a[p].l,a[p].r,p);p++;}
		ans=0;sol(1,n,i);res[i]=ans;
	}
	rep(i,1,n)printf("%d\n",res[i]);
	return 0;
}