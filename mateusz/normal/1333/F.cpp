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

const int N = 500005;

int n, cnt[N];
int wynik[N];

int main() {
    
    scanf("%d", &n);
    
    int ile = 1;
    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 0) {
            ile++;
        }
        for (int j = 2 * i; j <= n; j += i) {
            cnt[j]++;
        }
    }
    
    wynik[1] = ile;
    debug(1, wynik[1]);
    for (int i = 2; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            cnt[j]--;
            if (cnt[j] == 0) {
                ile++;
            }
        }
        wynik[i] = ile;
        debug(i, ile);
    }
    
    int ptr = 1;
    for (int k = 2; k <= n; k++) {
        while (wynik[ptr] < k) {
            ptr++;
        }
        printf("%d ", ptr);
    }
    
    return 0;
}