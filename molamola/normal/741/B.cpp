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

int n, m, w;
int p[1010];
int tw[1010], tb[1010];
int Find(int x){
	return p[x] == x ? x : p[x] = Find(p[x]);
}

int W[1010], B[1010];
int d[2][1010];

void solve(){
	scanf("%d%d%d", &n, &m, &w);
	for(int i=1;i<=n;i++)scanf("%d", W+i);
	for(int i=1;i<=n;i++)scanf("%d", B+i);
	for(int i=1;i<=n;i++){
		p[i] = i;
		tw[i] = W[i]; tb[i] = B[i];
	}
	rep(i, m){
		int x, y; scanf("%d%d", &x, &y);
		x = Find(x), y = Find(y);
		if(x == y)continue;
		p[x] = y;
		tb[y] += tb[x]; tw[y] += tw[x];
	}
	int a = 1;
	for(int i=1;i<=n;i++){
		if(Find(i) == i){
			for(int j=0;j<=w;j++)d[a][j] = d[a^1][j];
			for(int j=tw[i];j<=w;j++){
				d[a][j] = max(d[a][j], d[a^1][j - tw[i]] + tb[i]);
			}
			for(int j=1;j<=n;j++)if(Find(j) == i){
				for(int k=W[j];k<=w;k++){
					d[a][k] = max(d[a][k], d[a^1][k - W[j]] + B[j]);
				}
			}
			a ^= 1;
		}
	}
	printf("%d", d[a^1][w]);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}