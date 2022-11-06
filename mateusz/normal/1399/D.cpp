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

int n;
char word[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", &word[1]);
        int ans = 0;
        int bal = 0;
        int maxB = 0;
        int minB = 0;
        for (int i = 1; i <= n; i++) {
            if (word[i] == '0') bal++;
            else bal--;
            maxB = max(maxB, bal);
            minB = min(minB, bal);
        }
        printf("%d\n", maxB - minB);
        bal = 0;
        for (int i = 1; i <= n; i++) {
            if (word[i] == '0') bal++;
            else bal--;
            printf("%d ", bal - minB + (word[i] == '1'));
        }
        printf("\n");
    }
    
    return 0;
}