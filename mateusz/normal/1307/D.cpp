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
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 200005;

int n, m, k, special;
bool isSpecial[N];
bool vis[N][2];
int dist[N][2];
int a[N], b[N];
vector<int> V[N];

void BFS(int v, int d) {
    vis[v][d] = true;
    dist[v][d] = 0;
    queue<int> Q;
    Q.push(v);
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop();
        for (int u : V[w]) {
            if (!vis[u][d]) {
                vis[u][d] = true;
                dist[u][d] = dist[w][d] + 1;
                Q.push(u);
            }
        }
    }
}

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 1; i <= k; i++) {
        scanf("%d", &special);
        debug(special);
        isSpecial[special] = true;
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        V[a[i]].push_back(b[i]);
        V[b[i]].push_back(a[i]);
    }
    
    BFS(1, 0);
    BFS(n, 1);
    
    int ans = dist[n][0];
    
    vector<pair<int, int> > events;
    for (int i = 1; i <= n; i++) {
        if (isSpecial[i]) {
            events.push_back({dist[i][0], dist[i][1]});
        }
    }
    sort(events.begin(), events.end());
    int best = 0;
    int furthest = -1;
    for (int i = events.size() - 1; i >= 0; i--) {
//         debug(events[i]);
        if (i < events.size() - 1) {
//             furthest -= events[i + 1].first - events[i].first;
            best = max(best, events[i].first + furthest + 1);
        }
        furthest = max(furthest, events[i].second);
    }
    
    printf("%d\n", min(ans, best));
    
    return 0;
}