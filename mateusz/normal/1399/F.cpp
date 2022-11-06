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

const int N = 3005;

int n, from[N], to[N];
int dp[N];
vector<int> V[N];
bool vis[N];

bool contains(int a, int b) {
    return from[a] <= from[b] && to[a] >= to[b];
}

void DFS(int w) {
    dp[w] = 1;
    vis[w] = true;
    sort(V[w].begin(), V[w].end(), [&](int a, int b) { return to[a] < to[b]; });
    for (int u : V[w]) {
        if (!vis[u])
        DFS(u);
    }
    vector<int> prefMax;
    prefMax.push_back(0);
    int best = 0;
    for (int u : V[w]) {
        int F = from[u];
        int low = 0;
        int high = prefMax.size();
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (to[V[w][mid]] < F) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        best = max(best, dp[u] + prefMax[res + 1]);
        prefMax.push_back(best);
    }
    dp[w] = 1 + best;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        V[0].clear();
        dp[0] = 0;
        vis[0] = 0;
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            V[i].clear();
            dp[i] = 0;
            scanf("%d %d", &from[i], &to[i]);
        }
        from[0] = 0;
        to[0] = 200000;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == j) continue;
                if (contains(i, j)) {
                    V[i].push_back(j);
                }
            }
        }
        DFS(0);
        printf("%d\n", dp[0] - 1);
    }
    
    return 0;
}