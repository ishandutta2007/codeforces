/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

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

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAXN = 80+5;

int n,m;
int mat[MAXN][MAXN];

namespace MCF {
	#define MAXN 100010
	#define MAXM 100010
	#define wint int
	#define cint int
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	const cint cEPS = 0;
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
};


int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> mat[i][j];
	MCF::init(n*m+2);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++){
			if (i%2 == j%2){
				MCF::ae(n*m, i*m+j, 1, 0);
				for (int k=0; k<4; k++){
					int ii = i + dx[k];
					int jj = j + dy[k];
					if (ii<0 || ii>=n || jj<0 || jj>=m) continue;
					MCF::ae(i*m+j, ii*m+jj, 1, mat[i][j]!=mat[ii][jj]);
				}
			}
			else
				MCF::ae(i*m+j, n*m+1, 1, 0);
		}
	MCF::spRep(n*m,n*m+1,n*m/2);
	cout << ::MCF::toc << endl;
	return 0;
}