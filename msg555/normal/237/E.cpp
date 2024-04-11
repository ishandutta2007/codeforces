#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

/* Min Cost Flow */
// Heap Dijkstra: O(F*M*Log(N+M))

typedef int itype;

#define MAXV 28*105

// This implementation assumes there are not edges going in both directions
itype cap[MAXV][MAXV]; // capacity (input) this array is changed
itype cost[MAXV][MAXV]; // edge cost (input) this array is changed
itype pi[MAXV]; // node potential (intermediate)
itype d[MAXV]; // distance (intermediate)
int p[MAXV]; // path parent (intermediate)

/* Returns the min cost for the requested flow or "-1" if the flow can't be
 * made. */
itype mcf(int src, int snk, int n, itype flow) {
  // Create back edges
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(cap[i][j])
        cost[j][i] = -cost[i][j];

  memset(pi, 0, sizeof(itype) * n);
  // Main loop.  Keep adding flow until we get to the desired flow or there are
  // no more augmenting paths.
  itype cst = 0;
  for(itype f = 0; f < flow; ) {
    memset(d, 0x3F, sizeof(itype) * n); // infinity
    memset(p, -1, sizeof(int) * n);
    d[src] = 0; p[src] = -2; 
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, src));
    while(!q.empty()) {
      pair<int, int> pr = q.top(); q.pop();
      int best = pr.second;
      if(-pr.first != d[best]) continue;
      for(int i = 0; i < n; i++) {
        if(cap[best][i] && d[best] + cost[best][i] + pi[best] - pi[i] < d[i]) {
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

vector<int> get_cnts(const string& S) {
  vector<int> cnt(26);
  for(int i = 0; i < S.size(); i++) {
    if('a' <= S[i] && S[i] <= 'z') {
      cnt[S[i] - 'a']++;
    }
  }
  return cnt;
}

int main() {
  string T; cin >> T;
  int N; cin >> N;

  int nid = 0;
  int src = nid++;
  int snk = nid++;

  vector<int> tcnt = get_cnts(T);
  vector<int> tids;
  for(int i = 0; i < 26; i++, nid++) {
    tids.push_back(nid);
    cap[src][nid] = tcnt[i];
  }

  for(int i = 0; i < N; i++) {
    string S; cin >> S;
    vector<int> scnt = get_cnts(S);
    int c; cin >> c;

    int snd = nid++;
    cap[snd][snk] = c;
    cost[snd][snk] = i + 1;
    for(int j = 0; j < 26; j++) {
      cap[nid][snd] = scnt[j];
      cap[tids[j]][nid++] = scnt[j];
    }
  }

  cout << mcf(src, snk, nid, T.size()) << endl;
  return 0;
}