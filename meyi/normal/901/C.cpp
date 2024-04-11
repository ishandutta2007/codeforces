#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=3e5+10;
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
int hd[maxn],len=1;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
bool cur[maxn],vis[maxn];
int fa[maxn],pre[maxn];
void dfs(int p,int f){
	cur[p]=vis[p]=true;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(i!=(f^1)){
			if(!vis[e[i].to])fa[e[i].to]=p,dfs(e[i].to,i);
			else if(cur[e[i].to]){
				ri mn=p,mx=p;
				for(ri j=p;;j=fa[j]){
					ckmin(mn,j),ckmax(mx,j);
					if(j==e[i].to)break;
				}
				if(mn<mx)ckmax(pre[mx],mn+1);
			}
		}
	cur[p]=false;
}
int c1[maxn],id[maxn],l[maxn],m,n,r[maxn],q;
ll c2[maxn];
#define lowbit(k) (k&-k)
inline void add(int l,int r){
	for(ri i=l;i<=n;i+=lowbit(i))++c1[i],c2[i]+=l-1;
	for(ri i=r+1;i<=n;i+=lowbit(i))--c1[i],c2[i]-=r;
}
ll ans[maxn];
inline ll query(int l,int r){
	ll ret=0;
	for(ri i=r;i;i^=lowbit(i))ret+=1ll*r*c1[i]-c2[i];
	for(ri i=l-1;i;i^=lowbit(i))ret-=1ll*(l-1)*c1[i]-c2[i];
	return ret;
}
int main(){
	n=qr(),m=qr();
	while(m--){
		ri x=qr(),y=qr();
		addedge(x,y),addedge(y,x);
	}
	for(ri i=1;i<=n;++i)
		if(!vis[i])
			dfs(i,0);
	q=qr();
	for(ri i=1;i<=q;++i)id[i]=i,l[i]=qr(),r[i]=qr();
	sort(id+1,id+q+1,[&](int x,int y){return r[x]<r[y];});
	for(ri i=1,j=1,k=1;i<=n;++i){
		ckmax(j,pre[i]);
		add(j,i);
		while(k<=q&&r[id[k]]==i)ans[id[k]]=query(l[id[k]],i),++k;
	}
	for(ri i=1;i<=q;++i)qw(ans[i]),putchar(10);
	return 0;
}