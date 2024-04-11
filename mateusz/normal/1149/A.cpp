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

int main() {
    int n, x;
    scanf("%d", &n);
    int cnt[3];
    cnt[1] = cnt[2] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    if (cnt[2] == 0) {
        for (int i = 1; i <= n; i++) {
            printf("1 ");
        }
        printf("\n");
    } else {
        if (cnt[1] == 0) {
            for (int i = 1; i <= n; i++) {
                printf("2 ");
            }
            printf("\n");
        } else {
            printf("2 1 ");
            cnt[2]--;
            cnt[1]--;
            for (int i = 1; i <= cnt[2]; i++) {
                printf("2 ");
            }
            for (int i = 1; i <= cnt[1]; i++) {
                printf("1 ");
            }
            printf("\n");
        }
    }
    return 0;
}