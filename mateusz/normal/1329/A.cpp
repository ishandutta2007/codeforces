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

int n, m;
int len[N], p[N];
int t[N];
int prefRange[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d", &len[i]);
        t[i] = i;
    }
    
//     sort(t + 1, t + 1 + m, [&](int a, int b) { return len[a] > len[b]; });
    
    
    for (int i = 1; i <= m; i++) {
        p[t[i]] = i;
        if (i + len[t[i]] - 1 > n) {
            printf("-1\n");
            return 0;
        }
        prefRange[i] = max(prefRange[i - 1], i + len[t[i]] - 1);
    }
    int last = m;
    int pos = n;
    while (pos >= 1 && last >= 1 && prefRange[last] < pos) {
        p[t[last]] = pos - len[t[last]] + 1;
        pos = pos - len[t[last]];
        last--;
    }
    if (pos > 0 && (last == 0)) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    
    return 0;
}