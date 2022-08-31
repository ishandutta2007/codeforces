#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

#define MAXV 10000
#define MAXE 10000

using namespace std;

/* Dinic maxflow with unit capacities O(min(V^2/3, E^1/2)E) or
    O(sqrt(V) * E) on bipartite matching graphs. */
template<class flow_t>
class maxflow_dinic {
 public:
  explicit maxflow_dinic(int N) : N(N), edge_lst(N) {
  }

  void add_edge(int u, int v, flow_t capuv, flow_t capvu) {
    edge_lst[u].push_back(edges.size());
    edge_lst[v].push_back(edges.size());
    edge_map[make_pair(u, v)] = edges.size();
    edges.push_back(make_pair(make_pair(u, v), make_pair(capuv, capvu)));
  }

  flow_t compute(int s, int t) {
    vector<int> dist(N);
    vector<int> vis(N);
    for(flow_t fl = 0; ; ) {
      fill(dist.begin(), dist.end(), -1);
      fill(vis.begin(), vis.end(), 0);
      dist[s] = 0;
      vis[s] = true;

      queue<int> q;
      q.push(s);
      while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < edge_lst[u].size(); i++) {
          int j = edge_lst[u][i];
          pair<int, int> vert = edges[j].first;
          if((vert.first == u ? edges[j].second.first : edges[j].second.second) > 0) {
            int v = vert.first + vert.second - u;
            if(!vis[v]) {
              vis[v] = true;
              dist[v] = dist[u] + 1;
              q.push(v);
            }
          }
        }
      }
      if(!vis[t]) {
        return fl;
      }
      fill(vis.begin(), vis.end(), 0);
      fl += dfs(s, t, 0, dist, vis);
    }
  }

  flow_t flow(int u, int v) {
    __typeof__(edge_map.begin()) it = edge_map.find(make_pair(u, v));
    if(it == edge_map.end()) return 0;
    int eid = it->second;
    return edges[eid].second.second;
  }

 private:
  flow_t dfs(int u, int t, flow_t cp, vector<int>& dist, vector<int>& vis) {
    if(u == t) return cp;

    flow_t fl = 0;
    for(int& i = vis[u]; i < edge_lst[u].size(); i++) {
      int j = edge_lst[u][i];
      pair<int, int> vert = edges[j].first;
      int v = vert.first + vert.second - u;
      if(dist[u] + 1 != dist[v]) continue;

      flow_t ecp = vert.first == u ? edges[j].second.first :
                                     edges[j].second.second;
      if(ecp == 0) continue;
      if(cp) ecp = min(ecp, cp);

      ecp = dfs(v, t, ecp, dist, vis);
      fl += ecp;
      (vert.first == u ? edges[j].second.first : edges[j].second.second) -= ecp;
      (vert.first == u ? edges[j].second.second : edges[j].second.first) += ecp;
      if(cp != 0 && ecp == cp) break;
      if(cp) cp -= ecp;
    }
    return fl;
  }

  int N;
  vector<pair<pair<int, int>, pair<flow_t, flow_t> > > edges;
  vector<vector<int> > edge_lst;
  map<pair<int, int>, int> edge_map;
};

#define INF 0x1FFFFFFF
#define CAPINF 0x1FFFFFFF

template <typename T>
struct maxflow_dinic_neal {
  int V, source, sink;
  int eind, eadj [MAXE], eprev [MAXE], elast [MAXV], start [MAXV];
  int front, back, q [MAXV], dist [MAXV];
  T ecap [MAXE];

  explicit maxflow_dinic_neal(int v) : V(v), eind(0) {
    memset (elast, -1, V * sizeof (int));
  }

  inline void add_edge (int a, int b, T cap1, T cap2) {
    eadj [eind] = b; ecap [eind] = cap1;
    eprev [eind] = elast [a]; elast [a] = eind++;
    eadj [eind] = a; ecap [eind] = cap2;
    eprev [eind] = elast [b]; elast [b] = eind++;
  }

  bool bfs () {
    memset (dist, 63, V * sizeof (int));
    front = back = 0;
    q [back++] = source; dist [source] = 0;

    while (front < back) {
      int top = q [front++];

      for (int i = elast [top]; i != -1; i = eprev [i])
        if (ecap [i] > 0 && dist [top] + 1 < dist [eadj [i]]) {
          dist [eadj [i]] = dist [top] + 1;
          q [back++] = eadj [i];
        }
    }

    return dist [sink] < INF;
  }

  T dfs (int num, T pcap) {
    if (num == sink) return pcap;
    T total = 0;

    for (int &i = start [num]; i != -1; i = eprev [i])
      if (ecap [i] > 0 && dist [num] + 1 == dist [eadj [i]]) {
        T p = dfs (eadj [i], min (pcap, ecap [i]));
        ecap [i] -= p; ecap [i ^ 1] += p;
        pcap -= p; total += p;
        if (pcap == 0) break;
      }

    return total;
  }

  T compute (int _source, int _sink) {
    if (V == 0) return -1;

    source = _source; sink = _sink;
    T total = 0;
    while (bfs ()) {
      memcpy (start, elast, V * sizeof (int));
      total += dfs (source, CAPINF);
    }

    return total;
  }
};

int main() {
  int N, M;
  cin >> N >> M;

  int sn = 2;
  vector<vector<pair<int, int> > > A(N);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    for (int j = 2; j * j <= x; j++) {
      int cnt = 0;
      while (x % j == 0) {
        x /= j;
        cnt++;
      }
      if (cnt) {
        A[i].push_back(make_pair(j, cnt));
      }
    }
    if (x > 1) {
      A[i].push_back(make_pair(x, 1));
    }
    sn += A[i].size();
  }

  int src = 0;
  int snk = 1;
  int pos = 2;
  maxflow_dinic<int> mf(sn);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < A[i].size(); j++, pos++) {
      if (i % 2 == 0) {
        mf.add_edge(src, pos, A[i][j].second, 0);
      } else {
        mf.add_edge(pos, snk, A[i][j].second, 0);
      }
      A[i][j].second = pos;
    }
  }

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    if (x % 2) swap(x, y);
    for (int j = 0; j < A[x].size(); j++) {
      for (int k = 0; k < A[y].size(); k++) {
        if (A[x][j].first == A[y][k].first) {
          mf.add_edge(A[x][j].second, A[y][k].second, 100, 0);
        }
      }
    }
  }

  cout << mf.compute(src, snk) << endl;
}