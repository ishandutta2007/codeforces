//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
struct node{ll sm;int vl,sz,ls,rs;}T[200005];int tt,rt,K=0;
mt19937 rnd(time(0));inline char Rnd(int a,int b) {return (int)rnd()%(a+b)<a;}
inline void pushup(int x) {T[x].sz=T[T[x].ls].sz+T[T[x].rs].sz+1,T[x].sm=T[T[x].ls].sm+T[T[x].rs].sm+T[x].vl;}
inline void split(int x,int w,int &a,int &b)
{
	if(!x) return(void)(a=b=0);
	if(w<T[x].vl) b=x,split(T[x].ls,w,a,T[x].ls),pushup(x);
	else a=x,split(T[x].rs,w,T[x].rs,b),pushup(x);
}
inline void SPLIT(int x,int k,int &a,int &b)
{
	if(!x) return(void)(a=b=0);
	if(k<=T[T[x].ls].sz) b=x,SPLIT(T[x].ls,k,a,T[x].ls),pushup(x);
	else a=x,SPLIT(T[x].rs,k-T[T[x].ls].sz-1,T[x].rs,b),pushup(x);
}
inline int mrg(int a,int b)
{
	if(!a||!b) return a|b;else if(!(a^b)) return a;
	if(Rnd(T[a].sz,T[b].sz)) return T[a].rs=mrg(T[a].rs,b),pushup(a),a;
	else return T[b].ls=mrg(a,T[b].ls),pushup(b),b;
}
inline int fndl(int x) {return T[x].ls?fndl(T[x].ls):T[x].vl;}
inline void ins(int x) {int a,b;split(rt,x,a,b),T[++tt]=(node){x,x,1,0,0},rt=mrg(a,mrg(tt,b));}
inline void del(int x) {int a,b,c;split(rt,x-1,a,b),split(b,x,b,c),b=mrg(T[b].ls,T[b].rs),rt=mrg(a,mrg(b,c));}
inline ll Kths(int x) {int a,b;ll r;return SPLIT(rt,T[rt].sz-x,a,b),r=T[b].sm,rt=mrg(a,b),r;}
inline int Kth(int x) {int a,b,r;return SPLIT(rt,T[rt].sz-x,a,b),r=fndl(b),rt=mrg(a,b),r;}
multiset<int>fi;ll sum=0;
inline void debug(int x) {if(x) debug(T[x].ls),printf("%d ",T[x].vl),debug(T[x].rs);}
inline void solve()
{//fire  K K
	int a,b,c;read(b),read(c),a=c>0,c=abs(c);
	if(a) ins(c),sum+=c,(b==1?K++:(fi.insert(c),0));else del(c),sum-=c,(b==1?K--:(fi.erase(c),0));
	//printf("debug : "),debug(rt),putchar('\n');
	ll rs=0;if(Kth(K)>*fi.rbegin()) rs=Kths(K-1)+*fi.rbegin()+sum;else rs=Kths(K)+sum;
	printf("%lld\n",rs);
}
int main() {int Ca;fi.insert(0);for(read(Ca);Ca--;) solve();return 0;}