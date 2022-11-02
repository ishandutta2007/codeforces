#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename...A>inline void read(T &x,A&...a) {read(x),read(a...);}
struct node{int vl,sz,ls,rs;}t[200005];
int rt,n,k,a[200005],tt=0,res=0;
inline char Rnd(int a,int b) {return rand()%(a+b)<a;}
inline void upd(int x) {t[x].sz=t[t[x].ls].sz+t[t[x].rs].sz+1;}
inline int fndl(int x) {return t[x].ls?fndl(t[x].ls):t[x].vl;}
inline int fndr(int x) {return t[x].rs?fndr(t[x].rs):t[x].vl;}
inline void split(int x,int k,int &a,int &b)
{
	if(!x) return(void)(a=b=0);
	if(t[x].vl<=k) a=x,split(t[x].rs,k,t[x].rs,b),upd(x);
	else b=x,split(t[x].ls,k,a,t[x].ls),upd(x);
}
inline void splt(int x,int k,int &a,int &b)
{
	if(!x) return(void)(a=b=0);
	if(k<=t[t[x].ls].sz) b=x,splt(t[x].ls,k,a,t[x].ls),upd(x);
	else a=x,splt(t[x].rs,k-t[t[x].ls].sz-1,t[x].rs,b),upd(x);
}
inline int mrg(int a,int b)
{
	if(!a||!b) return a+b;else if(!(a^b)) return a;
	if(Rnd(t[a].sz,t[b].sz)) return t[a].rs=mrg(t[a].rs,b),upd(a),a;
	else return t[b].ls=mrg(a,t[b].ls),upd(b),b;
}
inline void ins(int x) {int r1,r2;split(rt,x,r1,r2),t[++tt]=(node){x,1,0,0},rt=mrg(mrg(r1,tt),r2);}
inline void del(int x) {int r1,r2,r3;split(rt,x-1,r1,r2),split(r2,x,r2,r3),r2=mrg(t[r2].ls,t[r2].rs),rt=mrg(mrg(r1,r2),r3);}
inline int rnk(int x) {int r1,r2,r;return split(rt,x-1,r1,r2),r=t[r1].sz,rt=mrg(r1,r2),r;}
inline int kth(int x) {int r1,r2,r;return splt(rt,x-1,r1,r2),r=fndl(r2),rt=mrg(r1,r2),r;}
inline int lst(int x) {int r1,r2,r;return split(rt,x-1,r1,r2),r=fndr(r1),rt=mrg(r1,r2),r;}
inline int nxt(int x) {int r1,r2,r;return split(rt,x,r1,r2),r=fndl(r2),rt=mrg(r1,r2),r;}
signed main()
{
	read(n,k),rt=tt=0,ins(0);for(int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;i++) res+=i-rnk(a[i]-k+1),ins(a[i]);
	return printf("%lld\n",res),0;
}