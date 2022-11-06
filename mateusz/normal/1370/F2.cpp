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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
const int N = 1005;

vector<int> V[N];
int n, a, b;
int dist[N];

pair<int, int> query(vector<int> v) {
    if (v.empty()) {
        return {-1, 1000000};
    }
    cout << "? " << v.size() << " ";
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
    int resA, resB;
    cin >> resA >> resB;
    return {resA, resB};
}

void DFS(int w, int par = -1) {
    for (int u : V[w]) {
        if (par == u) continue;
        dist[u] = dist[w] + 1;
        DFS(u, w);
    }
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
    for (int i = 1; i <= n; i++) {
        V[i].clear();
    }
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    vector<int> init;
    for (int i = 1; i <= n; i++) {
        init.push_back(i);
    }
    
    auto p = query(init);
    int root = p.first;
    int d = p.second;
    
    dist[root] = 0;
    DFS(root);
    
    int low = d / 2;
    int high = d;
    int res = low;
    int node = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
//         debug(mid);
        vector<int> nodes;
        for (int i = 1; i <= n; i++) {
            if (dist[i] >= mid) nodes.push_back(i);
        }
        auto p = query(nodes);
        if (p.second > d) {
            high = mid - 1;
        } else {
            node = p.first;
            res = mid;
            low = mid + 1;
        }
    }
    
    dist[node] = 0;
    DFS(node);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == d) {
            v.push_back(i);
        }
    } 
    
    p = query(v);
    cout << "! " << node << " " << p.first << endl;
    
    string ans;
    cin >> ans;
    if (ans != "Correct") {
        exit(1);
    }
    
    }
    return 0;
}