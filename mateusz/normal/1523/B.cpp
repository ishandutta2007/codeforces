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

const int N = 1005;
const int types[] = {1, 2, 1, 1, 2, 1};

int n;
int A[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        vector<pair<int, pair<int, int>>> ops;
        for (int i = 1; n - i + 1 > i; i++) {
            int w = i;
            int u = n - i + 1;
            for (int k = 0; k < 6; k++) {
                ops.push_back({types[k], {w, u}});
            }
        }
        printf("%d\n", ops.size());
        for (auto op : ops) {
            printf("%d %d %d\n", op.first, op.second.first, op.second.second);
        }
    }
    
    return 0;
}