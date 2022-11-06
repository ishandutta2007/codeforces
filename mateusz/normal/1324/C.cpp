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

const int N = 200005;

int t, n;
char word[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &word[1]);
        n = strlen(word + 1);
        int lastR = 0;
        word[n + 1] = 'R';
        int ans = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (word[i] == 'R') {
                ans = max(ans, i - lastR);
                lastR = i;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}