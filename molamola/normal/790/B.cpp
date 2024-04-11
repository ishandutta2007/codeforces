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
typedef long double ldouble;

int n, k;
vector <int> E[200020];

int down[200020], cut[200020];

void pre(int x, int fa){
	down[x] = 1;
	for(int e : E[x])if(cut[e] == 0 && e != fa){
		pre(e, x);
		down[x] += down[e];
	}
}

ll P[5];
ll ans;

void Do(int x, int fa, int L, ll s){
	ans += (L / k) * s;
	int t = L % k;
	for(int i=0;i<k;i++){
		int ti = (i + t);
		if(ti > k)ans += 2 * P[i];
		else if(ti > 0)ans += P[i];
	}
	for(int e : E[x])if(cut[e] == 0 && e != fa){
		Do(e, x, L+1, s);
	}
}

void Ins(int x, int fa, int L){
	P[L % k]++;
	for(int e : E[x])if(cut[e] == 0 && e != fa){
		Ins(e, x, L+1);
	}
}

void dfs(int x, int fa){
	pre(x, -1);
	int c = x, h = down[x] / 2;
	while(1){
		int ok = 1;
		for(int e : E[c])if(cut[e] == 0){
			if(down[e] < down[c] && down[e] > h){c = e; ok = 0; break;}
		}
		if(ok)break;
	}
	x = c;
	rep(i, 5)P[i] = 0;
	P[0] = 1;
	pre(x, -1);
	for(int e : E[x])if(cut[e] == 0){
		Do(e, x, 1, down[x] - down[e]);
		Ins(e, x, 1);
	};
	cut[x] = 1;
	for(int e : E[x])if(cut[e] == 0){
		dfs(e, x);
	}
}

void solve(){
	scanf("%d%d", &n, &k);
	for(int i=1;i<n;i++){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	dfs(1, -1);
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}