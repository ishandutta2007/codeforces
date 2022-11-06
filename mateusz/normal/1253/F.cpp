#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 300005;
const long long INF = 1e18;

int n, m, k, q, a, b, c;
int A[N], B[N], C[N];
bool done[N];
int rep[N];
long long ans[N];
long long dist[N];
int from[N];
vector<pair<int, int> > V[N], queries[N];

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        done[i] = false;
    }
    priority_queue<pair<long long, int> > Q;
    for (int i = 1; i <= k; i++) {
        dist[i] = 0;
        from[i] = i;
        Q.push({0, i});
    }
    
    while (!Q.empty()) {
        int w = Q.top().second;
        Q.pop();
        if (done[w]) continue;
        done[w] = true;
        for (auto edge : V[w]) {
            int u = edge.first;
            int kr = edge.second;
            if (dist[u] > dist[w] + kr) {
                dist[u] = dist[w] + kr;
                from[u] = from[w];
                Q.push({-dist[u], u});
            }
        }
    }
}

int find(int w) {
    return rep[w] = w == rep[w] ? w : find(rep[w]);
}

void Union(int a, int b, long long c) {
    if (queries[a].size() > queries[b].size()) {
        swap(a, b);
    }
    for (auto query : queries[a]) {
        int w = query.first;
        int id = query.second;
        if (find(w) == b) {
            ans[id] = c;
        } else {
            queries[b].push_back({w, id});
        }
    }
    queries[a].clear();
    rep[a] = b;
}

int main() {
    
    scanf("%d %d %d %d", &n, &m, &k, &q);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        V[a].push_back({b, c});
        V[b].push_back({a, c});
        A[i] = a;
        B[i] = b;
        C[i] = c;
    }
    
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &a, &b);
        queries[a].push_back({b, i});
        queries[b].push_back({a, i});
    }
    
    dijkstra();
    
    vector<pair<long long, pair<int, int> > > edges;
    for (int i = 1; i <= m; i++) {
        a = A[i], b = B[i];
        if (from[a] != from[b]) {
            edges.push_back({dist[a] + dist[b] + C[i], {from[a], from[b]}});
        }
    }
    
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= k; i++) {
        rep[i] = i;
    }
    
    for (int i = 0; i < edges.size(); i++) {
        long long c = edges[i].first;
        int a = find(edges[i].second.first);
        int b = find(edges[i].second.second);
        if (a == b) continue;
        Union(a, b, c);
    }
    
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }
    
    return 0;
}