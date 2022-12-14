#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef pair <int, int> pii;
#define fi first
#define se second
const int dx[3] = {-1, 0, 1};

char tunnel[4][105];
int n, k, testcase;
bool vis[4][105];
queue <pii> q;

int main(){
	int i, j; bool flag; pii now;
	scanf("%d", &testcase);
	while(testcase --){
		memset(vis, false, sizeof(vis));
		while(!q.empty()) q.pop();
		scanf("%d%d", &n, &k);
		for(i = 1; i <= 3; ++ i) scanf("%s", tunnel[i] + 1);
		for(i = 1; i <= 3; ++ i)
			if(tunnel[i][1] == 's'){
				q.push(pii(i, 1));
				vis[i][1] = true;
				break;
			}
		flag = false;
		while(!q.empty()){
			now = q.front(); q.pop();
			if(now.se == n){
				flag = true;
				printf("YES\n");
				break;
			}
			if(tunnel[now.fi][now.se + 1] != '.') continue;
			for(i = 0; i < 3; ++ i){
				now.fi += dx[i];
				if(now.fi < 1 || now.fi > 3){
					now.fi -= dx[i];
					continue;
				}
				for(j = 1; j <= 3; ++ j){
					if(now.se + j > n){
						printf("YES\n");
						flag = true;
						break;
					}
					if(tunnel[now.fi][now.se + j] != '.') break;
				}
				if(flag) break;
				if(j == 4 && !vis[now.fi][now.se + 3]){
					now.se += 3;
					vis[now.fi][now.se] = true;
					q.push(now);
					now.se -= 3;
				}
				now.fi -= dx[i];
			}
			if(flag) break;
		}
		if(!flag) printf("NO\n");
	}
	return 0;
}