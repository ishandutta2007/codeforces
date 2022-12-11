#include<bits/stdc++.h>
#define ll long long
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
const int N=4e5+10;
int n,m,fa[N],siz[N],col[N];
ll ans[N];
std::vector<int> G[N];
struct info{int tim,nod,opt;};std::vector<info> q[N];
void dfs(int u){siz[u]=1;for(int v:G[u])if(v!=fa[u])fa[v]=u,dfs(v),siz[u]+=siz[v];}
namespace lct{
	ll ans,sum[N];
	int z,fa[N],ch[N][2],siz[N],rev[N],vsiz[N];
	inline bool getson(int x){return ch[fa[x]][1]==x;}
	inline bool isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
	inline void maintain(int x){
		siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+vsiz[x]+1;
	}
	void rotate(int x){
		if(!x||!fa[x])return;int f=fa[x],ff=fa[f],fs=getson(x),ffs=getson(f),y=ch[x][fs^1];
		if(!isroot(f))ch[ff][ffs]=x;ch[x][fs^1]=f,ch[f][fs]=y,fa[y]=f,fa[f]=x,fa[x]=ff,maintain(f),maintain(x);
	}
	void splay(int x){for(int f=fa[x];!isroot(x);rotate(x),f=fa[x])if(!isroot(f))rotate(getson(x)==getson(f)?f:x);}
	void access(int x){
		for(int y=0;x;y=x,x=fa[x]){
			splay(x);
			vsiz[x]+=siz[ch[x][1]]-siz[y];
			sum[x]+=(ll)siz[ch[x][1]]*siz[ch[x][1]]-(ll)siz[y]*siz[y];
			ch[x][1]=y,maintain(x);
		}
	}
	int findroot(int x){access(x),splay(x);while(ch[x][0])x=ch[x][0];return x;}
	inline ll getsize(int x){return sum[x]+(ll)siz[ch[x][1]]*siz[ch[x][1]];}
	void link(int x,int y){
		z=findroot(y),splay(z),ans-=getsize(z);
		access(x),splay(x),ans-=getsize(x);
		fa[x]=y,vsiz[y]+=siz[x],sum[y]+=(ll)siz[x]*siz[x],maintain(y),z=findroot(y),splay(z),ans+=getsize(z);
	}
	void cut(int x,int y){
		z=findroot(y),splay(z),ans-=getsize(z);
		access(x),splay(x),ch[x][0]=fa[y]=0,maintain(x),ans+=getsize(x);
		z=findroot(y),splay(z),ans+=getsize(z);
	}
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(m);
	for(int i=1;i<=n;i++)read(col[i]),q[col[i]].push_back({0,i,0});
	for(int u,v,i=1;i<n;i++)read(u),read(v),G[u].push_back(v),G[v].push_back(u);
	for(int x,y,i=1;i<=m;i++)read(x),read(y),q[col[x]].push_back({i,x,1}),col[x]=y,q[col[x]].push_back({i,x,0});
	for(int i=1;i<=n;i++)q[col[i]].push_back({m+1,i,1});
	dfs(1),fa[1]=n+1;
	for(int i=1;i<=n;i++)lct::link(i,fa[i]);
	for(int c=1;c<=n;c++){
		const auto &q=::q[c];
		if(!q.size()||q[0].tim){
			int cur=0,nxt=q.size()?q[0].tim:m+1;
			ans[cur]+=lct::ans,ans[nxt]-=lct::ans;
		}
		for(int i=0;i<q.size();i++){
			(q[i].opt?lct::link:lct::cut)(q[i].nod,fa[q[i].nod]);
			if(i+1==q.size()||q[i].tim!=q[i+1].tim){
				int cur=q[i].tim,nxt=i+1==q.size()?m+1:q[i+1].tim;
				ans[cur]+=lct::ans,ans[nxt]-=lct::ans;
			}
		}
	}
	for(int i=1;i<=m;i++)ans[i]+=ans[i-1];
	for(int i=0;i<=m;i++)print((ll)n*n*n-ans[i]),putchar('\n');
}