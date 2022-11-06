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

int n;
vector<int> order, last;
long long A[N], B[N];
vector<int> V[N];

long long DFS(int w, int par = -1) {
    long long ret = 0;
    for (int u : V[w]) {
        if (par == u) continue;
        ret += DFS(u);
        if (A[u] >= 0) {
            A[w] += A[u];
        }
    }
    
    ret += A[w];
    if (A[w] >= 0) {
        order.push_back(w);
    } else {
        last.push_back(w);
    }
    return ret;
}
int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &B[i]);
        if (B[i] != -1) {
            V[B[i]].push_back(i);
        }
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (B[i] == -1) {
            ans += DFS(i);
        }
    }
    for (int i = last.size() - 1; i >= 0; i--) {
        order.push_back(last[i]);
    }
    printf("%lld\n", ans);
    for (int x : order) {
        printf("%d ", x);
    }
    printf("\n");
    
    return 0;
}