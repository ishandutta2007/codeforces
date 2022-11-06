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
int n, x;
int A[N];
vector<int> bits[25];
int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        int w = A[i];
        for (int j = 0; j < 20; j++) {
            bits[j].push_back(w % 2);
            w /= 2;
        } 
    }
    
    for (int i = 0; i < 20; i++) {
        sort(bits[i].begin(), bits[i].end());
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int w = 0;
        for (int j = 19; j >= 0; j--) {
            w = 2 * w + bits[j][i];
        }
        ans += (long long)w * w;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}