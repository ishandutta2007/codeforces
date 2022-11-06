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

int n, a, b;
vector<int> V[N];
int deg[N];

int LCA(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        deg[i] = V[i].size();
        if (V[i].size() == 1) {
            Q.push(i);
        }
    }
    
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop();
        if (Q.empty()) {
            cout << "! " << w << endl;
            return 0;
        }
        int u = Q.front();
        Q.pop();
        int lca = LCA(w, u);
        if (lca == w) {
            cout << "! " << w << endl;
            return 0;
        }
        if (lca == u) {
            cout << "! " << u << endl;
            return 0;
        }
        for (int v : V[w]) {
            deg[v]--;
            if (deg[v] == 1) {
                Q.push(v);
            }
        }
        
        for (int v : V[u]) {
            deg[v]--;
            if (deg[v] == 1) {
                Q.push(v);
            }
        }
    }
    
    return 0;
}