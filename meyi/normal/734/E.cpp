#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
inline char gc(){
	char ch;
	while(!isdigit(ch=getchar()));
	return ch;
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int ans,mx[maxn];
void dfs(int p,int f){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs(e[i].to,p);
			ckmax(ans,mx[p]+e[i].v+mx[e[i].to]);
			ckmax(mx[p],e[i].v+mx[e[i].to]);
		}
}
char a[maxn];
int n;
signed main(){
	n=qr();
	for(ri i=1;i<=n;++i)a[i]=gc();
	for(ri i=1,x,y;i<n;++i){
		x=qr(),y=qr();
		addedge(x,y,a[x]!=a[y]),addedge(y,x,a[x]!=a[y]);
	}
	dfs(1,0);
	qw((ans+1)>>1);
	return 0;
}