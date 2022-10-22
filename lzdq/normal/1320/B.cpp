#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5,MAXM=5e5+5;
int n,k,m;
int cnte,h[MAXN],nx[MAXM],to[MAXM];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int p[MAXN];
int dis[MAXN];
queue<int> que;
void Bfs(){
	dis[p[k]]=1;
	que.push(p[k]);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=h[u]; i; i=nx[i]){
			if(i&1) continue;
			int v=to[i];
			if(!dis[v]) dis[v]=dis[u]+1,que.push(v);
		}
	}
	return ;
}
int ans1,ans2;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	scanf("%d",&k);
	for(int i=1; i<=k; i++)
		scanf("%d",p+i);
	Bfs();
	for(int i=1; i<k; i++){
		int u=p[i],tot=0;
		for(int j=h[u]; j; j=nx[j]){
			if(!(j&1)) continue;
			int v=to[j];
			if(dis[u]==dis[v]+1) tot++;
		}
		if(dis[u]==dis[p[i+1]]+1){
			if(tot>1) ans2++;
		}else ans1++,ans2++;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}