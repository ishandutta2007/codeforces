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

long long power(long long a, long long k) {
    long long ret = 1;
    for (int i = 1; i <= k; i++) {
        ret *= a;
    }
    return ret;
}

int main() {
    
    string s = "codeforces";
        long long k;
        scanf("%lld", &k);
        for (long long i = 1;; i++) {
            if (power(i, 10) >= k) {
//                 debug(i);
                int remaining = 10;
                long long acc = 1;
                int id = 0;
                while (power(i - 1, remaining) * acc < k) {
//                     debug(id);
                    for (int j = 1; j <= i; j++) {
                        printf("%c", s[id]);
                    }
                    remaining--;
                    acc *= i;
                    id++;
                }
                for (int x = id; x < 10; x++) {
                    for (int j = 1; j < i; j++) {
                        printf("%c", s[x]);
                    }
                }
                printf("\n");
                
                return 0;
            }
        }
    
    
    return 0;
}