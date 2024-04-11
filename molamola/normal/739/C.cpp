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

int n, m;
ll a[300030];
ll b[300030];

struct node{
	int L[5], len;
	void merge(node a, node b){
		L[0] = b.L[0];
		if(b.L[0] == b.len) L[0] = b.len + a.L[0];
		L[1] = a.L[1];
		if(a.L[1] == a.len) L[1] = a.len + b.L[1];
		L[2] = b.L[2];
		if(b.L[1] == b.len) L[2] = b.len + a.L[2];
		else if(b.L[2] == b.len) L[2] = b.len + a.L[0];
		L[3] = a.L[3];
		if(a.L[0] == a.len) L[3] = a.len + b.L[3];
		else if(a.L[3] == a.len) L[3] = a.len + b.L[1];
		L[4] = max(a.L[4], b.L[4]);
		L[4] = max(L[4], a.L[0] + b.L[3]);
		L[4] = max(L[4], a.L[2] + b.L[1]);
		len = a.len + b.len;
	}
}T[1300010];

void update(int rt, int s, int d, int x){
	if(s == d){
		T[rt].len = 1;
		if(b[x] == 0)rep(i, 5)T[rt].L[i] = 0;
		else{
			rep(i, 5)T[rt].L[i] = 1;
			if(b[x] > 0)T[rt].L[1] = 0;
			else T[rt].L[0] = 0;
		}
		return;
	}
	int m = (s+d) >> 1;
	if(x<=m)update(rt+rt, s, m, x);
	else update(rt+rt+1, m+1, d, x);
	T[rt].merge(T[rt+rt], T[rt+rt+1]);
}

void update(int x){
	update(1, 1, n-1, x);
}

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%lld", a+i);
	for(int i=1;i<n;i++)b[i] = a[i+1] - a[i];
	for(int i=1;i<n;i++)update(i);
	scanf("%d", &m);
	while(m--){
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		if(x != 1){
			b[x-1] += z;
			update(x-1);
		}
		if(y != n){
			b[y] -= z;
			update(y);
		}
		printf("%d\n", T[1].L[4] + 1);
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}