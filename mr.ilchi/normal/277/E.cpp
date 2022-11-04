#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <iomanip>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

namespace MCF {
	#define MAXN 200010
	#define MAXM 200010
	#define wint int
	#define cint double
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	const cint cEPS = 1e-9;
	const cint cINF = 1001001001;
	int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
	wint capa[MAXM], tof;
	cint cost[MAXM], toc, d[MAXN], pot[MAXN];
	int vis[MAXN], pree[MAXN];
	void init(int _n) {
		n = _n; m = 0; memset(ptr, ~0, n << 2);
	}
	void ae(int u, int v, wint w, cint c) {
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w; cost[m] = +c; ++m;
		next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
	}
	bool spRep(int src, int ink, wint flo = wINF) {
		wint f;
		cint c, cc;
		int i, u, v;
		memset(pot, 0, n * sizeof(cint));
	//*
		for (bool cont = 1; cont; ) {
			cont = 0;
			for (u = 0; u < n; ++u) for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
				if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
					pot[zu[i]] = pot[u] + cost[i]; cont = 1;
				}
			}
		}
	//*/
		for (toc = 0, tof = 0; tof + wEPS < flo; ) {
			typedef pair<cint,int> node;
			priority_queue< node,vector<node>,greater<node> > q;
			for (u = 0; u < n; ++u) { d[u] = cINF; vis[u] = 0; }
			for (q.push(mp(d[src] = 0, src)); !q.empty(); ) {
				c = q.top().first; u = q.top().second; q.pop();
				if (vis[u]++) continue;
				for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
					cc = c + cost[i] + pot[u] - pot[v = zu[i]];
					if (d[v] > cc) { q.push(mp(d[v] = cc, v)); pree[v] = i; }
				}
			}
			if (!vis[ink]) return 0;
			f = flo - tof;
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; chmin(f, capa[i]); }
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
			tof += f;
			toc += f * (d[ink] - pot[src] + pot[ink]);
			for (u = 0; u < n; ++u) pot[u] += d[u];
		}
		return 1;
	}
}

typedef pair<int,int> pii;

int n;
pii a[1000];

inline int p2 (int x){
	return x*x;
}

inline double dist (pii &A, pii &B){
	return sqrt(p2(A.first-B.first)+p2(A.second-B.second)+0.0);
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].second >> a[i].first;
	sort(a, a+n, greater<pii>());
	MCF::init(2*n+2);
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++) if (a[i].first > a[j].first)
			MCF::ae(i, j + n, 1, dist(a[i], a[j])); 
	for (int i=0; i<n; i++) 
		MCF::ae(2*n, i, 2, 0);
	for (int j=n; j<2*n; j++)
		MCF::ae(j, 2*n+1, 1, 0);
	if (MCF::spRep(2*n, 2*n+1, n-1))
		cout << fixed << setprecision(10) << MCF::toc << endl;
	else
		cout << -1 << endl;
	return 0;
}