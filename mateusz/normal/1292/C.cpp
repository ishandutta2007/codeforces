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

const int N = 3005;

int n, a, b;
vector<int> V[N];
int subSize[N];
int myPar[N];
long long dp[N][N];

bool vis[N][N];
queue<pair<pair<int, int>, pair<int, int> > > Q;

void countSubtrees(int w, int par = -1) {
    subSize[w] = 1;
    for (int u : V[w]) {
        if (par == u) {
            continue;
        }
        myPar[u] = w;
        countSubtrees(u, w);
        subSize[w] += subSize[u];
    }
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    countSubtrees(1);
    
    for (int i = 1; i <= n; i++) {
        for (int u : V[i]) {
            long long size = 0;
            if (myPar[i] == u) {
                size = (long long)subSize[i] * (n - subSize[i]);
            } else {
                size = (long long)subSize[u] * (n - subSize[u]);
            }
            dp[i][u] = size;
            vis[i][u] = true;
            Q.push({{i, u}, {u, i}});
        }
    }
    
    long long ans = 0;
    while (!Q.empty()) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        debug(x, y, dp[x][y]);
        ans = max(ans, dp[x][y]);
        int parx = Q.front().second.first;
        int pary = Q.front().second.second;
        Q.pop();
        for (int u : V[x]) {
            if (u == parx) continue;
            int sizeA = 0;
            if (myPar[u] == x) {
                sizeA = subSize[u];
            } else {
                sizeA = n - subSize[x];
            }
            int sizeB = 0;
            if (myPar[y] == pary) {
                sizeB = subSize[y];
            } else {
                sizeB = n - subSize[pary];
            }
            dp[u][y] = max(dp[u][y], dp[x][y] + (long long)sizeA * sizeB);
            if (!vis[u][y]) {
                vis[u][y] = true;
                Q.push({{u, y}, {x, pary}});
            }
        }
        
        for (int u : V[y]) {
            if (u == pary) continue;
            int sizeA = 0;
            if (myPar[u] == y) {
                sizeA = subSize[u];
            } else {
                sizeA = n - subSize[y];
            }
            int sizeB = 0;
            if (myPar[x] == parx) {
                sizeB = subSize[x];
            } else {
                sizeB = n - subSize[parx];
            }
            dp[x][u] = max(dp[x][u], dp[x][y] + (long long)sizeA * sizeB);
            if (!vis[x][u]) {
                vis[x][u] = true;
                Q.push({{x, u}, {parx, y}});
            }
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}