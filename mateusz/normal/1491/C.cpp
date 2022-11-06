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

int n, A[N];
int rep[N];

int find(int w) {
    if (rep[w] == w) return w;
    return rep[w] = find(rep[w]);
}
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            rep[i] = i;
        }
        rep[n + 1] = n + 1;
        
        for (int i = n; i >= 1; i--) {
            if (A[i] == 1) {
                rep[i] = find(i + 1);
            }
        }
        
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] > n - i) {
                ans += A[i] - (n - i);
                A[i] = n - i;
            }
            while (A[i] > 1) {
                int w = i;
                ans++;
                while (w <= n) {
                    int nextW = A[w] == 1 ? find(w) : w + A[w];
                    if (A[w] > 1) {
                        A[w]--;
                        if (A[w] == 1) {
                            rep[w] = find(w + 1);
                        }
                    }
                    w = nextW;
                }
            }
        }
        ans += A[n] - 1;
        printf("%lld\n", ans);
    }
    
    return 0;
}