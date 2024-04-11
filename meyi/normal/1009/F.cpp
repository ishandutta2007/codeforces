#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int ans[maxn],cnt[maxn],dep[maxn],n,siz[maxn],son[maxn];
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
int mx;
inline void insert(int p){
	++cnt[dep[p]];
	if(cnt[dep[p]]>cnt[mx]||(cnt[dep[p]]==cnt[mx]&&dep[p]<mx))mx=dep[p];
}
void dfs3(int p,int f,bool t){
	if(t)insert(p);
	else --cnt[dep[p]];
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs3(e[i].to,p,t);
}
void dfs2(int p,int f){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f&&e[i].to!=son[p]){
			mx=0;
			dfs2(e[i].to,p);
			dfs3(e[i].to,p,0);
		}
	mx=0;
	if(son[p])dfs2(son[p],p);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f&&e[i].to!=son[p])
			dfs3(e[i].to,p,1);
	insert(p);
	ans[p]=mx-dep[p];
}
int main(){
	scanf("%d",&n);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(ri i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}