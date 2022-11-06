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
vector<int> V[N], G[N];
int goalVal[N];
int t[N];

int getMex(int w) {
    sort(G[w].begin(), G[w].end(), [&](int a, int b) { return goalVal[a] < goalVal[b]; });
    int ptr = 0;
    for (int i = 1; i <= n; i++) {
        while (ptr < G[w].size() && ptr > 0 && goalVal[G[w][ptr]] == goalVal[G[w][ptr - 1]]) ptr++;
        if (ptr == G[w].size() || i != goalVal[G[w][ptr]]) {
            return i;
        }
        ptr++;
    }
    assert(false);
}

int main() {
   
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &goalVal[i]);
        t[i] = i;
    }
    sort(t + 1, t + 1 + n, [&](int a, int b) {return goalVal[a] < goalVal[b]; });
    
    for (int i = 1; i <= n; i++) {
        int w = t[i];
        int mex = getMex(w);
        debug(w, mex);
        if (mex != goalVal[w]) {
            printf("-1\n");
            return 0;
        }
        for (int u : V[w]) {
            G[u].push_back(w);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
    return 0;
}