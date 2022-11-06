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

const int N = 105;

char s[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &s[1]);
        int n = strlen(s + 1);
        bool diff = false;
        for (int i = 2; i <= n; i++) {
            if (s[i] != s[i - 1]) {
                diff = true;
                break;
            }
        }
        
        if (!diff) {
            printf("%s\n", s + 1);
        } else {
            for (int i = 1; i <= n; i++) {
                printf("01");
            }
            printf("\n");
        }
        
    }
    
    return 0;
}