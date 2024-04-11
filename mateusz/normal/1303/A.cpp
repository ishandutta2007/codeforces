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

char word[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &word[1]);
        int n = strlen(word + 1);
        int firstOne = 0;
        int lastOne = 0;
        for (int i = 1; i <= n; i++) {
            if (word[i] == '1') lastOne = i;
        }
        
        for (int i = n; i >= 1; i--) {
            if (word[i] == '1') firstOne = i;
        }
        
        int ans = 0;
        for (int i = firstOne + 1; i < lastOne; i++) {
            if (word[i] == '0') {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}