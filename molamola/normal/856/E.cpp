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
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int R, N;
int L;
pii q[500050];
vector <t3> P;
vector <t3> query;
pii Lx[500050];

int T[1<<20]; const int ADD = 1<<19;
set <int> Sx[500050], Sy[500050];

void Ins(int x, int y) {
	Sx[x].insert(y);
	Sy[y].insert(x);
	T[x+ADD] = *Sx[x].begin(); x = (x + ADD) >> 1;
	while(x) T[x] = min(T[x<<1], T[x<<1|1]), x >>= 1;
}
void Del(int x, int y) {
	Sx[x].erase(y);
	Sy[y].erase(x);
	int v = (szz(Sx[x]) ? *Sx[x].begin() : 1e9);
	T[x+ADD] = v; x = (x + ADD) >> 1;
	while(x) T[x] = min(T[x<<1], T[x<<1|1]), x >>= 1;
}

int read_t(int l, int r) {
	l += ADD, r += ADD;
	int res = 1e9;
	while(l <= r) {
		if(l & 1) res = min(res, T[l++]);
		if(!(r & 1)) res = min(res, T[r--]);
		l >>= 1, r >>= 1;
	}
	return res;
}

int del_x, del_y;
int Query(int x, int y) {
	int xv = max(Lx[x].Fi, Lx[y].Fi);
	int yv = max(Lx[x].Se, Lx[y].Se);
	del_x = 0, del_y = 0;
	if(Lx[x].Fi < Lx[y].Fi && Lx[x].Se < Lx[y].Se) del_x = 1;
	if(Lx[y].Fi < Lx[x].Fi && Lx[y].Se < Lx[x].Se) del_y = 1;
	if(del_x) Del(Lx[x].Fi, Lx[x].Se);
	if(del_y) Del(Lx[y].Fi, Lx[y].Se);
	if(read_t(1, xv - 1) <= yv - 1) return 0;
	int w1 = -1, w2 = -1;
	if(Lx[x].Fi == xv) w1 = Lx[x].Se;
	if(Lx[y].Fi == xv) w2 = Lx[y].Se;
	for(auto it=Sx[xv].begin();it!=Sx[xv].end();++it) {
		if(*it > yv) break;
		if(*it != w1 && *it != w2) return 0;
	}
	w1 = w2 = -1;
	if(Lx[x].Se == yv) w1 = Lx[x].Fi;
	if(Lx[y].Se == yv) w2 = Lx[y].Fi;
	for(auto it=Sy[yv].begin();it!=Sy[yv].end();++it) {
		if(*it > xv) break;
		if(*it != w1 && *it != w2) return 0;
	}
	
	pii v1, v2;
	if(Lx[x].Fi >= Lx[y].Fi) v1 = pii(q[x].Fi + R, q[x].Se);
	else v1 = pii(q[y].Fi + R, q[y].Se);
	if(Lx[x].Se >= Lx[y].Se) v2 = pii(q[x].Fi - R, q[x].Se);
	else v2 = pii(q[y].Fi - R, q[y].Se);
	if((ll)v1.Fi * v2.Fi + (ll)v1.Se * v2.Se >= 0) return 1;
	return 0;
}

int main() {
	scanf("%d%d", &R, &N);
	for(int i=1;i<=N;i++) {
		int cmd; scanf("%d", &cmd);
		if(cmd == 1) {
			int x, y; scanf("%d%d", &x, &y);
			P.pb(t3(x, y, ++L));
			q[L] = pii(x, y);
			query.pb(t3(1, L, -1));
		}
		else if(cmd == 2) {
			int x; scanf("%d", &x);
			query.pb(t3(2, x, -1));
		}
		else {
			int x, y; scanf("%d%d", &x, &y);
			query.pb(t3(3, x, y));
		}
	}
	int xz = 1, yz = 1;
	auto comp = [&](const t3 &a, const t3 &b) {
		return (ll)(get<0>(a)+R) * get<1>(b) - (ll)get<1>(a) * (get<0>(b)+R) < 0;
	};
	sort(all(P), comp);
	for(int i=0;i<szz(P);i++) {
		Lx[get<2>(P[i])].Fi = xz;
		if(i < szz(P)-1 && comp(P[i], P[i+1])) ++xz;
	}
	auto comp2 = [&](const t3 &a, const t3 &b) {
		return (ll)(get<0>(a)-R) * get<1>(b) - (ll)get<1>(a) * (get<0>(b)-R) > 0;
	};
	sort(all(P), comp2);
	for(int i=0;i<szz(P);i++) {
		Lx[get<2>(P[i])].Se = yz;
		if(i < szz(P)-1 && comp2(P[i], P[i+1])) ++yz;
	}
	
	rep(i, 1<<20) T[i] = 1e9;
//	for(int i=1;i<=L;i++) printf("%d %d\n", Lx[i].Fi, Lx[i].Se);
	
	for(t3 e : query) {
		int cmd, x, y;
		tie(cmd, x, y) = e;
		if(cmd == 1) {
			int xv = Lx[x].Fi, yv = Lx[x].Se;
			Ins(xv, yv);
		}
		else if(cmd == 2) {
			int xv = Lx[x].Fi, yv = Lx[x].Se;
			Del(xv, yv);
		}
		else {
			int v = Query(x, y);
			if(del_x) Ins(Lx[x].Fi, Lx[x].Se);
			if(del_y) Ins(Lx[y].Fi, Lx[y].Se);
			
			printf("%s\n", v ? "YES" : "NO");
		}
	}
	
	return 0;
}