#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=4e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct edge{
	int to,nxt;
}e[maxn*10];
int hd[maxn<<2],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int clr,cnt,dfn[maxn<<2],id[maxn<<2],low[maxn<<2],st[maxn<<2],tp;
bool vis[maxn<<2];
void tarjan(int p){
	dfn[p]=low[p]=++cnt;
	st[++tp]=p;
	vis[p]=true;
	for(ri i=hd[p];i;i=e[i].nxt){
		if(!dfn[e[i].to])tarjan(e[i].to),ckmin(low[p],low[e[i].to]);
		else if(vis[e[i].to])ckmin(low[p],dfn[e[i].to]);
	}
	if(dfn[p]==low[p]){
		++clr;
		ri k;
		do{
			k=st[tp--];
			vis[k]=false;
			id[k]=clr;
		}while(k!=p);
	}
}
int ans[maxn],l[maxn],n,m,M,p,pos,r[maxn],tot;
inline int idx(int x,int y){return x-1<<1|y;}
int main(){
	n=qr(),p=qr(),M=qr(),m=qr();
	for(ri i=1,x,y;i<=n;++i){
		x=qr(),y=qr();
		addedge(idx(x,0),idx(y,1));
		addedge(idx(y,0),idx(x,1));
	}
	for(ri i=1;i<=p;++i){
		l[i]=qr(),r[i]=qr();
		if(l[i]>1){
			addedge(idx(i,1),idx(p+l[i]-1,0));
			addedge(idx(p+l[i]-1,1),idx(i,0));
		}
		addedge(idx(i,1),idx(p+r[i],1));
		addedge(idx(p+r[i],0),idx(i,0));
	}
	for(ri i=1;i<M;++i){
		addedge(idx(p+i,1),idx(p+i+1,1));
		addedge(idx(p+i+1,0),idx(p+i,0));
	}
	for(ri i=1,x,y;i<=m;++i){
		x=qr(),y=qr();
		addedge(idx(x,1),idx(y,0));
		addedge(idx(y,1),idx(x,0));
	}
	for(ri i=1;i<=p+M;++i){
		if(!dfn[idx(i,0)])tarjan(idx(i,0));
		if(!dfn[idx(i,1)])tarjan(idx(i,1));
	}
	for(ri i=1;i<=p;++i){
		if(id[idx(i,0)]==id[idx(i,1)])return putchar('-'),putchar(49),0;
		if(id[idx(i,0)]>id[idx(i,1)]){
			ans[++tot]=i;
			ckmax(pos,l[i]);
		}
	}
	qw(tot),putchar(32),qw(pos),putchar(10);
	for(ri i=1;i<=tot;++i)qw(ans[i]),putchar(32);
	return 0;
}