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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005;

int n, x;
vector<int> V[N];
int leaves[N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        V[x].push_back(i);
    }
    
    for (int i = n; i >= 1; i--) {
        if (V[i].empty()) {
            leaves[i] = 1;
        } else {
            for (int u : V[i]) {
                leaves[i] += leaves[u];
            }
        }
    }
    
    sort(leaves + 1, leaves + 1 + n);
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", leaves[i]);
    }
    printf("\n");
    
    return 0;
}