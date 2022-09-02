#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

class edge {
public:
	int s, e, f;
	int of;
	edge() {
		*this = edge(0, 0, 0);
	}
	edge(int s, int e, int f) : s(s), e(e), f(f) {}
};
vector <edge> E;
vector <int> fconn[100050];
void epush(int s, int e, int f) {
	fconn[s].push_back(E.size());
	fconn[e].push_back(E.size() + 1);
	E.emplace_back(s, e, f);
	E.emplace_back(e, s, 0);
}
int dchk[100050];
int DFS(int n, int snk, int C, int F) {
	if (n == snk) return F;
	dchk[n] = C;
	for (auto it : fconn[n]) {
		edge& ed = E[it];
		if (ed.f == 0 || dchk[ed.e] == C) continue;
		int t;
		if (t = DFS(ed.e, snk, C, min(F, ed.f))) {
			ed.f -= t;
			E[it ^ 1].f += t;
			return t;
		}
	}
	return 0;
}
void init(int snk) {
	int i;
	for (i = 0; i <= snk; i++) {
		fconn[i].clear();
		dchk[i] = false;
	}
	E.clear();
}

int dis[605][605];
int in[605];

int main() {
	int V, E, N, K, i, j, k;
	scanf("%d %d %d %d", &V, &E, &N, &K);
	for (i = 1; i <= V; i++) for (j = 1; j <= V; j++) if (i != j) dis[i][j] = INF;
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= E; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		dis[t1][t2] = min(dis[t1][t2], t3);
		dis[t2][t1] = min(dis[t2][t1], t3);
	}
	for (k = 1; k <= V; k++) for (i = 1; i <= V; i++) for (j = 1; j <= V; j++) dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);

	int st = 0, en = 1731312, mi, rv = 1731313;
	while (st <= en) {
		mi = (st + en) / 2;
		
		int src = 0, snk = N + V + 1;
		for (i = 1; i <= N; i++) epush(src, i, 1);
		for (i = 1; i <= V; i++) epush(i + N, snk, 1);
		for (i = 1; i <= N; i++) for (j = 1; j <= V; j++) if (dis[in[i]][j] <= mi) epush(i, j + N, 1);

		int f = 0;
		while (DFS(src, snk, f + 1, INF)) f++;
		init(snk);

		if (f >= K) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	if (rv > 1731311) rv = -1;
	return !printf("%d\n", rv);
}