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

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        if (k % 2 == 0 && n % 2 != 0) {
            printf("NO\n");
            continue;
        }
        vector<int> numbers;
        
        if ((n % 2 == 0 && k % 2 == 0) || n % 2 == 1) {
            for (int i = 1; i < k; i++) {
                numbers.push_back(1);
                n--;
            }
            if (n > 0) {
                numbers.push_back(n);
            } else {
                printf("NO\n");
                continue;
            }
        } else if (n % 2 == 0 && k % 2 == 1) {
            for (int i = 1; i < k; i++) {
                numbers.push_back(2);
                n -= 2;
            }
            if (n > 0) {
                numbers.push_back(n);
            } else {
                printf("NO\n");
                continue;
            }
        } 
        printf("YES\n");
        for (auto x : numbers) {
            printf("%d ", x);
        }
        printf("\n");
    }
    
    return 0;
}