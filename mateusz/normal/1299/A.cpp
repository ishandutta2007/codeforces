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

int n, a[N];
int cnt[50];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int w = a[i];
        for (int j = 0; j < 30; j++) {
            cnt[j] += w % 2;
            w /= 2;
        }
    }
    
    int best = 0;
    int bestCnt = -1;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        int w = a[i];
        for (int j = 0; j < 30; j++) {
            if (w % 2 == 1 && cnt[j] == 1) {
                c += (1 << j);
            }
            w /= 2;
        }
        if (c > bestCnt) {
            bestCnt = c;
            best = i;
        }
    }
    
    printf("%d ", a[best]);
    for (int i = 1; i <= n; i++) {
        if (best == i) continue;
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}