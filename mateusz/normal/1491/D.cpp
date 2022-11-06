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

int n;
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if (b < a) {
            printf("NO\n");
            continue;
        }
        bool ans = true;
        vector<int> digA, digB;
        int cntA = 0, cntB = 0;
        for (int i = 0; i < 30; i++) {
            digA.push_back(a % 2);
            digB.push_back(b % 2);
            cntA += a % 2;
            cntB += b % 2;
            a /= 2;
            b /= 2;
        }
        
        if (cntB > cntA) ans = false;
        
        bool found = false;
        for (int i = 29; i >= 0; i--) {
            if (digB[i] == 0) continue;
            bool good = false;
            for (int j = i; j >= 0; j--) {
                if (digA[j] == 1) {
                    digA[j] = 0;
                    digB[i] = 0;
                    if (j < i) {
                        found = true;
                    }
                    good = true;
                    break;
                }
            }
            if (!good) {
                ans = false;
            }
        }
        
        if (!found) {
            for (int i = 0; i < 30; i++) {
                if (digA[i]) ans = false;
            }
        }
        printf(ans ? "YES\n" : "NO\n");
    }
    
    return 0;
}