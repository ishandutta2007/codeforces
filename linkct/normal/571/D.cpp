#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 500005;
typedef pair <int, int> pii;
typedef long long int ll;

struct Query{
	int x, y; char type;
}q[MAXN];
int n, m, elem, f[MAXN << 1], cur[MAXN], timeStamp[MAXN << 1], size[MAXN << 1];
ll ans[MAXN], delta[MAXN << 1];
vector <Query> lastRaid[MAXN];

int find(int x){
	if(f[x] == f[f[x]]) return f[x];
	int ret = find(f[x]);
	timeStamp[x] = max(timeStamp[x], timeStamp[f[x]]);
	delta[x] += delta[f[x]];
	return f[x] = ret;
}
int merge(int u, int v){
	size[++ elem] = size[u] + size[v];
	return f[u] = f[v] = elem;
}
ll query(int x){
	find(x);
	if(f[x] == x) return delta[x];
	return delta[x] + delta[f[x]];
}
int main(){
	int i, j, cnt = 0; char buf[5];
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i){
		scanf("%s%d", buf, &q[i].x);
		q[i].type = buf[0];
		if(buf[0] == 'U' || buf[0] == 'M') scanf("%d", &q[i].y);
		else if(buf[0] == 'Q') q[i].y = ++ cnt;
	}
	for(i = 1; i < n * 2; ++ i) f[i] = i, size[i] = 1;
	for(i = 1; i <= n; ++ i) cur[i] = i;
	for(i = 1, elem = n; i <= m; ++ i)
		if(q[i].type == 'M') cur[q[i].x] = merge(cur[q[i].x], cur[q[i].y]);
		else if(q[i].type == 'Z') timeStamp[cur[q[i].x]] = i;
		else if(q[i].type == 'Q') lastRaid[max(timeStamp[q[i].x], timeStamp[find(q[i].x)])].push_back(q[i]);
	for(i = 1; i < n * 2; ++ i) f[i] = i, size[i] = 1;
	for(i = 1; i <= n; ++ i) cur[i] = i;
	for(i = 1, elem = n; i <= m; ++ i){
		if(q[i].type == 'U') cur[q[i].x] = merge(cur[q[i].x], cur[q[i].y]);
		else if(q[i].type == 'A') delta[cur[q[i].x]] += size[cur[q[i].x]];
		else if(q[i].type == 'Q') ans[q[i].y] += query(q[i].x);
		for(j = 0; j < int(lastRaid[i].size()); ++ j)
			ans[lastRaid[i][j].y] -= query(lastRaid[i][j].x);
	}
	for(i = 1; i <= cnt; ++ i) printf("%I64d\n", ans[i]);
	return 0;
}