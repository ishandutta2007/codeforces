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

const int N = 100005;

long long substrings(long long l) {
    return l * (l - 1) / 2 + l;
}

int main() {
    
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        if (m == n) {
            printf("%lld\n", n * (n - 1) / 2 + n);
            continue;
        }
        long long zeros = n - m;
        long long groupSize = zeros / (m + 1);
        long long biggerGroups = zeros % (m + 1);
        printf("%lld\n", substrings(n) - substrings(groupSize) * (m + 1 - biggerGroups) - substrings(groupSize + 1) * biggerGroups);
    }
    
    return 0;
}