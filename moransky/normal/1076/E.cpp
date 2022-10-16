#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3 * 1e5 + 5;
typedef long long ll;
struct Edge{
	int next,to;
}e[N * 2];
int n,m,head[N],numE=0;
ll c[N],ans[N];
vector<pair<int,int> > T[N];
void addEdge(int from,int to){
	e[++numE].next = head[from];
	e[numE].to = to;
	head[from] = numE;
}
ll ask(int x){
	ll ans = 0; 
	for(;x;x-=x&-x)ans += c[x];
	return ans;
}
void add(int x,ll k){
	for(;x<=n;x+=x&-x)c[x] += k;
}
void dfs(int u,int last,int dep){
	for(int i=0;i<T[u].size();i++){
		int d = T[u][i].first;
		ll x = T[u][i].second;
		add(dep,x);
		add(dep + d + 1,-x);
	}
	ans[u] = ask(dep);
	for(int i = head[u];i;i=e[i].next){
		int v = e[i].to;
		if(v == last)continue;
		dfs(v,u,dep + 1);
	}
	for(int i=0;i<T[u].size();i++){
		int d = T[u][i].first;
		ll x = T[u][i].second;
		add(dep,-x);
		add(dep + d + 1,+x);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(x,y);
		addEdge(y,x);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int v,d,x;
		scanf("%d%d%d",&v,&d,&x);
		T[v].push_back(make_pair(d,x));
	} 
	dfs(1,0,1);
	for(int i=1;i<=n;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}