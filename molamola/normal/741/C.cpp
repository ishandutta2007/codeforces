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

int n, a[100010], b[100010];
int vis[200020];
int color[200020];
int P[200020];

void dfs(int x, int c){
	int y = x;
	if(x & 1)y++;
	else y--;
	color[x] = c, color[y] = 3 - c;
	vis[x] = vis[y] = 1;
	if(vis[P[y]] == 0){
		dfs(P[y], c);
	}
}

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d%d", a+i, b+i);
	for(int i=1;i<=n;i++)P[a[i]] = b[i], P[b[i]] = a[i];
	for(int i=1;i<=n+n;i++)if(vis[i] == 0){
		dfs(i, 1);
	}
	for(int i=1;i<=n;i++){
		printf("%d %d\n", color[a[i]], color[b[i]]);
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}