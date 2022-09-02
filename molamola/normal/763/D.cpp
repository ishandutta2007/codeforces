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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

const int M1 = 1e9 + 7;
const int M2 = 1e9 + 33;
const int P = 13;
const int Q = 1299821;
int IP1, IP2;

int pw(int x, int y, int mod){
	int res = 1;
	while(y){
		if(y & 1)res = (ll)res * x % mod;
		x = (ll)x * x % mod;
		y >>= 1;
	}
	return res;
}

vector <int> E[100010];
int n;
Pi H[100010], R[100010];
void add(Pi &a, Pi b){
	a.Fi = (a.Fi + b.Fi) % M1;
	a.Se = (a.Se + b.Se) % M2;
}

void mul(Pi &a, Pi b){
	a.Fi = ((ll)a.Fi * b.Fi) % M1;
	a.Se = ((ll)a.Se * b.Se) % M2;
}

void dfs(int x, int fa){
	vector <Pi> SH;
	for(int e : E[x])if(e != fa){
		dfs(e, x);
		SH.pb(H[e]);
	}
	H[x] = Pi(1, 1);
	if(sz(SH) == 0){
		return;
	}
	sort(all(SH));
	Pi p = Pi(P, P), mu = Pi(Q, Q);
	for(int i=0;i<sz(SH);i++){
		mul(mu, p);
		Pi temp = mu;
		mul(temp, SH[i]);
		add(H[x], temp);
	}
}

void dfs2(int x, int fa, Pi a){
	R[x] = a;
	vector <t3> SH;
	if(fa != -1)SH.pb(t3(a.Fi, a.Se, fa));
	for(int e : E[x])if(e != fa){
		SH.pb(t3(H[e].Fi, H[e].Se, e));
	}
	sort(all(SH));
	Pi p = Pi(P, P), mu = Pi(Q, Q);
	for(int i=0;i<sz(SH);i++){
		mul(mu, p);
		Pi temp = mu;
		mul(temp, Pi(get<0>(SH[i]), get<1>(SH[i])));
		get<0>(SH[i]) = temp.Fi;
		get<1>(SH[i]) = temp.Se;
	}
	vector <Pi> sum;
	sum.resize(sz(SH));
	rep(i, sz(SH))sum[i].Fi = sum[i].Se = 0;
	add(sum[sz(SH)-1], Pi(get<0>(SH.back()), get<1>(SH.back())));
	for(int i=sz(SH)-2;i>=0;i--){
		add(sum[i], sum[i+1]);
		add(sum[i], Pi(get<0>(SH[i]), get<1>(SH[i])));
	}
	Pi now = Pi(1, 1);
	for(int i=0;i<sz(SH);i++){
		int u = get<2>(SH[i]);
		if(u != fa){
			Pi g = Pi(0, 0);
			if(i != sz(SH)-1){
				g = sum[i+1];
				mul(g, Pi(IP1, IP2));
			}
			Pi temp = now;
			add(temp, g);
			dfs2(u, x, temp);
		}
		add(now, Pi(get<0>(SH[i]), get<1>(SH[i])));
	}
}

int ans[100010];
map <Pi, int> S;

void Do(int x, int fa){
	for(int e : E[x])if(e != fa){
		S[R[e]]++;
		S[H[e]]--;
		if(S[H[e]] == 0)S.erase(H[e]);
		ans[e] = sz(S);
		Do(e, x);
		S[R[e]]--;
		S[H[e]]++;
		if(S[R[e]] == 0)S.erase(R[e]);
	}
}

void solve(){
	IP1 = pw(P, M1-2, M1);
	IP2 = pw(P, M2-2, M2);
	scanf("%d", &n);
	if(n == 1){
		puts("1");
		return;
	}
	rep(i, n-1){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	dfs(1, -1);
	dfs2(1, -1, Pi(0, 0));
	/*
	for(int i=1;i<=n;i++)printf("%d %d\n", H[i].Fi, H[i].Se);
	for(int i=1;i<=n;i++)printf("%d %d\n", R[i].Fi, R[i].Se);
	*/
	for(int i=2;i<=n;i++)S[H[i]]++;
	ans[1] = sz(S);
	Do(1, -1);
	
	//for(int i=1;i<=n;i++)printf("%d\n", ans[i]);
	printf("%d\n", (int)(max_element(ans+1, ans+1+n) - ans));
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}