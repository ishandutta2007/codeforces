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

const int N = 400005;

int tab[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n % 4 != 0) {
            printf("NO\n");
            continue;
        }
        long long sum = 0;
        int even = 2;
        for (int i = n / 2 + 1; i <= n; i++) {
            tab[i] = even;
            sum += tab[i];
            even += 2;
        }
        
        int odd = 1;
        long long sumOdd = 0;
        for (int i = 1; i <= n / 2; i++) {
            tab[i] = odd;
            sumOdd += tab[i];
            odd += 2;
        }
        sumOdd -= tab[n / 2];
        tab[n / 2] = sum - sumOdd;
        reverse(tab + 1, tab + 1 + n);
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            printf("%d ", tab[i]);
        }
        printf("\n");
    }
    
    return 0;
}