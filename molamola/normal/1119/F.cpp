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
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

struct str {
	multiset <ll> L, U;
	int k, n;
	ll sum_u;
	void clear() {
		k = n = 0; L.clear(); U.clear();
		sum_u = 0;
	}
	void Ins(ll x) {
		if(szz(U) == 0 || *U.begin() >= x) L.insert(x);
		else U.insert(x), sum_u += x;
		++n;
		fix();
	}
	void Del(ll x) {
		if(L.find(x) != L.end()) L.erase(L.find(x));
		else U.erase(U.find(x)), sum_u -= x;
		--n;
		fix();
	}
	ll get_mxk() { return sum_u; }
	void set_k(int x) {
		k = x;
		fix();
	}
	void fix() {
		int rk = min(k, n);
		if(szz(U) == rk) return;
		while(szz(U) < rk) {
			auto it = --L.end();
			U.insert(*it);
			sum_u += *it;
			L.erase(it);
		}
		while(szz(U) > rk) {
			auto it = U.begin();
			L.insert(*it);
			sum_u -= *it;
			U.erase(it);
		}
	}
} H;

vector <ll> Dx[500050];
ll Add1[250050], Add2[250050];
int Idx1[250050], Idx2[250050], ulv[250050];

int N;
vector <pii> E[250050];
int deg[250050], dmx[250050];

void pdfs(int x, int fa) {
	++deg[x];
	for(pii e : E[x]) if(e.Se != fa) {
		++deg[x];
		pdfs(e.Se, x);
		dmx[x] = max(dmx[x], dmx[e.Se]);
	}
	dmx[x] = max(dmx[x], deg[x]);
}

ll get_val1(int x, int a) { return Add1[x] + Dx[Idx1[x]][a-1]; }
ll get_val2(int x, int a) {
	if(a <= deg[x]) return Add2[x] + Dx[Idx2[x]][a-1];
	else return Add2[x] + Dx[Idx1[x]][a-1];
}
void set_val1(int x, int a, ll val) {
	if(szz(Dx[Idx1[x]]) < a) Dx[Idx1[x]].resize(a);
	Dx[Idx1[x]][a-1] = val - Add1[x];
}
void set_val2(int x, int a, ll val) {
	if(szz(Dx[Idx2[x]]) < a) Dx[Idx2[x]].resize(a);
	Dx[Idx2[x]][a-1] = val - Add2[x];
}

void DFS(int x, int fa, int ul) {
	vector <pii> child;
	for(pii e : E[x]) if(e.Se != fa) {
		ulv[e.Se] = e.Fi;
		DFS(e.Se, x, e.Fi);
		child.pb(pii(dmx[e.Se], e.Se));
	}
	sort(all(child)); reverse(all(child));
	int L = deg[x];
	if(szz(child) >= 2 && L < child[1].Fi) L = child[1].Fi;
	vector <ll> Lx1(L), Lx2(L);
	int mc = szz(child);
	ll sum_x = 0;
	H.clear();
	for(int i=1;i<=L;i++) {
		for(int j=0;j<mc;j++) {
			if(child[j].Fi < i) break;
			int u = child[j].Se;
			if(i > 1) sum_x -= get_val2(u, i - 1);
			sum_x += get_val2(u, i);
			if(i > 1) H.Del(get_val1(u, i - 1) - get_val2(u, i - 1));
			H.Ins(get_val1(u, i) - get_val2(u, i));
		}
		H.set_k(i);
		Lx2[i-1] = H.get_mxk() + sum_x;
		H.Ins(ul);
		Lx1[i-1] = H.get_mxk() + sum_x;
		H.Del(ul);
	}
	
	sum_x = 0;
	for(int i=1;i<mc;i++) {
		int u = child[i].Se;
		sum_x += get_val1(u, child[i].Fi);
	}
	if(szz(child)) {
		Idx1[x] = Idx1[child[0].Se];
		Add1[x] = Add1[child[0].Se] + sum_x + ul;
		Add2[x] = Add1[child[0].Se] + sum_x;
	}
	
	for(int i=1;i<=L;i++) {
		set_val1(x, i, Lx1[i-1]);
		if(i <= deg[x]) set_val2(x, i, Lx2[i-1]);
	}
	
}

int main() {
	scanf("%d", &N);
	ll sum = 0;
	rep(i, N - 1) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		E[x].pb(pii(z, y));
		E[y].pb(pii(z, x));
		sum += z;
	}
	pdfs(1, -1);
	for(int i=1;i<=N;i++) Idx1[i] = i*2-1, Idx2[i] = i*2;
	DFS(1, -1, 0);
	for(int i=0;i<N;i++) {
		if(i == 0) printf("%lld ", sum);
		else if(dmx[1] < i) printf("0 ");
		else {
			printf("%lld ", sum - get_val1(1, i));
		}
	} puts("");
	return 0;
}