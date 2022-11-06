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

const int N = 100005;

int n, a, b;
vector<pair<int, int> > V[N];
int ans[N];

int cntUp, cntDown;


void DFS(int w, int par = -1, int parEdge = -1) {
    debug(w, V[w].size());
    if (V[w].size() == 1 && par != -1) {
//         debug(parEdge)
        ans[parEdge] = cntUp;
        cntUp++;
    } else if (par != -1) {
//         debug(cntDown, parEdge);
        ans[parEdge] = cntDown;
        cntDown--;
    }
    
    for (auto p : V[w]) {
        int u = p.first;
        int kr = p.second;
        if (par == u) continue;
        DFS(u, w, kr);
    }
}

int main() {
    
    scanf("%d", &n);
    cntUp = 0;
    cntDown = n - 2;
    
    if (n == 2) {
        printf("0\n");
        return 0;
    }
    
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back({b, i});
        V[b].push_back({a, i});
    }
    
    for (int i = 1; i <= n; i++) {
        if (V[i].size() > 1) {
            DFS(i);
            break;
        }
    }
    
    for (int i = 1; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    
    
    
    return 0;
}