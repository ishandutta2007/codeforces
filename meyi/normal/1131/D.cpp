#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2010;
struct edge{
	int to,nxt;
}e[maxn*maxn];
int deg[maxn],hd[maxn],len;
inline void addedge(int fr,int to){
	++deg[to];
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
bool cur[maxn],vis[maxn];
void check(int p){
	cur[p]=vis[p]=true;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to])check(e[i].to);
		else if(cur[e[i].to]){
			puts("No");
			exit(0);
		}
	cur[p]=false;
}
struct dsu{
	int fa[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y)fa[x]=y;
	}
}d;
int ans[maxn],m,n;
inline void toposort(){
	queue<int>q;
	for(ri i=1;i<=n+m;++i)
		if(d.find(i)==i&&!deg[i])
			ans[i]=1,q.push(i);
	while(q.size()){
		ri p=q.front();q.pop();
		for(ri i=hd[p];i;i=e[i].nxt){
			assert(deg[e[i].to]);
			ckmax(ans[e[i].to],ans[p]+1);
			if(!--deg[e[i].to])q.push(e[i].to);
		}
	}
}
char s[maxn][maxn];
signed main(){
	scanf("%d%d",&n,&m);
	d.init(n+m);
	for(ri i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		for(ri j=1;j<=m;++j)
			if(s[i][j]=='=')
				d.merge(i,n+j);
	}
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			if(s[i][j]!='='){
				ri x=d.find(i),y=d.find(n+j);
				if(s[i][j]=='<')addedge(x,y);
				else addedge(y,x);
			}
	for(ri i=1;i<=n+m;++i)
		if(d.find(i)==i&&!vis[i])
			check(i);
	puts("Yes");
	toposort();
	for(ri i=1;i<=n;++i)printf("%d ",ans[d.find(i)]);
	printf("\n");
	for(ri i=1;i<=m;++i)printf("%d ",ans[d.find(n+i)]);
	return 0;
}