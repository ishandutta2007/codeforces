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
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int N;
vector <int> E[200020];
char ch[200020];
int A[200020];
int down[200020], cut[200020];
ll ans[200020];

void pdfs(int x, int fa) {
	down[x] = 1;
	for(int e : E[x]) if(e != fa && cut[e] == 0) {
		pdfs(e,x);
		down[x] += down[e];
	}
}

ll D[1<<20|5];

void ins_dfs(int x, int fa, int val, int c) {
	val ^= A[x];
	D[val] += c;
	for(int e : E[x]) if(cut[e] == 0 && e != fa) {
		ins_dfs(e, x, val, c);
	}
}

ll Get(int x) {
	ll res = D[x];
	rep(i, 20) res += D[x ^ 1<<i];
	return res;
}

ll find_dfs(int x, int fa, int val) {
	val ^= A[x];
	ll res = Get(val);
	for(int e : E[x]) if(cut[e] == 0 && e != fa) {
		res += find_dfs(e, x, val);
	}
	ans[x] += res;
	return res;
}

int qdfs(int x, int fa, int val) {
	val ^= A[x];
	int res = 0;
	if(__builtin_popcount(val) <= 1) ++res;
	for(int e : E[x]) if(cut[e] == 0 && e != fa) {
		res += qdfs(e, x, val);
	}
	return res;
}

void Do(int x) {
	pdfs(x, -1);
	int h = down[x] / 2;
	while(1) {
		int f = 0;
		for(int e : E[x]) if(cut[e] == 0 && down[e] < down[x] && down[e] > h) {
			x = e; f = 1; break;
		}
		if(f == 0) break;
	}
	++ans[x];
	D[A[x]] = 1;
	for(int e : E[x]) if(cut[e] == 0) {
		ins_dfs(e, x, A[x], 1);
	}
	ll cnt = 0;
	for(int e : E[x]) if(cut[e] == 0) {
		ins_dfs(e, x, A[x], -1);
		cnt += find_dfs(e, x, 0);
		ins_dfs(e, x, A[x], 1);
	}
	for(int e : E[x]) if(cut[e] == 0) ins_dfs(e, x, A[x], -1);
	D[A[x]]--;
	for(int e : E[x]) if(cut[e] == 0) cnt += qdfs(e, x, A[x]);
	ans[x] += cnt / 2;
	cut[x] = 1;
	for(int e : E[x]) if(cut[e] == 0) {
		Do(e);
	}
}

void solve() {
	scanf("%d", &N);
	for(int i=1;i<N;i++) {
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	scanf("%s", ch+1);
	for(int i=1;i<=N;i++) A[i] = 1 << (ch[i] - 'a');
	Do(1);
	for(int i=1;i<=N;i++) {
		printf("%lld ", ans[i]);
	} puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}