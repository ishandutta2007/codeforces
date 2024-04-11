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

char word[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        scanf("%s", &word[1]);
        sort(word + 1, word + 1 + n);
        if (word[k] != word[1]) {
            printf("%c\n", word[k]);
            continue;
        }
        
        if (k == n) {
            printf("%c\n", word[k]);
            continue;
        }
        
        if (word[n] != word[k + 1]) {
            for (int i = k; i <= n; i++) {
                printf("%c", word[i]);
            }
            printf("\n");
            continue;
        }
        
        printf("%c", word[k]);
        for (int i = 1; i <= (n - 1) / k; i++) {
            printf("%c", word[n]);
        }
        printf("\n");
        
    }
    
    return 0;
}