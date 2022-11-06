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

int n, k, a, b;
vector<int> V[N];
int depth[N], cnt[N];
int deg[N];

void DFS(int w, int par = -1) {
    for (int u : V[w]) {
        if (u == par) {
            continue;
        }
        depth[u] = depth[w] + 1;
        DFS(u, w);
    }
}

int main() {
    
    scanf("%d %d", &n, &k);
    
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    
    DFS(1);
    
    priority_queue<pair<int, int> > Q;
    for (int i = 2; i <= n; i++) {
        if (V[i].size() == 1) {
            Q.push({depth[i], i});
        }
    }
    
    long long ans = 0;
    
    for (int i = 1; i <= k; i++) {
        int w = Q.top().second;
        Q.pop();
        ans += depth[w] - cnt[w];
        for (int u : V[w]) {
            deg[u]--;
            cnt[u] += cnt[w] + 1;
            if (u != 1 && deg[u] == 1) {
                Q.push({depth[u] - cnt[u], u});
            }
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}