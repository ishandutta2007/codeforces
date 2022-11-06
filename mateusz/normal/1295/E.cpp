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

const int N = 200005, BASE = (1 << 18);

long long W[2 * BASE + 5], w[2 * BASE + 5];
int n, p[N], a[N];

void insert(int posa, int posb, int val) {
    posa += BASE;
    posb += BASE;
    w[posa] += val;
    W[posa] += val;
    if (posa != posb) {
        w[posb] += val;
        W[posb] += val;
    }
    while (posa >= 1) {
        if (posa / 2 != posb / 2) {
            if (posa % 2 == 0) {
                w[posa + 1] += val;
                W[posa + 1] += val;
            }
            if (posb % 2 == 1) {
                w[posb - 1] += val;
                W[posb - 1] += val;
            }
        }
        posa /= 2;
        posb /= 2;
        W[posa] = w[posa] + min(W[2 * posa], W[2 * posa + 1]);
        W[posb] = w[posb] + min(W[2 * posb], W[2 * posb + 1]);
    }
}

long long query(int posb) {
    posb += BASE;
    long long ret = W[posb];
    while (posb > 1) {
        if (posb % 2 == 1) {
            ret = min(ret, W[posb - 1]);
        }
        posb /= 2;
        ret += w[posb];
    }
    return ret;
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        insert(p[i], n, a[i]);
    }
    
    long long ans = 1e18;
    for (int i = 1; i < n; i++) {
        insert(p[i], n, -a[i]);
        insert(0, p[i] - 1, a[i]);
        ans = min(ans, query(n));
    }
    
    printf("%lld\n", ans);
    
    return 0;
}