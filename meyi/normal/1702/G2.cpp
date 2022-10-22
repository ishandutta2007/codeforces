#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
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
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int dep[maxn],dfn,fa[maxn],rev[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn];
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
void dfs2(int p,int k){
	seg[p]=++dfn;
	rev[dfn]=p;
	top[p]=k;
	if(son[p]){
		dfs2(son[p],k);
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!top[e[i].to])
				dfs2(e[i].to,e[i].to);
	}
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int a[maxn],b[maxn],n,q;
int main(){
	n=qr();
	for(ri i=1,x,y;i<n;++i){
		x=qr(),y=qr();
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	q=qr();
	while(q--){
		*a=qr();
		for(ri i=1;i<=*a;++i)a[i]=qr();
		sort(a+1,a+*a+1,[&](int x,int y){return dep[x]>dep[y];});
		*b=0;
		ri lst=a[1];
		for(ri i=2;i<=*a;++i){
			if(lca(lst,a[i])==a[i])lst=a[i];
			else b[++*b]=a[i];
		}
		if(*b){
			reverse(b+1,b+*b+1);
			if(lca(a[1],b[*b])!=lca(lst,b[*b])){putchar('N'),putchar('O');goto skip;}
			for(ri i=2;i<=*b;++i)if(lca(b[i-1],b[i])!=b[i-1]){putchar('N'),putchar('O');goto skip;}
		}
		putchar('Y'),putchar('E'),putchar('S');
		skip:;
		putchar(10);
	}
	return 0;
}