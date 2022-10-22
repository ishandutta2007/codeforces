#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <cstdio>
#define inf 30000

using namespace std;
typedef pair<int, int> P;

int h, w, k, Q;
int V;
int a[1005][1005];
vector<int> G[1100005];
short d[1100005];
short dist[45][1000005];
vector<int> vec[45];
bool used[45];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

void bfs(int c, short dist[])
{
	queue<int> Q;
	for(int i = 0; i < h*w; i++) dist[i] = inf;
	for(int i = 1; i <= k; i++) used[i] = false;
	
	for(int i = 0; i < vec[c].size(); i++){
		Q.push(vec[c][i]);
		dist[vec[c][i]] = 0;
	}
	used[c] = true;
	
	int v, x, y;
	while(Q.size()){
		v = Q.front();
		Q.pop();
		x = v % w, y = v / w, c = a[x][y];
		
		if(!used[c]){
			used[c] = true;
			for(int i = 0; i < vec[c].size(); i++){
				if(dist[vec[c][i]] < inf) continue;
				dist[vec[c][i]] = dist[v] + 1;
				Q.push(vec[c][i]);
			}
		}
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i], nv = ny*w+nx;
			if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
			if(dist[nv] < inf) continue;
			dist[nv] = dist[v] + 1;
			Q.push(nv);
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &h, &w, &k);
	int p;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			scanf("%d", &p);
			a[x][y] = p;
		}
	}
	
	int n = h*w;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			vec[a[x][y]].push_back(y*w+x);
		}
	}
	for(int i = 1; i <= k; i++){
		bfs(i, d);
		for(int j = 0; j < n; j++) dist[i][j] = d[j];
	}
	
	scanf("%d", &Q);
	int sx, sy, tx, ty;
	for(int q = 0; q < Q; q++){
		scanf("%d %d %d %d", &sy, &sx, &ty, &tx);
		sx--, sy--, tx--, ty--;
		int S = sy*w+sx, T = ty*w+tx;
		
		int ans = abs(sx-tx) + abs(sy-ty);
		for(int i = 1; i <= k; i++){
			ans = min(ans, dist[i][S] + dist[i][T] + 1);
		}
		printf("%d\n", ans);
	}
	flush(cout);
	
	return 0;
}