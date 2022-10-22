#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
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
	while(!isupper(ch=getchar()));
	return ch;
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
int cnt,dep[maxn],dfn[maxn],fa[maxn],m,n,x[maxn],y[maxn],z[maxn];
void dfs(int p,int f){
	dep[p]=dep[f]+1;
	dfn[p]=++cnt;
	fa[p]=f;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs(e[i].to,p);
}
struct dsu{
	int fa[maxn],siz[maxn],st[maxn][2],tp;
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		++tp,st[tp][0]=x,st[tp][1]=y;
		fa[y]=x,siz[x]+=siz[y];
	}
	inline void undo(int k){
		while(tp>k){
			ri x=st[tp][0],y=st[tp][1];
			--tp;
			fa[y]=y,siz[x]-=siz[y];
		}
	}
}d;
ll ans;
vector<int>pos[maxn];
void solve(int l,int r){
	if(l==r){
		for(ri i:pos[l]){
			if(dep[x[i]]>dep[y[i]])swap(x[i],y[i]);
			ans+=1ll*d.siz[d.find(x[i])]*d.siz[d.find(y[i])];
		}
	}
	else{
		ri mid=l+r>>1,tmp=d.tp;;
		for(ri j=l;j<=mid;++j)
			for(ri i:pos[j]){
				if(dep[x[i]]>dep[y[i]])swap(x[i],y[i]);
				d.merge(x[i],y[i]);
			}
		solve(mid+1,r);
		d.undo(tmp);
		for(ri j=mid+1;j<=r;++j)
			for(ri i:pos[j]){
				if(dep[x[i]]>dep[y[i]])swap(x[i],y[i]);
				d.merge(x[i],y[i]);
			}
		solve(l,mid);
		d.undo(tmp);
	}
}
int main(){
	n=qr();
	d.init(n);
	for(ri i=1;i<n;++i){
		x[i]=qr(),y[i]=qr(),z[i]=qr();
		addedge(x[i],y[i]),addedge(y[i],x[i]);
		pos[z[i]].push_back(i);
	}
	dfs(1,0);
	solve(1,n);
	printf("%lld",ans);
	return 0;
}