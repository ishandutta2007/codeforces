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

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int chk[330][330];
int c[330][330][8][33];
int xx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int yy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, t[33];

void Do(int dep, int x, int y, int d){
	if(dep == n)return;
	if(c[x+165][y+165][d][dep])return;
	c[x+165][y+165][d][dep] = 1;
	for(int i=1;i<=t[dep];i++){
		int tx = x + xx[d] * i;
		int ty = y + yy[d] * i;
		chk[165+tx][165+ty] = 1;
		if(i == t[dep]){
			Do(dep+1, tx, ty, (d+1)%8);
			Do(dep+1, tx, ty, (d+7)%8);
		}
	}
}

void solve(){
	scanf("%d", &n);
	rep(i, n)scanf("%d", t+i);
	Do(0, 0, -1, 2);
	int ans = 0;
	rep(i, 330)rep(j, 330)ans += chk[i][j];
	printf("%d", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}