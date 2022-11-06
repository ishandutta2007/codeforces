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

int n, m, t, a, b;
vector<int> V[N];
int inTime[N], outTime[N];
int par[N];

void DFS(int w) {
    inTime[w] = ++t;
    
    for (int u : V[w]) {
        if (par[w] == u) {
            continue;
        }
        par[u] = w;
        DFS(u);
    }
    
    outTime[w] = ++t;
}

bool isAncestor(int w, int u) {
    return inTime[w] <= inTime[u] && outTime[w] >= outTime[u];
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    par[1] = 1;
    DFS(1);
    
    while (m--) {
        int k;
        scanf("%d", &k);
        vector<int> nodes;
        for (int i = 1; i <= k; i++) {
            int x;
            scanf("%d", &x);
            nodes.push_back(par[x]);
        }
        sort(nodes.begin(), nodes.end(), [&](int a, int b) { return inTime[a] < inTime[b]; });
        bool good = true;
        for (int i = 1; i < nodes.size(); i++) {
            if (!isAncestor(nodes[i - 1], nodes[i])) {
                good = false;
                break;
            }
        }
        printf(good ? "YES\n" : "NO\n");
    }
    
    return 0;
}