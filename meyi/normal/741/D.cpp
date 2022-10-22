#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],dep[maxn],siz[maxn],son[maxn];
void dfs1(int p){
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt){
		a[e[i].to]=a[p]^e[i].v;
		dep[e[i].to]=dep[p]+1;
		dfs1(e[i].to);
		siz[p]+=siz[e[i].to];
		if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
	}
}
int ans[maxn],cur,mx[1<<22];
inline void insert(int p){
	if(mx[a[p]]>=dep[cur])ckmax(ans[cur],dep[p]+mx[a[p]]-(dep[cur]<<1));
	for(ri i=1;i<(1<<22);i<<=1)
		if(mx[a[p]^i]>=dep[cur])
			ckmax(ans[cur],dep[p]+mx[a[p]^i]-(dep[cur]<<1));
}
void dfs3(int p,int v){
	if(v&1)insert(p);
	else if(v)ckmax(mx[a[p]],dep[p]);
	else mx[a[p]]=0;
	for(ri i=hd[p];i;i=e[i].nxt)dfs3(e[i].to,v);
}
void dfs2(int p){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=son[p]){
			dfs2(e[i].to);
			ckmax(ans[p],ans[e[i].to]);
			dfs3(e[i].to,0);
		}
	if(son[p]){
		dfs2(son[p]);
		ckmax(ans[p],ans[son[p]]);
	}
	cur=p;
	insert(p);
	ckmax(mx[a[p]],dep[p]);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=son[p]){
			dfs3(e[i].to,1);
			dfs3(e[i].to,2);
		}
}
int n;
char s[5];
signed main(){
	scanf("%d",&n);
	for(ri i=2,f;i<=n;++i){
		scanf("%d%s",&f,s);
		addedge(f,i,1<<(*s-'a'));
	}
	dfs1(1);
	dfs2(1);
	for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}