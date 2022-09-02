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

int n, m;
vector <int> E[410];
int D[410][410];

double Do(int x){
	vector <int> v[410];
	for(int i=1;i<=n;i++)v[D[x][i]].pb(i);
	double res = 0;
	for(int i=0;i<n;i++){
		if(sz(v[i]) == 0)continue;
		if(sz(v[i]) == 1){ res += 1.0 / n; continue; }
		int chk[410] = {};
		double pp[410] = {};
		for(int e : v[i]){
			int c = sz(E[e]);
			for(int f : E[e]){
				chk[f] = 1;
				pp[f] += 1.0 / (n * c);
			}
		}
		vector <int> w;
		for(int j=1;j<=n;j++)if(chk[j])w.pb(j);
		sort(all(w), [&, pp](int a, int b){return pp[a] > pp[b]; });
		int chk2[410] = {};
		double mx = 0;
		for(int a=1;a<=n;a++){
			double sum = 0;
			for(int e : w){
				if(chk2[D[a][e]] == 0){
					chk2[D[a][e]] = 1;
					sum += pp[e];
				}
			}
			for(int e : w)chk2[D[a][e]] = 0;
			mx = max(mx, sum);
		}
		res += max(mx, 1.0 / n);
	}
	return res;
}

void solve(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)D[i][j] = (i == j ? 0 : 1e9);
	for(int i=1;i<=m;i++){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y); E[y].pb(x);
		D[y][x] = D[x][y] = 1;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	}
	double ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans, Do(i));
	}
	printf("%.12lf\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}