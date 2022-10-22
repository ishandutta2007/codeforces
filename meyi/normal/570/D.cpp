#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int dep[maxn],siz[maxn],son[maxn];
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt){
		dfs1(e[i].to,p);
		siz[p]+=siz[e[i].to];
		if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
	}
}
int cnt[maxn];
char s[maxn];
void dfs3(int p){
	cnt[dep[p]]^=1<<(s[p]-'a');
	for(ri i=hd[p];i;i=e[i].nxt)dfs3(e[i].to);
}
bool ans[maxn];
int d[maxn];
vector<int>q[maxn];
void dfs2(int p){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=son[p]){
			dfs2(e[i].to);
			dfs3(e[i].to);
		}
	if(son[p]){
		dfs2(son[p]);
		for(ri i=hd[p];i;i=e[i].nxt)
			if(e[i].to!=son[p])
				dfs3(e[i].to);
	}
	cnt[dep[p]]^=1<<(s[p]-'a');
	for(ri i:q[p])ans[i]=__builtin_popcount(cnt[d[i]])>1;
}
int m,n;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=2,f;i<=n;++i){
		scanf("%d",&f);
		addedge(f,i);
	}
	scanf("%s",s+1);
	for(ri i=1,p;i<=m;++i){
		scanf("%d%d",&p,d+i);
		q[p].push_back(i);
	}
	dfs1(1,0);
	dfs2(1);
	for(ri i=1;i<=m;++i)puts(ans[i]?"No":"Yes");
	return 0;
}