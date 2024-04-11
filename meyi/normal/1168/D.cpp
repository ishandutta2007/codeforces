#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=15e4+10;
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
	while(!islower(ch=getchar())&&ch!='?');
	return ch;
}
template<class T>
inline void ps(const T &s,char ed=10){
	for(const char &ch:s)if(ch)putchar(ch);
	putchar(ed);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
char c[maxn];
vector<int>g[maxn];
int bel[maxn],cnt,d,dep[maxn],f[maxn][26],m,n,sum[maxn][26];
void dfs1(int p,int fa){
	ckmax(d,dep[p]=dep[fa]+1);
	if(!g[p].size()&&dep[p]!=d){
		while(m--)puts("Fou");
		exit(0);
	}
	for(ri i:g[p])dfs1(i,p);
}
vector<int>cur;
struct edge{
	int to,nxt;
}e[maxn];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
inline bool check(int p){return accumulate(f[p],f[p]+26,0)>d-dep[p];}
int fa[maxn];
void dfs2(int p,int k){
	cur.push_back(p);
	if(g[p].size()!=1||p==1){
		for(ri i:cur){
			bel[i]=p;
			if(c[i]!='?')++sum[p][c[i]-'a'];
		}
		vector<int>().swap(cur);
		if(k)addedge(k,p);
		k=p;
	}
	for(ri i:g[p])dfs2(i,k);
	if(hd[p]){
		for(ri i=hd[p];i;i=e[i].nxt){
			fa[e[i].to]=p;
			for(ri j=0;j<26;++j)ckmax(f[p][j],f[e[i].to][j]+sum[e[i].to][j]);
		}
		cnt+=check(p);
	}
}
void dfs3(int p){
	cnt-=check(p);
	memset(f[p],0,sizeof f[p]);
	for(ri i=hd[p];i;i=e[i].nxt)
		for(ri j=0;j<26;++j)
			ckmax(f[p][j],f[e[i].to][j]+sum[e[i].to][j]);
	cnt+=check(p);
	if(p>1)dfs3(fa[p]);
}
int main(){
	n=qr(),m=qr();
	for(ri i=2;i<=n;++i){
		g[qr()].push_back(i);
		c[i]=gc();
	}
	dfs1(1,0);
	dfs2(1,0);
	while(m--){
		ri x=qr();
		if(c[x]!='?')--sum[bel[x]][c[x]-'a'];
		c[x]=gc();
		if(c[x]!='?')++sum[bel[x]][c[x]-'a'];
		dfs3(fa[bel[x]]);
		if(cnt)ps("Fou");
		else{
			ps("Shi",32);
			ri ans=0,sum=accumulate(f[1],f[1]+26,0);
			for(ri i=0;i<26;++i)ans+=(d-1-(sum-f[1][i]))*(i+1);
			qw(ans),putchar(10);
		}
	}
	return 0;
}