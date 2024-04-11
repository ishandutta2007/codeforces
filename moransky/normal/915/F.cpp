#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000005;
typedef long long LL;
typedef pair<int, int> PII;
int n, a[N], f[N], sz[N];
PII b[N];
bool st[N];
int head[N], numE = 0;
LL ans = 0;
struct E{
	int next, v;
}e[N << 1];
void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}
int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}
void inline merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	if(sz[x] > sz[y]) swap(x, y);
	f[x] = y;
	sz[y] += sz[x];
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = make_pair(a[i], i);
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	
	for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
	
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++) {
		PII u = b[i];
		LL s = 1;
		for (int j = head[u.second]; j; j = e[j].next) {
			int v = e[j].v;
			if(st[v]) {
				ans += (LL)u.first * sz[find(v)] * s;
				s += sz[find(v)];
				merge(v, u.second);
			}
		} 
		st[u.second] = true;
	}
	
	
	for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1, st[i] = false;
	
	for (int i = n; i; i--) {
		PII u = b[i];
		LL s = 1;
		for (int j = head[u.second]; j; j = e[j].next) {
			int v = e[j].v;
			if(st[v]) {
				ans -= (LL)u.first * sz[find(v)] * s;
				s += sz[find(v)];
				merge(v, u.second);
			}
		} 
		st[u.second] = true;
	}
	
	
	
	
	printf("%lld\n", ans);
	return 0;
}