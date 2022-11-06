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
long long tab[N];

void test() {
    scanf("%d", &n);
    long long sum = 0;
    long long x = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &tab[i]);
        sum += tab[i];
        x ^= tab[i];
    }
    vector<long long> ans;
    ans.push_back(x);
    sum += x;
    x ^= x;
    ans.push_back(sum);
    printf("%d\n", ans.size());
    for (auto x : ans) {
        printf("%lld ", x);
    }
    printf("\n");
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    return 0;
}