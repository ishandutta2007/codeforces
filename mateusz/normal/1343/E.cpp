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

const int N = 400005;

int n, m, a, b, c;
vector<pair<int, int> > V[N];
int dist[N], dist2[N], dist3[N];
int price[N];
long long pref[2 * N];
bool vis[N];
int val[N];

void BFS(int v, int *dist) {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        dist[i] = 0;
    }
    vis[v] = true;
    queue<int> Q;
    Q.push(v);
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop();
        for (auto p : V[w]) {
            int u = p.first;
            int kr = p.second;
            if (!vis[u]) {
                vis[u] = true;
                dist[u] = dist[w] + 1;
                Q.push(u);
            }
        }
    }
    
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
        for (int i = 1; i <= n; i++) {
            V[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &price[i]);
        }
        sort(price + 1, price + 1 + m);
        for (int i = 1; i <= m; i++) {
            pref[i] = pref[i - 1] + price[i];
        }
        for (int i = m + 1; i <= 3 * m; i++) {
            pref[i] = pref[i - 1] + price[m];
        }
        
        for (int i = 1; i <= m; i++) {
            int d, e;
            scanf("%d %d", &d, &e);
            V[d].push_back({e, i});
            V[e].push_back({d, i});
        }
        
        for (int i = 1; i <= n; i++) {
            dist[i] = dist2[i] = dist3[i] = 0;
        }

        BFS(a, dist);
        BFS(b, dist2);
        BFS(c, dist3);
        
        for (int i = 1; i <= n; i++) {
            val[i] = -1;
        }
     /*   
        int d = dist[b];
        for (int i = 1; i <= n; i++) {
            debug(i, dist[i], dist2[i]);
            if (dist[i] + dist2[i] == d) {
                val[i] = dist2[i];
                debug(i, val[i]);
            }
        }
        debug("*");
        
        */
        long long ans = 1e18;
        
        for (int i = 1; i <= n; i++) {
//             if (val[i] != -1) {
//                 debug(i, dist[i]);
//                 debug(i, pref[d] + pref[val[i]] + (dist[i] + d > m ? (long long)1e18 : pref[dist[i] + d] - pref[d]));
                ans = min(ans, pref[dist2[i]] + pref[dist[i] + dist2[i] + dist3[i]]);
//             }
        }
        debug("***");
        printf("%lld\n", ans);
        
    }
    
    return 0;
}