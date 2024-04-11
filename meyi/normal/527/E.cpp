#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=5e5+10;
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
}e[maxn<<1];
int deg[maxn],hd[maxn],len=1;
inline void addedge(int fr,int to){
	++deg[fr];
	e[++len]={to,hd[fr]};
	hd[fr]=len;
	++deg[to];
	e[++len]={fr,hd[to]};
	hd[to]=len;
}
int a[maxn],cnt,m,n;
bool flag,vis[maxn<<1];
void dfs(int p){
	for(ri &i=hd[p];i;i=e[i].nxt){
		if(vis[i])continue;
		vis[i]=vis[i^1]=true;
		ri nxt=e[i].to;
		dfs(nxt);
		if(flag^=1)qw(nxt),putchar(32),qw(p);
		else qw(p),putchar(32),qw(nxt);
		putchar(10);
	}
}
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=m;++i){
		ri x=qr(),y=qr();
		addedge(x,y);
	}
	for(ri i=1;i<=n;++i)
		if(deg[i]&1)
			a[++cnt]=i;
	for(ri i=1;i<cnt;i+=2)addedge(a[i],a[i+1]),++m;
	if(m&1)addedge(1,1),++m;
	qw(m),putchar(10);
	dfs(1);
	return 0;
}