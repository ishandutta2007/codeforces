#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 * 2 + 5;
typedef long long ll;
struct Edge{
	int next,to;
	ll dis;
}e[N];
int n,head[N],numE = 0,fa[N];
ll w[N],c[N],ans[N];
vector<ll> val;
vector<int> num;
void addEdge(int from,int to,ll dis){
	e[++numE].next = head[from];
	e[numE].to = to;
	e[numE].dis = dis;
	head[from] = numE;
}
void dfs_(int u){
	for(int i = head[u];i;i=e[i].next){
		int v = e[i].to, dis = e[i].dis;
		ll g = (val.size() > 0 ? val.back() : 0) + dis;
		val.push_back(g);
		num.push_back(v);
		dfs_(v);
		int pos = (lower_bound(val.begin(),val.end(),g - w[v]) - val.begin());
		if(pos >= 0)c[fa[num[pos]]]--,c[u]++;
		num.pop_back();
		val.pop_back();
	}
	
}
void dfs(int u){
	ans[u] = c[u];
	for(int i = head[u];i;i=e[i].next){
		int v = e[i].to, dis = e[i].dis;
		dfs(v);
		ans[u] += ans[v];
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin >> w[i];
	fa[1] = 0;
	addEdge(0,1,0);
	for(int i=2;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,i,v);
		fa[i] = u;
	} 
	dfs_(0);
	dfs(0);
	for(int i=1;i<=n;i++)cout << ans[i] << " ";
	return 0;
}