#include <iostream>
#include <utility>
#include <stdlib.h>
#define enc(x, y) (x+(y-1)*n)
#define inf 1e9

using namespace std;
typedef pair<int, int> P;

int n, N;
int map[15][15];
int pos[105];
P G[305][305], dist[305][305];
P dp[105][3];

P add(P a, P b){
	return make_pair(a.first+b.first, a.second+b.second);
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> map[i][j];
			pos[map[i][j]] = enc(i, j);
		}
	}
	N = n*n;
	
	for(int i = 1; i <= 3*N; i++){
		for(int j = 1; j <= 3*N; j++){
			G[i][j] = make_pair(inf, inf);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int v = enc(i, j);
			G[v][v+N] = G[v+N][v] = make_pair(1, 1);
			G[v+N][v+2*N] = G[v+2*N][v+N] = make_pair(1, 1);
			G[v+2*N][v] = G[v][v+2*N] = make_pair(1, 1);
		}
	}
	
	for(int k = 0; k < 3; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int v = enc(i, j) + k*N;
				for(int ni = 1; ni <= n; ni++){
					for(int nj = 1; nj <= n; nj++){
						int nv = enc(ni, nj) + k*N;
						
						if(v == nv){
							G[v][nv] = make_pair(0, 0);
							continue;
						}
						if(k == 0){  //k
							if(abs(i-ni)+abs(j-nj) == 3 && i != ni && j != nj){
								G[v][nv] = make_pair(1, 0);
							}
							//else G[v][nv] = make_pair(inf, inf);
						}
						if(k == 1){  //b
							if(i+j == ni+nj || i-j == ni-nj){
								G[v][nv] = make_pair(1, 0);
							}
							//else G[v][nv] = make_pair(inf, inf);
						}
						if(k == 2){  //r
							if(i == ni || j == nj){
								G[v][nv] = make_pair(1, 0);
							}
							//else G[v][nv] = make_pair(inf, inf);
						}
					}
				}
			}
		}
	}
	
	for(int i = 1; i <= 3*N; i++){
		for(int j = 1; j <= 3*N; j++){
			dist[i][j] = G[i][j];
		}
	}
	for(int k = 1; k <= 3*N; k++){
		for(int i = 1; i <= 3*N; i++){
			for(int j = 1; j <= 3*N; j++){
				dist[i][j] = min(add(dist[i][k], dist[k][j]), dist[i][j]);
			}
		}
	}
	
	/*for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(dist[i][j].first >= inf) cout << "x ";
			else cout << dist[i][j].first << " ";
		}
		cout << endl;
	}*/
	
	
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 3; j++){
			dp[i][j] = make_pair(inf, inf);
		}
	}
	dp[1][0] = dp[1][1] = dp[1][2] = make_pair(0, 0);
	
	for(int i = 2; i <= N; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				dp[i][j] = min(add(dp[i-1][k], dist[pos[i-1]+k*N][pos[i]+j*N]), dp[i][j]);
			}
		}
	}
	
	P ans = make_pair(inf, inf);
	for(int i = 0; i < 3; i++) ans = min(ans, dp[N][i]);
	cout << ans.first << " " << ans.second << endl;
	
	return 0;
}