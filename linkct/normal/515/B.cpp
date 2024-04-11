#include <cstdio>
#include <queue>
using std :: queue;
const int MAXN = 205;

bool g[MAXN][MAXN];
int n, m, boy, girl, vis[MAXN];//0: unhappy 1: initially happy 2:brought happy 

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}
inline int lcm(int a, int b){return a / gcd(a, b) * b;}
void bfs(int x){
	queue <int> q;
	q.push(x);
	int now, i;
	while(!q.empty()){
		now = q.front();
		q.pop();
		for(i = 0; i < n + m; ++ i)
			if(g[now][i] && vis[i] == 0){
				vis[i] = 2;
				q.push(i);
			}
	}
}
int main(){
	int i, t;
	scanf("%d%d", &n, &m);
	scanf("%d", &boy);
	for(i = 1; i <= boy; ++ i){
		scanf("%d", &t);
		vis[t] = 1;
	}
	scanf("%d", &girl);
	for(i = 1; i <= girl; ++ i){
		scanf("%d", &t);
		vis[t + n] = 1;
	}
	int k = lcm(n, m);
	for(i = 0; i < k; ++ i){
		g[i % n][(i % m) + n] = true;
		g[(i % m) + n][i % n] = true;
	}
	for(i = 0; i < n + m; ++ i)
		if(vis[i] == 1) bfs(i);
	for(i = 0; i < n + m; ++ i)
		if(!vis[i]) break;
	printf("%s\n", i == n + m ? "Yes" : "No");
	return 0;
}