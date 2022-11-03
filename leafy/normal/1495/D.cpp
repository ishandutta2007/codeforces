#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=605,mod=998244353;
int n,m;
vector<int> G[N];
int dis[N][N],c[N];
ll ans[N][N];
void bfs(int s,int dis[N]){
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:G[u]){
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
inline ll calc(int x,int y){
	if(x>y) swap(x,y);
	if(ans[x][y]!=-1) return ans[x][y];
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++) if(dis[x][i]+dis[i][y]==dis[x][y]) c[dis[x][i]]++;
	for(int i=0;i<=n;i++) if(c[i]>1) return 0;
	ll res=1;
	for(int i=1;i<=n;i++){
		if(i==x) continue;
		int cnt=0;
		if(dis[x][i]+dis[i][y]==dis[x][y]){
			for(int j:G[i])
				if(dis[x][j]==dis[x][i]-1&&dis[j][y]==dis[i][y]+1)
					cnt++;
		}else {
			for(int j:G[i]){
				if(dis[x][j]==dis[x][i]-1&&dis[j][y]==dis[i][y]-1)
					cnt++;
			}	
		}
		res=res*cnt%mod;
	}
	return res;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=n;i++) {
		memset(dis[i],-1,sizeof(dis[i]));
		bfs(i,dis[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%lld ",calc(i,j));
		puts("");
	}
	return 0;
}