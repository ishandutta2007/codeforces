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

const int N = 1005;

int n, m;
char word[N], word2[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n ,&m);
        scanf("%s", &word[1]);
        for (int i = 1; i <= n; i++) word[i] -= '0';
        int reps = 1;
        for (int reps = 1; reps <= min(n + 5, m); reps++) {
            for (int i = 1; i <= n; i++) {
                int ones = word[i - 1] + word[i + 1];
                if (ones == 1 || word[i] == 1) {
                    word2[i] = 1;
                } else {
                    word2[i] = 0;
                }
            }
            for (int i = 1; i <= n; i++) {
                word[i] = word2[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (word[i] == 1) printf("1");
            else printf("0");
        }
        printf("\n");
    }
    
    return 0;
}