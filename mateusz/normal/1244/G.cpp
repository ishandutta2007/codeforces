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

const int N = 1000005;

int n, p[N], q[N];
long long k;

int main() {
    
    scanf("%d %lld", &n, &k);
    
    long long initK = k;
    
    long long cost = 0;
    for (int i = 1; i <= n; i++) {
        p[i] = q[i] = i;
        k -= i;
    }
    if (k < 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n - i + 1; i++) {
        debug(i, k);
        if ((p[n - i + 1] - i) <= k) {
            k -= (p[n - i + 1] - i);
            swap(p[i], p[n - i + 1]);
//             cerr << "TAK\n";
            continue;
        }
//         if (k % 2 == 1) {
//             printf("-1\n");
//             return 0;
//         }
        int diff = n - i + 1 - i;
        int ptrA = i;
        int ptrB = n - i + 1;
        while (diff > k && ptrA < ptrB) {
            ptrA++;
            diff --;
            if (diff > k && ptrA < ptrB) {
                ptrB--;
                diff --;
            }
        }
        swap(p[ptrA], p[ptrB]);
        break;
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += max(p[i], q[i]);
    }
    printf("%lld\n", ans);
//     printf("%lld\n", initK - cost);
    for (int i = 1; i <= n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
    
    
    return 0;
}