/* Min Cost Flow */
// Heap Dijkstra: O(F*M*Log(N+M))

#include <queue>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

#define MAXV 810

typedef int itype;

// This implementation assumes there are not edges going in both directions
itype cap[MAXV][MAXV]; // capacity (input) this array is changed
double cost[MAXV][MAXV]; // edge cost (input) this array is changed
double pi[MAXV]; // node potential (intermediate)
double d[MAXV]; // distance (intermediate)
int p[MAXV]; // path parent (intermediate)

#define INF 1e300
#define EPS 1e-9

/* Returns the min cost for the requested flow or "-1" if the flow can't be
 * made. */
double mcf(int src, int snk, int n, itype flow) {
  // Create back edges
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(cap[i][j])
        cost[j][i] = -cost[i][j];

  memset(pi, 0, sizeof(pi));
  // Main loop.  Keep adding flow until we get to the desired flow or there are
  // no more augmenting paths.
  double cst = 0;
  for(itype f = 0; f < flow; ) {
    for(int i = 0; i < n; i++) d[i] = INF;
    memset(p, -1, sizeof(int) * n);
    d[src] = 0; p[src] = -2; 
    priority_queue<pair<double, int> > q;
    q.push(make_pair(0.0, src));
    while(!q.empty()) {
      pair<double, int> pr = q.top(); q.pop();
      int best = pr.second;
      if(fabs(pr.first + d[best]) > EPS) continue;
      for(int i = 0; i < n; i++) {
        if(cap[best][i] &&
           d[best] + cost[best][i] + pi[best] - pi[i] + EPS < d[i]) {
          d[i] = d[best] + cost[best][i] + pi[best] - pi[i];
          p[i] = best;
          q.push(make_pair(-d[i], i));
        }
      }
    }
    if(p[snk] == -1) return -1; // requested flow is impossible
    for(int i = 0; i < n; i++) if(p[i] != -1) pi[i] += d[i];

    itype aug_f = flow - f;
    for(int v = snk; v != src; v = p[v]) {
      aug_f = min(aug_f, cap[p[v]][v]);
    }
      
    for(int v = snk; v != src; v = p[v]) {
      int u = p[v];
      cap[u][v] -= aug_f;
      cap[v][u] += aug_f;
      cst += aug_f * cost[u][v];
    }
    f += aug_f;
  }
  return cst;
}

int X[MAXV];
int Y[MAXV];

int main() {
  int N; cin >> N;

  int src = 2 * N;
  int snk = src + 1;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    //X[i] = rand() % 10000; Y[i]= i;
    cap[N + i][snk] = 2;
    cap[src][i] = 1;
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(Y[i] <= Y[j]) continue;
      cap[j][N + i] = 1;
      cost[j][N + i] = sqrt((X[i] - X[j]) * (X[i] - X[j]) +
                        (Y[i] - Y[j]) * (Y[i] - Y[j]));
    }
  }

  double cst = mcf(src, snk, snk + 1, N - 1);
  if(cst < 0) {
    printf("-1\n");
  } else {
    printf("%.11f\n", cst);
  }
}