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
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n, m;
const int MOD = 1e9 + 7;
struct node{
	int p[2][2];
	node operator*(node &A){
		node res;
		rep(i, 2)rep(j, 2){
			res.p[i][j] = 0;
			rep(k, 2)res.p[i][j] = (res.p[i][j] + p[i][k] * (ll)A.p[k][j]) % MOD;
		}
		return res;
	}
	void init1(){
		p[0][0] = 1;
		p[0][1] = 1;
		p[1][0] = 1;
		p[1][1] = 0;
	}
	void init0(){
		rep(i, 2)rep(j, 2)p[i][j] = i == j;
	}
};

node A[270000];
node T[270000];

void update(int rt, int s, int d, int l, int r, node &a){
	if(l <= s && d <= r){
		A[rt] = A[rt] * a;
		T[rt] = T[rt] * a;
		return;
	}
	T[rt+rt] = T[rt+rt] * A[rt];
	T[rt+rt+1] = T[rt+rt+1] * A[rt];
	A[rt+rt] = A[rt+rt] * A[rt];
	A[rt+rt+1] = A[rt+rt+1] * A[rt];
	A[rt].init0();
	int m = (s+d)>>1;
	if(l<=m)update(rt+rt, s, m, l, r, a);
	if(m<r)update(rt+rt+1, m+1, d, l, r, a);
	rep(i, 2)rep(j, 2)T[rt].p[i][j] = (T[rt<<1].p[i][j] + T[rt<<1|1].p[i][j]) % MOD;
}

void update(int L, int R, int x){
	node X, res;
	X.init1();
	res.init0();
	while(x){
		if(x & 1)res = res * X;
		X = X * X;
		x >>= 1;
	}
	update(1, 1, n, L, R, res);
}

int read(int rt, int s, int d, int l, int r){
	if(l <= s && d <= r){
		return T[rt].p[1][0];
	}
	T[rt+rt] = T[rt+rt] * A[rt];
	T[rt+rt+1] = T[rt+rt+1] * A[rt];
	A[rt+rt] = A[rt+rt] * A[rt];
	A[rt+rt+1] = A[rt+rt+1] * A[rt];
	A[rt].init0();
	int res = 0;
	int m = (s+d)>>1;
	if(l<=m)res = read(rt<<1, s, m, l, r);
	if(m<r)res = (res + read(rt<<1|1, m+1, d, l, r)) % MOD;
	return res;
}

void solve(int tc){
	scanf("%d%d", &n, &m);
	rep(i, 270000)A[i].init0(), T[i].init0();
	rep(i, n){
		int x; scanf("%d", &x);
		update(i+1, i+1, x);
	}
	rep(i, m){
		int x; scanf("%d", &x);
		if(x == 1){
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			update(a, b, c);
		}
		else{
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", read(1, 1, n, a, b));
		}
	}
}

int main(){
	int Tc = 1;//; scanf("%d\n", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		solve(tc);
	}
	return 0;
}