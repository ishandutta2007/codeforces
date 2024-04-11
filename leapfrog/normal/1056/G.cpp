//Coded by leapfrog on 2021.11.04 {{{
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
struct node{int vl,sz,ls,rs;}T[20000005];int tt,st[2000005],tp;
inline void Cpy(int &x) {int nx;if(x) T[nx=tp?st[tp--]:++tt]=T[x],x=nx;}
inline void New(int &x,int w) {T[x=tp?st[tp--]:++tt]=(node){w,1,0,0};}
inline void Del(int &x) {T[st[++tp]=x]=(node){0,0,0,0},x=0;}
inline void pushup(int x) {T[x].sz=T[T[x].ls].sz+T[T[x].rs].sz+1;}
inline void split(int x,int k,int &a,int &b)
{
	if(!x) return a=b=0,void();
	if(k<=T[T[x].ls].sz) Cpy(b=x),split(T[x].ls,k,a,T[b].ls),pushup(b);
	else Cpy(a=x),split(T[x].rs,k-T[T[x].ls].sz-1,T[a].rs,b),pushup(a);
}
mt19937 getrnd(1145141919810+19260817);
inline char rnd(int x,int y) {return (int)(getrnd())%(x+y)<x;}
inline int merge(int x,int y)
{
	if(!x||!y||!(x^y)) return x|y;
	if(rnd(T[x].sz,T[y].sz)) return Cpy(x),T[x].rs=merge(T[x].rs,y),pushup(x),x;
	else return Cpy(y),T[y].ls=merge(x,T[y].ls),pushup(y),y;
}
inline void build(int &x,int l,int r)
{
	int md;if(l>r) return;else md=(l+r)>>1,New(x,md);
	build(T[x].ls,l,md-1),build(T[x].rs,md+1,r),pushup(x);
}
inline void rebuild(int &x,int l,int r,int *a)
{
	int md;if(l>r) return;else md=(l+r)>>1,New(x,a[md]);
	rebuild(T[x].ls,l,md-1,a),rebuild(T[x].rs,md+1,r,a),pushup(x);
}
int n,m,s,rt,db[100005],cnt,dp[100005],tn[100005];ll t;
inline void pullout(int x,int *a) {if(x) pullout(T[x].ls,a),a[++cnt]=T[x].vl,pullout(T[x].rs,a);}
inline int pull(int &rt,int l,int r)
{
	int a,b,c;split(rt,r,b,c),split(b,l-1,a,b);
	return rt=merge(a,merge(b,c)),b;
}
inline int getsg(int &rt,int l,int r)
{
	if(l<=r) return pull(rt,l,r);
	return merge(pull(rt,l,n),pull(rt,1,r));
}
inline void zy(int x,int &y,int ds)
{
	int ql=ds%n+1,qr=(ds+m-1)%n+1,al=((m-ds)%n+n)%n+1,ar=((n-ds-1)%n+n)%n+1;
	y=merge(getsg(x,ql,qr),getsg(x,al,ar));
}
int main()
{
	read(n,m,s,t),build(rt,1,n);
	for(int i=1;i<n;i++)
	{
		zy(rt,rt,i);
		if(tt>19000000)
		{
			cnt=0,pullout(rt,db);
			while(tt) T[tt--]=(node){0,0,0,0};
			while(tp) st[tp--]=0;
			rebuild(rt,1,n,db);
		}
	}
	cnt=0,pullout(rt,dp);for(ll i=t,e=t/n*n+1;i>=e;i--)
		if(s<=m) s=(s+i-1)%n+1;else s=((s-i-1)%n+n)%n+1;
	//for(int i=1;i<=n;i++) printf("%d%c",dp[i],i==n?'\n':' ');
	t/=n;int go,cr;for(int x=s,i=1;;x=dp[x],i++)
		if(tn[x]) {go=tn[x],cr=tn[x]-i;break;}else tn[x]=i;
	while(t&&go) t--,go--,s=dp[s];
	t%=cr;while(t) t--,s=dp[s];
	return printf("%d\n",s),0;
}