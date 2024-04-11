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
int n, x;
int A[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n == 1) {
            printf("FastestFinger\n");
            continue;
        }
        int winner = 0;
        if (n == 2 || n % 2 == 1) {
            printf("Ashishgup\n");
            continue;
        }
        int cnt = 0;
        while (n % 2 == 0) {
            n /= 2;
            cnt++;
        }
        if (n == 1) {
            printf("FastestFinger\n");
            continue;
        }
        
        set<int> divs;
        for (int i = 3; i * i <= n; i++) {
            while (n % i == 0) {
                divs.insert(i);
                n /= i;
            }
        }
        divs.insert(n);
        printf(divs.size() >= 2 || (divs.size() >= 1 && cnt >= 2) ? "Ashishgup\n" : "FastestFinger\n");
    }
    
    return 0;
}