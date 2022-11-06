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

int n, a, b, cost[5][N];
long long dp[N][3][3];
vector<int> V[N];
int color[N];

vector<int> seq;
void DFS(int w, int par = -1) {
    seq.push_back(w);
    for (int u : V[w]) {
        if (u == par) {
            continue;
        }
        DFS(u, w);
    }
}

int main() {
    scanf("%d", &n);
    for (int c = 0; c < 3; c++) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &cost[c][i]);
        }
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    seq.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (V[i].size() >= 3) {
            printf("-1\n");
            return 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (V[i].size() == 1) {
            DFS(i);
            break;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int w = seq[i];
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (a == b) continue;
                dp[i][a][b] = dp[i - 1][b][0 ^ 1 ^ 2 ^ a ^ b] + cost[a][w];
            }
        }
    }
    
    long long ans = dp[n][0][1];
    int bestA = 0, bestB = 1;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            if (a == b) continue;
            if (dp[n][a][b] < ans) {
                ans = dp[n][a][b];
                bestA = a;
                bestB = b;
            }
        }
    }
    
    debug(bestA, bestB);
    color[seq[n]] = bestA;
    color[seq[n - 1]] = bestB;
    for (int i = n - 2; i >= 1; i--) {
        int w = seq[i];
        color[w] = 0 ^ 1 ^ 2 ^ bestA ^ bestB;
        bestA = bestB;
        bestB = color[w];
    }
    
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++) {
        printf("%d ", color[i] + 1);
    }
    printf("\n");
    
    return 0;
}