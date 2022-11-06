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

const int N = 2005;

int n, x[N], y[N], k[N], c[N];
int rep[N], val[N];
bool done[N];

int find(int w) {
    return rep[w] = (w == rep[w] ? w : find(rep[w]));
}

long long getDist(int a, int b) {
    return (long long)(k[a] + k[b]) * (abs(x[a] - x[b]) + abs(y[a] - y[b]));
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }
    
    
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += c[i];
        rep[i] = i;
        val[i] = c[i];
    }
    
    vector<pair<long long, pair<int, int> > > edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edges.push_back({getDist(i, j), {i, j}});
        }
    }
    
    sort(edges.begin(), edges.end());
    vector<pair<int, int> > ans;
    for (auto edge : edges) {
        int a = edge.second.first;
        int b = edge.second.second;
        int f = a;
        int s = b;
        long long weight = edge.first;
        if (find(a) == find(b)) {
            continue;
        }
        a = find(a);
        b = find(b);
        if (weight < max(val[a], val[b])) {
            ans.push_back({f, s});
            sum += weight;
            sum -= max(val[a], val[b]);
            weight -= max(val[a], val[b]);
            val[b] = min(val[a], val[b]);
            rep[a] = b;
        }
    }
    vector<int> stations;
    for (int i = 1; i <= n; i++) {
        int w = find(i);
        if (!done[w] && c[i] == val[w]) {
            stations.push_back(i);
            done[w] = true;
        }
    }
    
    printf("%lld\n", sum);
    printf("%d\n", stations.size());
    for (int w : stations) {
        printf("%d ", w);
    }
    printf("\n");
    
    printf("%d\n", ans.size());
    for (auto edge : ans) {
        printf("%d %d\n", edge.first, edge.second);
    }
    
    
    return 0;
}