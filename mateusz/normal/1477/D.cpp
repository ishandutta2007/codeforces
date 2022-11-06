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

const int N = 500005;

int n, m, a, b;
vector<int> V[N], sons[N], connected[N];
int deg[N], myEdge[N], ansA[N], ansB[N];
bool full[N];

void test() {
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        V[i].clear();
        myEdge[i] = 0;
        deg[i] = 0;
        connected[i].clear();
        sons[i].clear();
        full[i] = false;
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    int totalN = n;
    for (int i = 1; i <= n; i++) {
        V[i].push_back(i);
        sort(V[i].begin(), V[i].end());
        for (int j = 0; j < V[i].size(); j++) {
            if (j + 1 != V[i][j]) {
                myEdge[i] = j + 1;
                break;
            }
        }
        if (myEdge[i] == 0) {
            if (V[i].size() == n) {
                ansA[i] = totalN;
                ansB[i] = totalN;
                totalN--;
                full[i] = true;
                continue;
            }
            myEdge[i] = V[i].size() + 1;
        }
    }
    
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (full[i] || vis[i]) continue;
        int w = i;
        vis[w] = true;
        while (!vis[myEdge[w]]) {
            w = myEdge[w];
            vis[w] = true;
        }
        if (vis[myEdge[w]] == 1) {
            myEdge[w] = 0;
        }
        int u = w;
        w = i;
        while (w != u) {
            vis[w] = 2;
            w = myEdge[w];
        }
        vis[w] = 2;
    }
    
    for (int i = 1; i <= n; i++) {
        if (full[i] || myEdge[i] == 0) continue;
        deg[myEdge[i]]++;
        sons[myEdge[i]].push_back(i);
    }
    
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (full[i]) continue;
        if (deg[i] == 0) {
            Q.push(i);
        }
    }
    
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop();
        if (connected[w].empty()) {
            if (myEdge[w] != 0) {
                connected[myEdge[w]].push_back(w);
            } else {
                connected[sons[w][0]].push_back(w);
            }
        }
        if (myEdge[w] != 0) {
            deg[myEdge[w]]--;
            if (deg[myEdge[w]] == 0) {
                Q.push(myEdge[w]);
            }
        }
    }
    
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (!connected[i].empty()) {
            ansA[i] = last + 1;
            ansB[i] = last + connected[i].size() + 1;
            
            for (int j = 0; j < connected[i].size(); j++) {
                int u = connected[i][j];
                ansA[u] = last + j + 2;
                ansB[u] = last + j + 1;
            }
            last += connected[i].size() + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ansA[i]);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ansB[i]);
    }
    printf("\n");
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    
    return 0;
}