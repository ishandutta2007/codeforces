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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int, int> t4;
typedef long double ldouble;

int A[122][5], n;
int X[5];
int ans = 1e9 + 7;
int score[6] = {500, 1000, 1500, 2000, 2500, 3000};
int fc[7] = {1, 2, 4, 8, 16, 32, -1};

void dfs(int x){
	if(x == 5){
		
		int sa = 0, sb = 0;
		rep(i, 5) if(A[0][i] != -1) sa += score[X[i]] / 250 * (250 - A[0][i]);
		rep(i, 5) if(A[1][i] != -1) sb += score[X[i]] / 250 * (250 - A[1][i]);
		if(sa > sb){
			int sc[5] = {};
			rep(i, n)rep(j, 5)if(A[i][j] != -1) sc[j]++;
			for(int i=0;i<=4000;i++){
				int ok = 1;
				for(int j=0;j<5;j++){
					int t = sc[j];
					int s = n + i;
					int r = fc[X[j]], l = fc[X[j]+1];
					if(A[0][j] == -1) {
						if(l != -1 && l * t <= s) ok = 0;
						if(r * t > s) ok = 0;
					}
					else{
						int lx = 0, rx = i;
						if(l != -1) lx = max(lx, s / l + 1 - t);
						rx = min(rx, s / r - t);
						if(lx > rx) ok = 0;
					}
					if(ok == 0) break;
				}
				if(ok){ ans = min(ans, i); break; }
			}
		}
		
		return;
	}
	rep(i, 6){
		X[x] = i;
		dfs(x+1);
	}
}

void solve(){
	scanf("%d", &n);
	rep(i, n)rep(j, 5)scanf("%d", A[i]+j);
	dfs(0);
	if(ans == 1e9 + 7) puts("-1");
	else printf("%d\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}