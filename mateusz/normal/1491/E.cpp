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

int fib[105];
int n, a, b;
vector<int> V[N];
int sub[N], blocked[N];


bool check(int w, int par, int k);

int DFS(int w, int par, int k) {
    sub[w] = 1;
    for (int u : V[w]) {
        if (par == u || blocked[u]) continue;
        int ret = DFS(u, w, k);
        if (ret == 1) return 1;
        if (ret == 2) return 2;
        sub[w] += sub[u];
    }
    if (sub[w] == fib[k - 1] || sub[w] == fib[k - 2]) {
        int myK = sub[w] == fib[k - 1] ? k - 1 : k - 2;
        int parK = myK == k - 1? k - 2 : k - 1;
        blocked[par] = true;
        bool goodA = check(w, par, myK);
        blocked[par] = false;
        blocked[w] = true;
        bool goodB = check(par, w, parK);
        if (goodA && goodB) return 1;
        return 2;
    }
    return 0;
}

bool check(int w, int par, int k) {
    if (k <= 2) {
        return true;
    }
    
    return DFS(w, par, k) == 1;
}

int main() {
    
    
    scanf("%d", &n);
    if (n == 1) {
        printf("YES\n");
        return 0;
    }
    int k = -1;
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2;; i++) {
        fib[i] = fib[i - 2] + fib[i - 1];
        if (fib[i] > n) {
            printf("NO\n");
            return 0;
        }
        if (fib[i] == n) {
            k = i;
            break;
        }
    } 
        
        
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    printf(check(1, -1, k) ? "YES\n" : "NO\n");

    return 0;
}