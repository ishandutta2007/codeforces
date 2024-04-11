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

const int N = 200005;

int n;
long long A[N], A2[N];
int twos[N], cnt[N];

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
        A2[i] = A[i];
        while (A[i] % 2 == 0) {
            twos[i]++;
            A[i] /= 2;
        }
        cnt[twos[i]]++;
    }
    
    int best = 0;
    for (int i = 0; i <= 100; i++) {
        if (cnt[i] > cnt[best]) best = i;
    }
    
    printf("%d\n", n - cnt[best]);
    for (int i = 1; i <= n; i++) {
        if (twos[i] != best) {
            printf("%lld ", A2[i]);
        }
    }
    printf("\n");
    
    return 0;
}