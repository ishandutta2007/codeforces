#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int fr,to,v,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v){
	e[++len]={fr,to,v,hd[fr]};
	hd[fr]=len;
}
ll dis[maxn];
struct node{
	ll d;
	int p;
	inline bool operator<(const node &k)const{
		return d>k.d;
	}
};
priority_queue<node>q;
bool vis[maxn];
inline void dijkstra(int s,ll *res){
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push({0,s});
	memset(vis,0,sizeof vis);
	while(q.size()){
		ri p=q.top().p;q.pop();
		if(vis[p])continue;
		vis[p]=true;
		for(ri i=hd[p];i;i=e[i].nxt)
			if(dis[p]+e[i].v<dis[e[i].to]){
				dis[e[i].to]=dis[p]+e[i].v;
				if(!vis[e[i].to])q.push({dis[e[i].to],e[i].to});
			}
	}
	memcpy(res,dis,sizeof dis);
}
ll dis1[maxn],dis2[maxn];
int k,l[maxn],m,r[maxn];
inline bool check(){
	bool flag=false;
	for(ri i=1;i<=k;++i){
		ri j=i+m;
		if(dis1[e[j].fr]<dis2[e[j].fr]&&e[j].v==r[i])e[j].v=l[i],flag=true;
	}
	return flag;
}
int n,s1,s2,t;
signed main(){
	scanf("%d%d%d%d%d%d",&n,&m,&k,&s1,&s2,&t);
	for(ri i=1,x,y,z;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	for(ri i=1,x,y;i<=k;++i){
		scanf("%d%d%d%d",&x,&y,l+i,r+i);
		addedge(x,y,r[i]);
	}
	do dijkstra(s1,dis1),dijkstra(s2,dis2);while(check());
	if(dis1[t]>dis2[t])return puts("LOSE"),0;
	puts(dis1[t]<dis2[t]?"WIN":"DRAW");
	for(ri i=1;i<=k;++i)printf("%d ",e[i+m].v);
	return 0;
}