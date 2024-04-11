#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
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
template<class T>
inline void ps(const T &s,char ed=10){
	for(const char &ch:s)if(ch)putchar(ch);
	putchar(ed);
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
int id[maxn],l[maxn],m,n,n1=INT_MAX,n2,nl,nr,r[maxn];
void dfs(int p){
	for(ri i=hd[p];i;i=e[i].nxt){
		if(!id[e[i].to])id[e[i].to]=3-id[p],dfs(e[i].to);
		else if(id[p]==id[e[i].to])ps("IMPOSSIBLE"),exit(0);
	}
}
int main(){
	nl=qr(),nr=qr(),n=qr(),m=qr();
	for(ri i=1;i<=n;++i){
		l[i]=qr(),r[i]=qr();
		ckmin(n1,r[i]),ckmax(n2,l[i]);
	}
	if(n1+n2<nl)n2=nl-n1;
	if(n1+n2>nr)n1=nr-n2;
	if(min(n1,n2)<0)return ps("IMPOSSIBLE"),0;
	for(ri i=1;i<=n;++i){
		bool f1=l[i]<=n1&&n1<=r[i],f2=l[i]<=n2&&n2<=r[i];
		if(!f1&&!f2)return ps("IMPOSSIBLE"),0;
		if(!f1)id[i]=2;
		if(!f2)id[i]=1;
	}
	while(m--){
		ri x=qr(),y=qr();
		addedge(x,y),addedge(y,x);
	}
	for(ri i=1;i<=n;++i)if(id[i])dfs(i);
	for(ri i=1;i<=n;++i)if(!id[i])id[i]=1,dfs(i);
	ps("POSSIBLE");
	qw(n1),putchar(32),qw(n2),putchar(10);
	for(ri i=1;i<=n;++i)putchar(id[i]|48);
	return 0;
}