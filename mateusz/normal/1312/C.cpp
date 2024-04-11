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
     
    const int N = 105;
     
    int n, k;
    long long tab[N];
    int digit[N][N];
     
    int main() {
        
        int t;
        scanf("%d", &t);
        while (t--) {
            scanf("%d %d", &n, &k);
            for (int i = 1; i <= n; i++) {
                scanf("%lld", &tab[i]);
                long long w = tab[i];
                for (int j = 0; j < 100; j++) {
                    digit[j][i] = w % k;
                    w /= k;
                }
            }
            
            bool bad = false;
            for (int i = 0; i < 100; i++) {
                int cnt = 0;
                for (int j = 1; j <= n; j++) {
                    if (digit[i][j] > 1) {
                        bad = true;
                    } else if (digit[i][j] == 1) {
                        cnt++;
                    }
                }
                if (cnt > 1) {
                    bad = true;
                }
                if (bad) break;
            }
            printf(!bad ? "YES\n" : "NO\n");
        }
        
        return 0;
    }