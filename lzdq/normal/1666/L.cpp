#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,s;
int cnte,h[MAXN],to[MAXN],nx[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int pre[MAXN],f[MAXN];
queue<int> que;
int tot,ans[MAXN];
void Print(int u){
	tot=0;
	while(u!=s){
		ans[++tot]=u;
		u=pre[u];
	}
	ans[++tot]=s;
	printf("%d\n",tot);
	for(int i=tot; i; i--)
		printf("%d%c",ans[i],i==1?'\n':' ');
	return ;
}
void Bfs(int p){
	if(pre[p]){
		puts("Possible");
		Print(p);
		pre[p]=s;
		Print(p);
		exit(0);
	}
	pre[p]=s;
	que.push(p);
	f[p]=p;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			if(!pre[v]){
				pre[v]=u;
				f[v]=p;
				que.push(v);
			}else if(f[v]!=p){
				puts("Possible");
				Print(v);
				pre[v]=u;
				Print(v);
				exit(0);
			}
		}
	}
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d%d",&n,&m,&s);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		if(v!=s) adde(u,v);
	}
	for(int i=h[s]; i; i=nx[i])
		Bfs(to[i]);
	puts("Impossible");
	return 0;
}