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

const int N = 1000005;

int n, cnt[N], cntOnes[N];

int main() {
    
    scanf("%d", &n);
    int oldN = n;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            cnt[i]++;
            n /= i;
        }
    }
    
    int ans = 0;
    int ans2 = 1;
    int biggest = 0;
    bool used = false;
    for (int i = 2; i <= oldN; i++) {
        int c = 0;
        int x = cnt[i];
        if (x == 0) continue;
        while (x & (x - 1)) x++;
        biggest = max(biggest, x);
        if (cnt[i] > 0) ans2 *= i;
    }
    for (int i = 2; i <= oldN; i++) {
        if (cnt[i] > 0 && cnt[i] < biggest) used = true;
    }

    while (biggest > 1) {
        ans++;
        biggest /= 2;
    }
    
    printf("%d %d\n", ans2, ans + used);
    return 0;
}