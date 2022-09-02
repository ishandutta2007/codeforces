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
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int q;
int D[1000010][20];
const int MOD = 1e9 + 7;
vector <int> P[1000010];
int isp[1000010];

void solve(){
	for(int i=2;i<=1000000;i++)isp[i] = 1;
	for(int i=2;i<=1000000;i++){
		if(isp[i]){
			P[i].pb(1);
			for(int j=i+i;j<=1000000;j+=i){
				int cnt = 0, t = j;
				while(t % i == 0)cnt++, t /= i;
				P[j].pb(cnt);
				isp[j] = 0;
			}
		}
	}
	D[0][0] = 1;
	for(int i=1;i<20;i++)D[0][i] = 2;
	for(int i=1;i<=1000000;i++){
		D[i][0] = 1;
		for(int j=1;j<20;j++){
			D[i][j] = (D[i][j-1] + D[i-1][j]) % MOD;
		}
	}
	int q; scanf("%d", &q);
	while(q--){
		int r, n; scanf("%d%d", &r, &n);
		ll ans = 1;
		for(int e : P[n]){
			ans = (ans * D[r][e]) % MOD;
		}
		printf("%lld\n", ans);
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}