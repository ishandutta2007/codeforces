#include<bits/stdc++.h>
using namespace std;
#include<bits/extc++.h>
using namespace __gnu_pbds;
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
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
unordered_set<int>adj[maxn];
int c,fa[maxn],m,n,q;
gp_hash_table<int,int>to[maxn];
int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
inline void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		if(adj[x].size()>adj[y].size())swap(x,y);
		fa[x]=y,adj[y].insert(adj[x].begin(),adj[x].end());
	}
}
int main(){
	n=qr(),m=qr(),c=qr(),q=qr();
	for(ri i=1;i<=n;++i)fa[i]=i;
	for(ri i=1,x,y,z;i<=m;++i){
		x=qr(),y=qr(),z=qr();
		adj[find(x)].insert(y),adj[find(y)].insert(x);
		auto itx=to[x].find(z),ity=to[y].find(z);
		if(itx==to[x].end())to[x][z]=y;
		else merge(itx->second,y);
		if(ity==to[y].end())to[y][z]=x;
		else merge(ity->second,x);
	}
	for(ri i=1,x,y,z;i<=q;++i){
		char op=getchar();
		while(op!='?'&&op!='+')op=getchar();
		x=qr(),y=qr();
		if(op=='?'){
			x=find(x);
			if(x==find(y)||adj[x].count(y))putchar('Y'),putchar('e'),putchar('s');
			else putchar('N'),putchar('o');
			putchar(10);
		}
		else{
			z=qr();
			adj[find(x)].insert(y),adj[find(y)].insert(x);
			auto itx=to[x].find(z),ity=to[y].find(z);
			if(itx==to[x].end())to[x][z]=y;
			else merge(itx->second,y);
			if(ity==to[y].end())to[y][z]=x;
			else merge(ity->second,x);
		}
	}
	return 0;
}