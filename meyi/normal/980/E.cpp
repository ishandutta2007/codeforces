#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10;
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
int dep[maxn],fa[maxn][20],k,n;
vector<int>to[maxn];
bool vis[maxn];
void dfs(int p,int f){
	dep[p]=dep[f]+1;
	fa[p][0]=f;
	for(ri i=1,j=__lg(dep[p]);i<=j;++i)fa[p][i]=fa[fa[p][i-1]][i-1];
	for(ri i:to[p])
		if(i!=f)
			dfs(i,p);
}
int main(){
	n=qr(),k=qr();
	for(ri i=1;i<n;++i){
		ri x=qr(),y=qr();
		to[x].push_back(y),to[y].push_back(x);
	}
	dfs(n,0);
	vis[0]=true;
	for(ri i=n;k<n;--i){
		if(vis[i])continue;
		ri f=i;
		for(ri j=__lg(dep[i]);~j;--j)
			if(!vis[fa[f][j]])
				f=fa[f][j];
		ri dis=dep[i]-dep[f]+1;
		if(k+dis<=n){
			k+=dis;
			for(ri j=i;!vis[j];j=fa[j][0])vis[j]=true;
		}
	}
	for(ri i=1;i<=n;++i)
		if(!vis[i])
			qw(i),putchar(32);
	return 0;
}