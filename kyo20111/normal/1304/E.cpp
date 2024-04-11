#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,q,sp[20][100100],dis[20][100100],lev[100100];
vector<pair<int,int>> v[100100];
void dfs(int cur,int par){
	lev[cur]=lev[par]+1;
	for(pair<int,int> nxt : v[cur]) if(nxt.first != par) sp[0][nxt.first]=cur,dis[0][nxt.first]=nxt.second,dfs(nxt.first,cur);
}
int lca(int a,int b){
	int re=0;
	if(lev[a]<lev[b]) swap(a,b);
	for(int i=0;i<=17;i++) if((1<<i)&(lev[a]-lev[b])) re+=dis[i][a],a=sp[i][a];
	if(a==b) return re;
	for(int i=17;i>=0;i--) if(sp[i][a] != sp[i][b]) re+=dis[i][a]+dis[i][b],a=sp[i][a],b=sp[i][b];
	return re+dis[0][a]+dis[0][b];
}
bool f(int a, int b){
	return a <= b && a%2 == b%2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back({b,1});
		v[b].push_back({a,1});
	}
	dfs(1,0);
	for(int i=1;i<=17;i++) for(int j=1;j<=n;j++) sp[i][j]=sp[i-1][sp[i-1][j]],dis[i][j]=dis[i-1][sp[i-1][j]]+dis[i-1][j];
	scanf("%d",&q);
	while(q--){
		int a,b,x,y,k; scanf("%d %d %d %d %d",&x,&y,&a,&b,&k);
		puts(f(lca(a, b), k) || f(lca(a,x) + lca(y,b) + 1, k) || f(lca(a,y) + lca(x,b) + 1, k) ? "YES" : "NO");
	}
}