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

int n, type[N], color[N];

int mod(int w) {
    if (w > n) {
        return w - n;
    }
    return w;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &type[i]);
        }
        
        int colors = 1;
        for (int i = 2; i <= n; i++) {
            if (type[i] != type[i - 1]) {
                colors = 3;
                break;
            }
        }
        
        if (colors == 1) {
            printf("1\n");
            for (int i = 1; i <= n; i++) {
                printf("1 ");
            }
            printf("\n");
            continue;
        }
        
        int start = 1;
        
        for (int i = 1; i <= n; i++) {
            if (type[i] == type[mod(i + 1)]) {
                start = mod(i + 1);
                colors--;
                break;
            }
        }
        
        if (n % 2 == 0) {
            colors = 2;
        }
        if (colors == 2) {
            printf("2\n");
            int col = 1;
            for (int i = 1; i <= n; i++) {
                color[start] = col;
                if (col == 1) col = 2;
                else col = 1;
                start = mod(start + 1);
            }
            for (int i = 1; i <= n; i++) {
                printf("%d ", color[i]);
            }
            printf("\n");
            continue;
        }
        
        printf("3\n");
        for (int i = 1; i < n; i++) {
            printf("%d ", (i % 2) + 1);
        }
        printf("3\n");
    }
    
    return 0;
}