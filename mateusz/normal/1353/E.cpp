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

const int N = 1000005;

int n, k;
char word[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        scanf("%s", &word[1]);
        int cntOnes = 0;
        for (int i = 1; i <= n; i++) {
            word[i] -= '0';
            if (word[i] == 0) {
                word[i] = -1;
            } else {
                cntOnes++;
            }
        }
        if (cntOnes == 0) {
            printf("0\n");
            continue;
        }
        int ans = cntOnes - 1;
        for (int i = 1; i <= k; i++) {
            int cntOnesHere = 0;
            int best = 0;
            int sum = 0;
            for (int j = i; j <= n; j += k) {
                sum += word[j];
                if (sum < 0) {
                    sum = 0;
                }
                best = max(best, sum);
                if (word[j] == 1) {
                    cntOnesHere++;
                }
            }
            ans = min(ans, cntOnesHere - best + (cntOnes - cntOnesHere));
        }
        printf("%d\n", ans);
    }
    
    return 0;
}