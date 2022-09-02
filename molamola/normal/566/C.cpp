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

vector <Pi> v[200020];	//pair(length, edge);
int n;
int w[200020];

int erased[200020];
int down[200020];

void dfs(int x, int fa){
	down[x] = 1;
	for(auto it : v[x]){
		if(erased[it.Se] == 0 && it.Se != fa){
			dfs(it.Se, x);
			down[x] += down[it.Se];
		}
	}
}

int fm(int x){
	int half = (down[x] - 1) >> 1;
	while(1){
		int nxt = -1;
		for(auto it : v[x]){
			if(erased[it.Se] == 0 && down[it.Se] < down[x] && down[it.Se] > half){
				nxt = it.Se;
				break;
			}
		}
		if(nxt == -1)break;
		x = nxt;
	}
	return x;
}

double get1(int x,int fa,int len){
	double res = w[x] * sqrt(len);
	for(auto it : v[x]){
		if(it.Se != fa)res += get1(it.Se, x, len + it.Fi);
	}
	return res;
}

double get2(int x,int fa,int len){
	double res = w[x] * sqrt(len) * len;
	for(auto it : v[x]){
		if(it.Se != fa)res += get2(it.Se, x, len + it.Fi);
	}
	return res;
}

int ans;
double res = 2e25;

void solve(int x){
	dfs(x, -1);
	x = fm(x);
	double rx = get2(x, -1, 0);
	if(res > rx)res = rx, ans = x;
	double mx = 0, sum = 0;
	int mxv = -1;
	for(auto it : v[x]){
		if(erased[it.Se] == 0){
			double sub = get1(it.Se, x, it.Fi);
			if(mx < sub)mx = sub, mxv = it.Se;
			sum += sub;
		}
	}
	if(mxv == -1 || mx + mx < sum * (1 + 1e-12));
	else{
		erased[x] = 1;
		solve(mxv);
	}
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", w+i);
	if(n == 1){
		printf("1 0");
		return 0;
	}
	for(int i=1;i<n;i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v[x].pb(Pi(z, y));
		v[y].pb(Pi(z, x));
	}
	solve(1);
	printf("%d %.15f", ans, res);
	return 0;
}