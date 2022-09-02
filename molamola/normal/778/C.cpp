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
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

const int P1 = 1e9 + 7, P2 = 1e9 + 9;

void add(Pi &a, int x){
	a.Fi = (a.Fi + x) % P1;
	a.Se = (a.Se + x) % P2;
}

void add2(Pi &a, Pi x){
	a.Fi = (a.Fi + x.Fi) % P1;
	a.Se = (a.Se + x.Se) % P2;
}

void mul(Pi &a, int x){
	a.Fi = ((ll)a.Fi * x) % P1;
	a.Se = ((ll)a.Se * x) % P2;
}

void mul2(Pi &a, Pi x){
	a.Fi = ((ll)a.Fi * x.Fi) % P1;
	a.Se = ((ll)a.Se * x.Se) % P2;
}

pii operator-(const pii a, const pii b){
	return pii((a.Fi - b.Fi + P1) % P1, (a.Se - b.Se + P2) % P2);
}

pii operator+(const pii a, const pii b){
	return pii((a.Fi + b.Fi) % P1, (a.Se + b.Se) % P2);
}

vector <Pi> E[300030];
int A[300030], dep[300030];
Pi V[300030], U[300030];
int down[300030], ans[300030];
Pi I = Pi(1, 1);
pii pw[300030];

void pre(int x, int fa){
	down[x] = 1;
	for(pii e : E[x])if(e.Se != fa){
		dep[e.Se] = dep[x] + 1;
		V[e.Se] = V[x];
		pii temp = pii(e.Fi, e.Fi);
		mul2(temp, pw[dep[e.Se]]);
		U[e.Se] = temp;
		add2(V[e.Se], temp);
		pre(e.Se, x);
		down[x] += down[e.Se];
	}
}

void dfs(int x, int fa, set <Pi> &P){
	int mx = -1;
	for(pii e : E[x])if(e.Se != fa){
		if(mx == -1 || down[mx] < down[e.Se])mx = e.Se;
	}
	if(mx == -1){
		P.insert(V[x]);
		return;
	}
	dfs(mx, x, P);
	vector <pii> T, ER;
	for(pii e : E[x])if(e.Se != fa && e.Se != mx){
		set<pii> X;
		dfs(e.Se, x, X);
		for(auto ele : X){
			T.pb(ele);
			auto temp = ele-U[e.Se]+U[mx];
			if(P.find(temp) == P.end())P.insert(temp), ER.pb(temp);
		}
	}
	ans[dep[x]] += (down[x] - sz(P));
	for(auto &e : ER)P.erase(e);
	for(auto &e : T)P.insert(e);
	P.insert(V[x]);
}

void solve(){
	pw[0] = I;
	for(int i=1;i<300030;i++){pw[i] = pw[i-1]; mul(pw[i], 29); }
	int n; scanf("%d", &n);
	rep(i, n-1){
		int x, y;
		char c;
		scanf("%d%d %c", &x, &y, &c);
		c -= 'a' - 1;
		E[x].pb(Pi(c, y));
		E[y].pb(Pi(c, x));
	}
	pre(1, -1);
	set <Pi> t;
	dfs(1, -1, t);
	int tmp = (int)(max_element(ans, ans+n) - ans);
	printf("%d\n%d\n", n - ans[tmp], tmp+1);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case %d: ", tc);
		solve();
	}
	return 0;
}