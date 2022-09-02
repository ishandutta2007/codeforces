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
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

pii P[1010], Q[10];
int k, n;

vector <int> X[1010][8];

ll operator^(pii a, pii b){
	return (ll)a.Fi * b.Se - (ll)a.Se * b.Fi;
}

ll operator*(pii a, pii b){
	return (ll)a.Fi * b.Fi + (ll)a.Se * b.Se;
}

pii operator-(pii a, pii b){
	return pii(a.Fi-b.Fi, a.Se-b.Se);
}

int isin(pii a, pii b, pii c){
	return ((b-a) ^ (c-a)) == 0 && (a-c) * (b-c) < 0;
}

int chk[1010][8];

int mat[1010], matI[1010];

int dfs(int x, vector <int> V){
	if(sz(V) > k-1)return 0;
	if(x == sz(V)){
		return 1;
	}
	for(int j=0;j<k;j++)if(mat[j] == -1 && chk[V[x]][j] == 0){
		mat[j] = V[x];
		vector <int> W = V;
		vector <int> temp;
		for(int e : X[V[x]][j])if(matI[e] == -1)W.pb(e), matI[e] = 0, temp.pb(e);
		if(dfs(x+1, W))return 1;
		for(int e : temp)matI[e] = -1;
		mat[j] = -1;
	}
	return 0;
}

void solve(){
	scanf("%d%d", &k, &n);
	rep(i, k)scanf("%d%d", &Q[i].Fi, &Q[i].Se);
	rep(i, n)scanf("%d%d", &P[i].Fi, &P[i].Se);
	rep(i, n)rep(j, k){
		rep(u, n){
			if(isin(P[i], Q[j], P[u])){
				X[i][j].pb(u);
			}
		}
		if(sz(X[i][j]) >= k)X[i][j].clear(), chk[i][j] = 1;
	}
	int ans = 0;
	rep(i, n){
		int ok = 0;
		rep(j, k){
			if(chk[i][j] == 0){
				auto &V = X[i][j];
				rep(u, k)mat[u] = -1;
				rep(u, n)matI[u] = -1;
				for(auto e : V)matI[e] = 0;
				mat[j] = i;
				if(dfs(0, V)){
					ok = 1; break;
				}
			}
		}
		ans += ok;
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}