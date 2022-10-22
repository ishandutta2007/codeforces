#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct edge{
	int to,nxt;
}e[maxn];
int hd[maxn],len;
bool vis[maxn];
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int ans[maxn],dis[maxn],m,n,st[maxn],tp;
inline void bfs(){
	for(ri i=1;i<=n;++i)dis[i]=-1;
	dis[1]=0;
	queue<int>q;
	q.push(1);
	tp=0;
	while(q.size()){
		ri p=q.front();q.pop();
		st[++tp]=p;
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!~dis[e[i].to]){
				dis[e[i].to]=dis[p]+1;
				q.push(e[i].to);
			}
	}
}
int t_case;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)hd[i]=0;
		len=0;
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		bfs();
		while(tp){
			ri p=st[tp--];
			ans[p]=dis[p];
			for(ri i=hd[p];i;i=e[i].nxt)ckmin(ans[p],dis[e[i].to]<=dis[p]?dis[e[i].to]:ans[e[i].to]);
		}
		for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}