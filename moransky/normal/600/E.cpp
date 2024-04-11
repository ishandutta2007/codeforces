#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator MIT;
typedef map<int, LL>::iterator MLT;
const int N = 100005;
int n, c[N];
int head[N], numE = 0;
LL ans[N];
struct E{
	int next, v;
}e[N << 1];
map<int, LL> sum[N];
map<int, int> cnt[N];
void add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}
void dfs(int u, int last){
	cnt[u][c[u]]++;
	sum[u][1] = c[u];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == last) continue;
		dfs(v, u);
		if(cnt[v].size() > cnt[u].size()) {
			swap(cnt[v], cnt[u]);
			swap(sum[v], sum[u]);
		}
		
		for(MIT it = cnt[v].begin(); it != cnt[v].end(); it++) {
			sum[u][cnt[u][it->first]] -= it->first;
			cnt[u][it->first] += it->second;
			sum[u][cnt[u][it->first]] += it->first;
		}
		
		
		cnt[v].clear();
		sum[v].clear();
	}
	
	MLT it = sum[u].end(); it--;
	ans[u] = it->second;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	
	dfs(1, 0);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}