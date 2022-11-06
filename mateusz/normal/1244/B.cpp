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

int n;
char word[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %s", &n, &word[1]);
        int firstOne = -1, lastOne = -1;
        for (int i = 1; i <= n; i++) {
            if (firstOne == -1 && word[i] == '1') {
                firstOne = i;
            }
            if (word[i] == '1') {
                lastOne = i;
            }
        }
        if (firstOne == -1) {
            printf("%d\n", n);
            continue;
        }
        if (firstOne == lastOne) {
            printf("%d\n", 2 * max(firstOne, n - firstOne + 1));
            continue;
        }
        printf("%d\n", 2 * (lastOne - firstOne + 1 + max(firstOne - 1, n - lastOne)));
    }
    
    return 0;
}