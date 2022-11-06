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

const int N = 100005;

int n, k, a, b;
int ans;
bool vis[N];
vector<int> V[N];
int add;

void DFS(int w, int par = -1) {
    vis[w] = true;
    for (int u : V[w]) {
        if (vis[u] && par != u) {
            add++;
        }
        if (!vis[u]) {
            DFS(u, w);
        }
    }
}
int main() {
    
    set<pair<int, int> > appear;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) {
            swap(a, b);
        }
        if (appear.count({a, b})) {
            ans++;
            continue;
        }
        appear.insert({a, b});
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) DFS(i);
    }
    
    printf("%d\n", ans + add / 2);
    return 0;
}