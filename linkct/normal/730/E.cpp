#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair <int, int> pii;
const int MAXN = 105;

pii s[MAXN], t[MAXN], tmp[MAXN << 1];
int st[MAXN], ed[MAXN], n, ind[MAXN], bit[MAXN << 2];
bool g[MAXN][MAXN];
queue <int> q;

void update(int x, int v){
	for(; x <= 2 * n; x += x & -x)
		bit[x] += v;
}
int query(int x){
	int ret = 0;
	for(; x; x -= x & -x)
		ret += bit[x];
	return ret;
}
int main(){
	int i, u, v, j, now, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d", &u, &v);
		tmp[i * 2 - 1] = s[i] = pii(u, -i);
		tmp[i * 2] = t[i] = pii(u + v, -i);
	} sort(tmp + 1, tmp + 1 + n * 2);
	for(i = 1; i <= n; ++ i){
		st[i] = n * 2 - (lower_bound(tmp + 1, tmp + 1 + n * 2, s[i]) - tmp) + 1;
		ed[i] = n * 2 - (lower_bound(tmp + 1, tmp + 1 + n * 2, t[i]) - tmp) + 1;
	}
	for(i = 1; i <= n; ++ i)
		if(st[i] < ed[i]){
			for(j = 1; j <= n; ++ j)
				if(st[j] < ed[j] && st[j] > st[i] && ed[j] > ed[i])
					g[i][j] = true, ++ ind[j];
		}else if(st[i] > ed[i]){
			for(j = 1; j <= n; ++ j)
				if(st[j] > ed[j] && st[j] < st[i] && ed[j] < ed[i])
					g[i][j] = true, ++ ind[j];
		}
	for(i = 1; i <= n; ++ i){
		update(st[i], 1);
		if(!ind[i]) q.push(i);
	}
	while(!q.empty()){
		now = q.front(); q.pop();
		if(st[now] < ed[now]) ans += query(ed[now]) - query(st[now]);
		else if(st[now] > ed[now]) ans += query(st[now]) - query(ed[now]) - 1;
		update(st[now], -1), update(ed[now], 1);
		for(i = 1; i <= n; ++ i)
			if(g[now][i] && !(-- ind[i]))
				q.push(i);
	} printf("%d\n", ans);
	return 0;
}