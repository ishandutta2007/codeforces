#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int siz[maxn],son[maxn];
void dfs1(int p,int f){
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
int c[maxn],cnt[maxn],mx,n,st[maxn],tp;
ll ans[maxn],sum;
inline void insert(int k){
	++cnt[k];
	if(cnt[k]>mx)mx=cnt[k],sum=k;
	else if(cnt[k]==mx)sum+=k;
	st[++tp]=k;
}
void dfs3(int p,int f){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs3(e[i].to,p);
	insert(c[p]);
}
void dfs2(int p,int f){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f&&e[i].to!=son[p]){
			dfs2(e[i].to,p);
			while(tp)cnt[st[tp--]]=0;
			mx=sum=0;
		}
	if(son[p])dfs2(son[p],p);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f&&e[i].to!=son[p])
			dfs3(e[i].to,p);
	insert(c[p]);
	ans[p]=sum;
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",c+i);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(ri i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}