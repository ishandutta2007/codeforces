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
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n, b;
int c[5050], d[5050];
int p[5050];
vector <int> E[5050];
ll D[5050][2][5050];
int down[5050];
ll temp[2][5050];

void dfs(int x) {
	down[x] = 1;
	D[x][1][1] = c[x];
	for(int e : E[x]) {
		dfs(e);
		for(int i=0;i<=down[x]+down[e];i++) temp[0][i] = temp[1][i] = 1e18;
		for(int i=0;i<=down[e];i++) {
			for(int j=0;j<=down[x];j++) {
				if(j != down[x]) temp[0][i+j] = min(temp[0][i+j], min(D[e][0][i], D[e][1][i]) + D[x][0][j]);
				temp[1][i+j] = min(temp[1][i+j], D[e][1][i] + D[x][1][j]);
			}
		}
		for(int i=0;i<=down[x]+down[e];i++) D[x][0][i] = temp[0][i], D[x][1][i] = temp[1][i];
		down[x] += down[e];
	}
	for(int i=down[x];i;i--) D[x][0][i] = D[x][0][i-1] + c[x] - d[x];
	D[x][0][0] = 0;
}

void solve(){
	scanf("%d%d", &n, &b);
	for(int i=1;i<=n;i++) {
		scanf("%d%d", c+i, d+i);
		if(i > 1) {
			scanf("%d", p+i);
			E[p[i]].pb(i);
		}
	}
	dfs(1);
	int ans = 0;
	for(int i=1;i<=n;i++) if(min(D[1][0][i], D[1][1][i]) <= b) ans = i;
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
};