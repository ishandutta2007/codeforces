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

const int N = 500005;

int n, a, b, c, k, t;
long long ans;
vector<pair<int, int> > V[N];
int edgeBack[N];
int gain[N];

void DFS(int w, int par = -1) {
    for (int i = 0; i < V[w].size(); i++) {
        if (V[w][i].first == par) {
            swap(V[w][i], V[w].back());
            V[w].pop_back();
            break;
        }
    }
    for (auto p : V[w]) {
        int u = p.first;
        int weight = p.second;
        if (u == par) {
            continue;
        }
        edgeBack[u] = weight;
        DFS(u, w);
    }
    sort(V[w].begin(), V[w].end(), [](pair<int, int> a, pair<int, int> b) { return gain[a.first] > gain[b.first]; });
    long long sumGain = 0;
    int worstGain = 1e9;
    for (int i = 0; i < min((int)V[w].size(), k); i++) {
        int u = V[w][i].first;
        sumGain += gain[u];
        worstGain = min(worstGain,  gain[u]);
    }
    
    ans += sumGain;
    if (V[w].size() >= k) {
        gain[w] = max(0, edgeBack[w] - worstGain);
    } else {
        gain[w] = edgeBack[w];
    }
}

void test() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        V[i].clear();
    }
    ans = 0;
    for (int i = 2; i <= n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        V[a].push_back({b, c});
        V[b].push_back({a, c});
    }
    DFS(1);
    printf("%lld\n", ans);
}

int main() {
    
    scanf("%d", &t);
    while (t--) test();
    
    return 0;
}