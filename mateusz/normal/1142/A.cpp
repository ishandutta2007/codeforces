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

int n, k, a, b;
long long m;

long long NWD(long long a, long long b) {
    return b == 0 ? a : NWD(b, a % b);
}

long long checkDist(long long startPos, long long secondPos) {
    long long stepLength = ((secondPos - startPos) + m) % m;
    long long gcd = NWD(stepLength, m);
    return m / gcd;
}

int main() {
    
    scanf("%d %d", &n, &k);
    scanf("%d %d", &a, &b);
    m = (long long)n * k;
    vector<long long> values;
    for (long long i = 0; i < n; i++) {
        values.push_back(checkDist(a, (i * k + b)));
        values.push_back(checkDist(a, (i + 1) * k - b));
    }
    sort(values.begin(), values.end());
    printf("%lld %lld\n", values[0], values.back());
    return 0;
}