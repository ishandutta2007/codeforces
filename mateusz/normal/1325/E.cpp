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

const int N = 1000000;

int n, a[N + 5];
vector<int> V[N + 5];

int sieve[N + 5];
vector<int> primes;

bool vis[N + 5];
int dist[N + 5], par[N + 5];
int ans;
queue<int> Q;

void BFS(int v) {
    for (int p : primes) {
        vis[p] = false;
        dist[p] = 0;
    }
    vis[v] = true;
    Q.push(v);
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop();
        for (int u : V[w]) {
            if (vis[u]) {
                
                if (par[w] != u) {
                    ans = min(ans, dist[w] + dist[u] + 1);
                }
                
                continue;
            }
            par[u] = w;
            vis[u] = true;
            dist[u] = dist[w] + 1;
            Q.push(u);
        }
    }
}

int main() {
    ans = 1e9;
    scanf("%d", &n);
    
    for (int i = 2; i <= N; i++) {
        if (sieve[i] != 0) continue;
        for (int j = i; j <= N; j += i) {
            sieve[j] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        vector<int> primes;
        int w = a[i];
        while (w > 1) {
            if (!primes.empty() && primes.back() == sieve[w]) {
                primes.pop_back();
            } else {
                primes.push_back(sieve[w]);
            }
            w /= sieve[w];
        }
        if (primes.empty()) {
            printf("1\n");
            return 0;
        }
        if (primes.size() == 1) {
            V[1].push_back(primes[0]);
            V[primes[0]].push_back(1);
        } else {
            V[primes[0]].push_back(primes[1]);
            V[primes[1]].push_back(primes[0]);
        }
    }
    
    primes.push_back(1);
    for (int i = 2; i <= N; i++) {
        if (sieve[i] == i) {
            primes.push_back(i);
        }
    }
    
    for (int p : primes) {
        if (p * p > N) break;
        BFS(p);
    }
    if (ans == 1e9) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans);
    
    return 0;
}