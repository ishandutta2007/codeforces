#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef pair<ll, ll> PL;
typedef long double ldouble;

int D[82][82][82];
int E[82][82];
int n, k, m;
int ans = -1;

void put(int &a, int b){
	if(a == -1 || a > b)a = b;
}

void solve(){
	scanf("%d%d%d", &n, &k, &m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)E[i][j] = 1e9;
	rep(i, m){
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		E[y][x] = min(E[y][x], z);
	}
	memset(D, -1, sizeof D);
	for(int i=1;i<=n;i++)D[i][i][0] = 0;
	
	for(int u=1;u<k;u++){
		for(int i=1;i<n;i++){
			for(int j=1;j+i<=n;j++){
				int l = j, r = j + i;
				if(E[l][r] != 1e9){
					for(int a=l;a<r;a++)if(D[a][l][u-1] != -1){
						put(D[l][r][u], D[a][l][u-1] + E[l][r]);
					}
				}
				for(int a=l+1;a<r;a++)if(E[a][r] != 1e9){
					if(D[l][a][u-1] != -1)put(D[l][r][u], D[l][a][u-1] + E[a][r]);
				}
				if(E[r][l] != 1e9){
					for(int a=l+1;a<=r;a++)if(D[a][r][u-1] != -1){
						put(D[r][l][u], D[a][r][u-1] + E[r][l]);
					}
				}
				for(int a=l+1;a<r;a++)if(E[a][l] != 1e9){
					if(D[r][a][u-1] != -1)put(D[r][l][u], D[r][a][u-1] + E[a][l]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(D[i][j][k-1] != -1){
		put(ans, D[i][j][k-1]);
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}