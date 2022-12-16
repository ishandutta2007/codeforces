#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;
typedef long long ll;
ll n,m,k,a[maxn][maxn],ans;
map <ll, ll> mp[maxn];
struct node {
	ll x,y,val;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs1() {
	node st = (node){1, 1, a[1][1]};
	queue <node> q;
	while(!q.empty()) q.pop();
	q.push(st);
	while(!q.empty()) {
		node nw = q.front(); q.pop();
		if(nw.x + nw.y - 2 == (n + m - 2) / 2) {
//			printf("1: %lld %lld %lld\n", nw.x, nw.y, nw.val);
			if(mp[nw.x].find(nw.val) == mp[nw.x].end()) mp[nw.x][nw.val] = 1; 
			else mp[nw.x][nw.val]++;
			continue;
		}
		for(int k = 0; k < 2; ++k) {
			node nxt = (node){nw.x + dx[k], nw.y + dy[k], nw.val};
			if(nxt.x > n || nxt.x < 1 || nxt.y > m || nxt.y < 1) continue;
			nxt.val ^= a[nxt.x][nxt.y];
			q.push(nxt);
		}
	}
}

void bfs2() {
	node st = (node){n, m, 0};
	queue <node> q;
	while(!q.empty()) q.pop();
	q.push(st);
	while(!q.empty()) {
		node nw = q.front(); q.pop();
		if(nw.x + nw.y - 2 == (n + m - 2) / 2) {
//			printf("2: %lld %lld %lld\n", nw.x, nw.y, nw.val);
			if(mp[nw.x].find(k ^ nw.val) != mp[nw.x].end())	ans += mp[nw.x][k ^ nw.val];
			continue;
		}
		for(int k = 2; k < 4; ++k) {
			node nxt = (node){nw.x + dx[k], nw.y + dy[k], nw.val ^ a[nw.x][nw.y]};
			if(nxt.x > n || nxt.x < 1 || nxt.y > m || nxt.y < 1) continue;
			q.push(nxt);
		}
	}
}

int main() {
	//freopen(".in", "r", stdin), freopen(".out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%lld", &a[i][j]);
	bfs1(); bfs2();
	printf("%lld\n", ans);
	//fclose(stdin), fclose(stdout);
	return 0;
}