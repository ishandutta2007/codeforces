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
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005;

char a[N], b[N], c[N];

int main() {
    
    int t;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%s %s %s", &a[1], &b[1], &c[1]);
        int n = strlen(a + 1);
        bool good = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] == c[i] || b[i] == c[i]) {
                continue;
            }
            good = false;
            break;
        }
        printf(good ? "YES\n" : "NO\n");
    }
    
    return 0;
}