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

const int N = 100005, M = 1e9 + 7;

int n, m, a, b;
int subtree[N], p[N];
vector<int> V[N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int mul(int w, int u) {
    return (long long)w * u % M;
}


void DFS(int w, int par = -1) {
    subtree[w] = 1;
    for (int u : V[w]) {
        if (u == par) continue;
        DFS(u, w);
        subtree[w] += subtree[u];
    }
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            subtree[i] = 0;
            V[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d %d", &a, &b);
            V[a].push_back(b);
            V[b].push_back(a);
        }
        DFS(1);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d", &p[i]);
        }
        while (m < n - 1) {
            p[++m] = 1;
        }
        vector<long long> subtrees;
        for (int i = 2; i <= n; i++) {
            subtrees.push_back({(long long)subtree[i] * (n - subtree[i])});
        }
        sort(subtrees.begin(), subtrees.end());
        sort(p + 1, p + 1 + m);
        int ptr = 0;
        int ans = 0;
        int cur = 1;
        for (int i = 1; i <= m; i++) {
            cur = mul(cur, p[i]);
            if (ptr < n - 2 || i == m) {
                add(ans, mul(cur, subtrees[ptr] % M));
                cur = 1;
                ptr++;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}