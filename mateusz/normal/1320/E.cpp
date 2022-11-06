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

const int N = 200005, LOG = 18;

int n, k;
int a, b;
vector<int> V[N];
bool vis[N];
int inTime[N], outTime[N], timer;
int par[N][LOG + 5];
int parent[N];
int depth[N];

vector<pair<int, int> > G[N];
int dist[N], source[N];

void DFS(int w) {
    inTime[w] = ++timer;
    vis[w] = true;
    par[w][0] = parent[w];
    for (int i = 1; i < LOG; i++) {
        par[w][i] = par[par[w][i - 1]][i - 1];
    }
    
    for (int u : V[w]) {
        if (!vis[u]) {
            parent[u] = w;
            depth[u] = depth[w] + 1;
            DFS(u);
        }
    }
    outTime[w] = ++timer;
}

bool isAncestor(int anc, int w) {
    return inTime[anc] <= inTime[w] && outTime[anc] >= outTime[w];
}

int LCA(int a, int b) {
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = par[a][i];
        }
    }
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[b] - (1 << i) >= depth[a]) {
            b = par[b][i];
        }
    }
    
    if (a == b) {
        return a;
    }
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }
    
    return par[a][0];
}


int main() {
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    DFS(1);
    
    int q;
    scanf("%d", &q);
    
    while (q--) {
        int virNo, nodesNo;
        scanf("%d %d", &virNo, &nodesNo);
        vector<pair<int, int> > viruses;
        vector<int> queryNodes;
        vector<int> nodes;
        for (int i = 0; i < virNo; i++) {
            int init, speed;
            scanf("%d %d", &init, &speed);
            viruses.push_back({init, speed});
            nodes.push_back(init);
        }
        for (int i = 0; i < nodesNo; i++) {
            int v;
            scanf("%d", &v);
            queryNodes.push_back(v);
            nodes.push_back(v);
        }
        
        sort(nodes.begin(), nodes.end(), [&](int a, int b) { return inTime[a] < inTime[b]; });
        for (int i = nodes.size() - 1; i > 0; i--) {
            nodes.push_back(LCA(nodes[i], nodes[i - 1]));
        }
        sort(nodes.begin(), nodes.end(), [&](int a, int b) { return inTime[a] < inTime[b]; });
        nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
        
        vector<int> s;
        for (int i = 0; i < nodes.size(); i++) {
            while (!s.empty() && !isAncestor(s.back(), nodes[i])) {
                s.pop_back();
            }
            if (!s.empty()) {
                debug("krawedz", s.back(), nodes[i], depth[nodes[i]] - depth[s.back()]);
                G[s.back()].push_back({nodes[i], depth[nodes[i]] - depth[s.back()]});
                G[nodes[i]].push_back({s.back(), depth[nodes[i]] - depth[s.back()]});
            }
            s.push_back(nodes[i]);
        }
        
        
        for (int i = 0; i < nodes.size(); i++) {
            dist[nodes[i]] = 1e9;
            vis[nodes[i]] = false;
        }
        priority_queue<pair<pair<int, int>, int>> Q;
        for (int i = 0; i < viruses.size(); i++) {
            dist[viruses[i].first] = i;
            source[viruses[i].first] = i;
            Q.push({{-i, viruses[i].first}, 0});
        }
        
        while (!Q.empty()) {
            int w = Q.top().first.second;
            int curDist = Q.top().second;
            Q.pop();
            if (vis[w]) continue;
            vis[w] = true;
            for (auto p : G[w]) {
                int u = p.first;
                int kr = p.second;
                int realDist = curDist + kr;
                int myD = (curDist + viruses[source[w]].second - 1) / viruses[source[w]].second;
                int sonD = (realDist +  viruses[source[w]].second - 1) / viruses[source[w]].second;
                int newDist = dist[w] + virNo * (sonD - myD);
                if (newDist < dist[u]) {
                    dist[u] = newDist;
                    source[u] = source[w];
                    Q.push({{-dist[u], u}, realDist});
                }
            }
        }
        
        for (int u : queryNodes) {
            printf("%d ", source[u] + 1);
        }
        printf("\n");
        
        for (int w : nodes) {
            G[w].clear();
        }
    }
    
    return 0;
}