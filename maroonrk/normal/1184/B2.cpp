#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <class T> void chmax(T &t, const T &f) { if (t < f) t = f; }


//	Hopcroft-Karp
namespace BM {
	const int LIM_N0 = 1010;
	const int LIM_N1 = 1010;
	const int LIM_M = 1000010;
	int n0, n1, m, ptr[LIM_N0], nxt[LIM_M], zu[LIM_M];
	int to[LIM_N0], fr[LIM_N1], used[LIM_N0], tof;
	int lev[LIM_N0], que[LIM_N0], *qb, *qe;
	void init(int _n0, int _n1) {
		n0 = _n0; n1 = _n1; m = 0; fill(ptr, ptr + n0, -1);
	}
	void ae(int u, int v) {
		nxt[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
	}
	int augment(int u) {
		used[u] = tof;
		for (int i = ptr[u]; ~i; i = nxt[i]) {
			const int v = zu[i];
			const int w = fr[v];
			if (!~w || (used[w] != tof && lev[u] < lev[w] && augment(w))) {
				to[u] = v; fr[v] = u; return 1;
			}
		}
		return 0;
	}
	int solve() {
		fill(to, to + n0, -1); fill(fr, fr + n1, -1); fill(used, used + n0, -1);
		for (tof = 0; ; ) {
			qb = qe = que; fill(lev, lev + n0, -1);
			for (int u = 0; u < n0; ++u) if (!~to[u]) lev[*qe++ = u] = 0;
			for (; qb != qe; ) {
				const int u = *qb++;
				for (int i = ptr[u]; ~i; i = nxt[i]) {
					const int w = fr[zu[i]];
					if (~w && !~lev[w]) lev[*qe++ = w] = lev[u] + 1;
				}
			}
			int f = 0;
			for (int u = 0; u < n0; ++u) if (!~to[u]) f += augment(u);
			if (!f) return tof;
			tof += f;
		}
	}
}


constexpr int INF = 1001001001;

int N, M;
int U[10010], V[10010];
int S, B;
Int K, H;
int X[1010], A[1010], F[1010];
int Y[1010], D[1010];

int dist[110][110];

int main() {
  for (; ~scanf("%d%d", &N, &M); ) {
    for (int i = 0; i < M; ++i) {
      scanf("%d%d", &U[i], &V[i]);
      --U[i];
      --V[i];
    }
    scanf("%d%d%lld%lld", &S, &B, &K, &H);
    for (int s = 0; s < S; ++s) {
      scanf("%d%d%d", &X[s], &A[s], &F[s]);
      --X[s];
    }
    for (int b = 0; b < B; ++b) {
      scanf("%d%d", &Y[b], &D[b]);
      --Y[b];
    }
    
    for (int u = 0; u < N; ++u) for (int v = 0; v < N; ++v) {
      dist[u][v] = (u == v) ? 0 : INF;
    }
    for (int i = 0; i < M; ++i) {
      chmin(dist[U[i]][V[i]], 1);
      chmin(dist[V[i]][U[i]], 1);
    }
    for (int w = 0; w < N; ++w) for (int u = 0; u < N; ++u) for (int v = 0; v < N; ++v) {
      chmin(dist[u][v], dist[u][w] + dist[w][v]);
    }
    
    BM::init(S, B);
    for (int s = 0; s < S; ++s) for (int b = 0; b < B; ++b) {
      if (A[s] >= D[b] && F[s] >= dist[X[s]][Y[b]]) {
        BM::ae(s, b);
      }
    }
    const Int res = BM::solve();
cerr<<"res = "<<res<<endl;
    
    Int ans = H * S;
    for (Int z = 0; z <= S; ++z) {
      const Int score = K * min(res, S - z) + H * z;
      chmin(ans, score);
    }
    printf("%lld\n", ans);
  }
  return 0;
}