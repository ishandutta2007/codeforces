#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1e3 + 10;
int fa[maxn],siz[maxn],n,d;

int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }

int main() {
	scanf("%d%d", &n, &d);
	for(int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
	for(int i = 1, x, y, rst = 0; i <= d; ++i) {
		scanf("%d%d", &x, &y);
		x = get(x), y = get(y);
		if(x == y) rst++;
		else fa[x] = y, siz[y] += siz[x];
		priority_queue <int> pq;
		bitset <maxn> vis;
		for(int j = 1; j <= n; ++j)
			if(!vis[get(j)]) vis[get(j)] = 1, pq.push(siz[get(j)]);
		for(int j = 1; j <= rst && (int)pq.size() > 1; ++j) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			pq.push(a + b);
		}
		printf("%d\n", pq.top() - 1);
	}
	return 0;
}