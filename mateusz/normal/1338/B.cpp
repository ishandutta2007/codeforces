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
vector<int> V[N];
bool isLeaf[2];
int cntBad;
bool used[N];

void DFS(int w, int d, int par = -1) {
    if (V[w].size() == 1) {
        isLeaf[d] = true;
        if (used[par]) {
            cntBad++;
        }
        used[par] = true;
    }
    for (int u : V[w]) {
        if (par == u) {
            continue;
        }
        DFS(u, d ^ 1, w);
    }
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (V[i].size() >= 2) {
            DFS(i, 0);
            break;
        }
    }
    int mini = (!isLeaf[0] || !isLeaf[1]) ? 1 : 3;
    int maxi = n - cntBad - 1;
    printf("%d %d\n", mini, maxi);
    return 0;
}