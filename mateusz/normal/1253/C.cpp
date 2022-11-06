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

int n, m;
int sugar[N];
long long pref[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &sugar[i]);
    }
    sort(sugar + 1, sugar + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (i - m >= 1) {
            pref[i] += pref[i - m];
        }
        pref[i] += sugar[i];
    }
    
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pref[i];
        printf("%lld ", sum);
    }
    
    printf("\n");
    
    return 0;
}