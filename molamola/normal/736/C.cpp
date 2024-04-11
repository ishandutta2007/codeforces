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

const int MOD = 1e9 + 7;
ll D[110][42][22];
int n, k;
vector <int> E[110];

void dfs(int x, int fa){
	ll temp[42][22] = {}, temp2[42][22] = {};
	int s = -1;
	for(auto e : E[x])if(e != fa){
		dfs(e, x);
		if(s == -1){
			for(int i=0;i<=k+k;i++)for(int j=0;j<=k;j++)temp[i][j] = D[e][i][j];
			s = 0;
		}
		else{
			for(int i=0;i<=k+k;i++)for(int j=0;j<=k;j++){
				for(int u=0;u<=k+k;u++){
					for(int v=0;v<=k;v++){
						int q = max(j, v);
						if(q + min(i, u) + 1 <= k)q = 0;
						temp2[min(i, u)][q] = (temp[i][j] * D[e][u][v] + temp2[min(i, u)][q]) % MOD;
					}
				}
			}
			for(int i=0;i<=k+k;i++)for(int j=0;j<=k;j++)temp[i][j] = temp2[i][j], temp2[i][j] = 0;
		}
	}
	if(s == -1){
		D[x][0][0] = 1;
		D[x][k+1][1] = 1;
		return;
	}
	for(int i=0;i<=k+k;i++){
		for(int j=0;j<=k;j++){
			int nj = j+1;
			if(j == 0){
				if(i >= k)nj = 1;
				else nj = 0;
			}
			D[x][i+1][nj] = (D[x][i+1][nj] + temp[i][j]) % MOD;
			D[x][0][0] = (D[x][0][0] + temp[i][j]) % MOD;
		}
	}
}

void solve(){
	scanf("%d%d", &n, &k);
	rep(i, n-1){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	dfs(1, -1);
	ll ans = 0;
	for(int i=0;i<=k;i++)ans = (ans + D[1][i][0]) % MOD;
	printf("%lld", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}