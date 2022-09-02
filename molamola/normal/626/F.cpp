#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

int n, K;
int d[202][202][1002];
int a[202];

const int MOD = 1e9 + 7;

ll dfs(int i,int j,int k){
	if(k < 0 || j < 0 || k > K)return 0;
	if(d[i][j][k] != -1)return d[i][j][k];
	if(i == 0)return j == 0;
	ll res = dfs(i-1, j, k - j*(a[i]-a[i-1])) * (j+1) + dfs(i-1, j+1, k - (j+1)*(a[i]-a[i-1])) * (j+1) + dfs(i-1, j-1, k - (j-1)*(a[i]-a[i-1]));
	return d[i][j][k] = res % MOD;
}

int main(){
	memset(d, -1, sizeof d);
	scanf("%d%d", &n, &K);
	for(int i=1;i<=n;i++)scanf("%d", a+i);
	sort(a+1, a+1+n);
	printf("%lld", dfs(n, 0, K));
	return 0;
}