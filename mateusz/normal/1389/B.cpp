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
const int N = 100005;

int n, k, z;
int a[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &k, &z);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        k++;
        long long ans = 0;
        for (int ile = 0; ile <= z && 2 * ile <= k; ile++) {
            long long sum = 0;
            vector<int> numbers;
            for (int i = 1; i <= k - ile * 2; i++) {
                sum += a[i];
//                 if (i >= 2) {
                    numbers.push_back(a[i] + a[i + 1]);
//                 }
            }
            sort(numbers.begin(), numbers.end());
            if (ile > 0 && !numbers.empty()) {
                sum += ile * numbers.back();
            }
            ans = max(ans, sum);
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}