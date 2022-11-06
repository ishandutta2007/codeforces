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

const int N = 5005;

int n, d;
int pref[N];
int par[N];

int minimum(int w) {
    return pref[w];
}

int maximum(int w) {
    return w * (w - 1) / 2;
}

bool solve(int w, int n, int d) {
    debug(w, n, d, par[w]);
    if (n <= 1) {
        return d == 0;
    }
    for (int nLeft = 0; nLeft < n; nLeft++) {
        int nRight = n - nLeft - 1;
        if (minimum(nLeft) + minimum(nRight) + n - 1 <= d && maximum(nLeft) + maximum(nRight) + n - 1 >= d) {
            for (int d2 = minimum(nLeft); d2 <= maximum(nRight); d2++) {
                if (d - d2 - (n - 1) >= minimum(nRight) && d - d2 - (n - 1) <= maximum(nRight)) {
                    par[w + 1] = w;
                    if (nRight > 0) {
                        par[w + nLeft + 1] = w;
                    }
                    return solve(w + 1, nLeft, d2) && solve(w + nLeft + 1, nRight, d - d2 - (n - 1));
                }
            }
        }
    }
    
    return false;
}


void test() {
    scanf("%d %d", &n, &d);
    
    if (!solve(1, n, d)) {
        printf("NO\n");
        return;
    }
    
    printf("YES\n");
    for (int i = 2; i <= n; i++) {
        printf("%d ", par[i]);
    }
    printf("\n");
}

int main() {
    
    for (int i = 1; i < N; i++) {
        int w = i;
        int c = 0;
        while (w > 1) {
            c++;
            w /= 2;
        }
        pref[i] = pref[i - 1] + c;
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    
    return 0;
}