#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int inf=0x3f3f3f3f,maxn=5e3+10;
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
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct edge{
	int v,to,nxt;
}e[maxn];
int deg[maxn],hd[maxn],len;
inline void addedge(int fr,int to,int v){
	++deg[to];
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int f[maxn][maxn],k,m,n;
short pre[maxn][maxn];
inline void toposort(){
	queue<int>q;
	for(ri i=1;i<=n;++i)
		if(!deg[i])
			q.push(i);
	while(q.size()){
		ri p=q.front();q.pop();
		for(ri i=hd[p];i;i=e[i].nxt){
			if(!--deg[e[i].to])q.push(e[i].to);
			for(ri j=1;j<n;++j)
				if(f[p][j]+e[i].v<=f[e[i].to][j+1]){
					f[e[i].to][j+1]=f[p][j]+e[i].v;
					pre[e[i].to][j+1]=p;
				}
		}
	}
}
void dfs(int p,int d){
	if(pre[p][d])dfs(pre[p][d],d-1);
	qw(p),putchar(32);
}
int main(){
	n=qr(),m=qr(),k=qr();
	while(m--){
		ri x=qr(),y=qr(),z=qr();
		addedge(x,y,z);
	}
	memset(f,0x3f,sizeof f);
	f[1][1]=0;
	toposort();
	for(ri i=n;i;--i)
		if(f[n][i]<=k){
			qw(i),putchar(10);
			dfs(n,i);
			break;
		}
	return 0;
}