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

char word[N];
int n;

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &word[1]);
        n = strlen(word + 1);
        for (int i = 1; i <= n; i++) {
            word[i] -= '0';
        }
        int ans = max(0, n - 2);
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                int cur = 0;
                for (int i = 1; i <= n; i++) {
                    
                    if (cur % 2 == 0 && word[i] == a) {
                        cur++;
                    } else if (cur % 2 == 1 && word[i] == b) {
                        cur++;
                    }
                }
                if (cur % 2 == 1 && a != b) cur--;
                ans = min(ans, n - cur);
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}