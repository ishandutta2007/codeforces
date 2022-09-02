#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n, m;
vector <int> E[2][3030];
int dis[2][3030][3030];
int h[2][3030][4];

void solve(){
	scanf("%d%d", &n, &m);
	rep(i, m){
		int x, y; scanf("%d%d", &x, &y);
		E[0][x].pb(y);
		E[1][y].pb(x);
	}
	rep(u, 2){
		int que[3030] = {};
		for(int i=1;i<=n;i++){
			int *fr = que, *re = que;
			*fr++ = i;
			for(int j=1;j<=n;j++)dis[u][i][j] = -1e6;
			dis[u][i][i] = 0;
			while(fr != re){
				int t = *re++;
				for(int e : E[u][t]){
					if(dis[u][i][e] == -1e6){
						dis[u][i][e] = dis[u][i][t] + 1;
						*fr++ = e;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			int z = 0;
			for(int j=1;j<=n;j++){
				h[u][i][z] = j;
				for(int k=z;k;k--){
					if(dis[u][i][ h[u][i][k] ] > dis[u][i][ h[u][i][k-1] ]){
						swap(h[u][i][k], h[u][i][k-1]);
					}
				}
				z = min(z+1, 3);
			}
		}
	}
	int ans = -10;
	int res[4];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(i!=j){
			rep(k, 3)rep(u, 3){
				int x = h[1][i][k];
				int y = i, z = j;
				int w = h[0][j][u];
				if(x == y || x == z || x == w || y == w || z == w)continue;
				if(ans < dis[0][x][y] + dis[0][y][z] + dis[0][z][w]){
					res[0] = x, res[1] = y, res[2] = z, res[3] = w;
					ans = dis[0][x][y] + dis[0][y][z] + dis[0][z][w];
				}
			}
		}
	}
	rep(i, 4)printf("%d ", res[i]);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}