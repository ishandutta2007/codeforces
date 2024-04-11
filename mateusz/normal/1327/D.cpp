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

const int N = 200005;

int n, p[N], color[N];
bool vis[N];
vector<vector<int>> cycles;

int good(vector<int> cycle) {
    int l = cycle.size();
    
    vector<int> divisors;
    for (int i = 1; i * i <= l; i++) {
        if (l % i == 0) {
            divisors.push_back(i);
            divisors.push_back(l / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    for (auto div : divisors) {
    
        for (int i = 0; i < div; i++) {
            int pos = i;
            int myColor = color[cycle[i]];
            bool fine = true;
            do {
                pos = (pos + div) % l;
                if (myColor != color[cycle[pos]]) {
                    fine = false;
                }
            } while (pos != i);
            if (fine) {
                return div;
            }
        }
    }
    return l;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            vis[i] = false;
        }
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &color[i]);
        }
        
        cycles.clear();
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vector<int> cycle;
                int w = i;
                do {
                    cycle.push_back(w);
                    vis[w] = true;
                    w = p[w];
                } while (w != i);
                cycles.push_back(cycle);
            }
        }
        
        int ans = n;
        for (auto cycle : cycles) {
            ans = min(ans, good(cycle));
        }
        printf("%d\n", ans);
    }
    
    return 0;
}