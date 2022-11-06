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

const int N = 100005, M = 1e9 + 7;

int n, m, a, b;
char word[N];
int ones[N], zeros[N];

int mul(int x, int y) {
    return (long long)x * y % M;
}

int power(int a, int k) {
    if (k == 0) return 1;
    return mul(power(mul(a, a), k / 2), k % 2 ? a : 1);
}

int main() {
    
    scanf("%d%d", &n, &m);
    scanf("%s", &word[1]);
    for (int i = 1; i <= n; i++) {
        ones[i] = ones[i - 1] + (word[i] - '0');
        zeros[i] = zeros[i - 1] + (1 - word[i] + '0');
    }
    
    while (m--) {
        scanf("%d %d", &a, &b);
        int x = ones[b] - ones[a - 1];
        int y = zeros[b] - zeros[a - 1];
        printf("%d\n", mul(power(2, y), ((power(2, x) - 1) + M) % M));
    }
    return 0;
}