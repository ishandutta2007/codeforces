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
const int P=998244353;int fc[400005],fi[400005];
struct node{int sm,tg,sz,ls,rs;}T[200005];int tt,rt,n,m;
inline char rnd(int a,int b) {return rand()%(a+b)<a;}
inline void pushup(int x) {if(x) T[x].sz=T[T[x].ls].sz+T[T[x].rs].sz+1;}
inline void allc(int x,int c) {if(x) T[x].tg+=c,T[x].sm+=c;}
inline void pushdw(int x) {if(T[x].tg) allc(T[x].ls,T[x].tg),allc(T[x].rs,T[x].tg),T[x].tg=0;}
inline void split(int x,int v,int &a,int &b)
{
	if(!x) return a=b=0,void();else pushdw(x);
	if(T[x].sm<=v) a=x,split(T[x].rs,v,T[a].rs,b),pushup(a);
	else b=x,split(T[x].ls,v,a,T[b].ls),pushup(b);
}
inline int mrg(int x,int y)
{
	if(!x||!y||!(x^y)) return x|y;else pushdw(x),pushdw(y);
	if(rnd(T[x].sz,T[y].sz)) return T[x].rs=mrg(T[x].rs,y),pushup(x),x;
	else return T[y].ls=mrg(x,T[y].ls),pushup(y),y;
}
inline char fnd(int x,int w)
{
	if(!x) return 0;else if(T[x].sm==w) return 1;else pushdw(x);
	if(w<T[x].sm) return fnd(T[x].ls,w);else return fnd(T[x].rs,w);
}
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void init()
{
	srand(time(0)),fc[0]=1;for(int i=1;i<=400000;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[400000]=ksm(fc[400000]);for(int i=400000;i;i--) fi[i-1]=1ll*fi[i]*i%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
inline void debug(int x)
{
	if(!x) return;else pushdw(x);
	debug(T[x].ls),printf("%d ",T[x].sm),debug(T[x].rs);
}
inline void solve()
{
	read(n,m),tt=rt=0;for(int i=1,x,y;i<=m;i++)
	{
		read(x,y);char fg=fnd(rt,y);
		int a,b;split(rt,y-1,a,b);if(b) allc(b,1);
#ifndef ONLINE_JUDGE
		printf("left : "),debug(a),putchar('\n');
		printf("righ : "),debug(b),putchar('\n');
#endif
		if(fg) rt=mrg(a,b);else T[++tt]=(node){y+1,0,1,0,0},rt=mrg(mrg(a,tt),b);
#ifndef ONLINE_JUDGE
		debug(rt),puts("\n----------");
#endif
	}
	printf("%d\n",C(n+n-tt-1,n));
}
int main() {int Ca;for(init(),read(Ca);Ca--;) solve();return 0;}