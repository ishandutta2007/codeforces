#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,a[MAXN];
int cnte,h[MAXN],to[MAXN],nx[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int dis[MAXN];
struct node{
	int u,d;
};
bool operator <(node a,node b){
	return a.d>b.d;
}
priority_queue<node> que;
int Add(int u,int k){
	int res=k+a[u];
	a[u]--;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		a[u]++;
		adde(v,u);
	}
	memset(dis,0x3f,sizeof(dis));
	que.push(node{n,0});
	dis[n]=0;
	while(!que.empty()){
		node t(que.top());
		que.pop();
		int u=t.u;
		if(t.d>dis[u]) continue;
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			int d=Add(v,dis[u]);
			if(d<dis[v]){
				dis[v]=d;
				que.push(node{v,d});
			}
		}
	}
	printf("%d\n",dis[1]);
	return 0;
}