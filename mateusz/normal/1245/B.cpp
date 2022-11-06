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

char word[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, r, p, s;
        scanf("%d %d %d %d", &n, &r, &p, &s);
        scanf("%s", &word[1]);
        int r2 = 0, p2 = 0, s2 = 0;
        for (int i = 1; i <= n; i++) {
            if (word[i] == 'R') r2++;
            if (word[i] == 'P') p2++;
            if (word[i] == 'S') s2++;
        }
        int wins = min(r, s2) + min(p, r2) + min(s, p2);
        if (2 * wins >= n) {
            printf("YES\n");
            int rLeft = max(0, r - s2);
            int pLeft = max(0, p - r2);
            int sLeft = max(0, s - p2);
            for (int i = 1; i <= n; i++) {
                if (word[i] == 'R') {
                    if (p > 0) {
                        p--;
                        printf("P");
                    } else {
                        if (rLeft > 0) {
                            rLeft--;
                            r--;
                            printf("R");
                        } else if (sLeft > 0) {
                            sLeft--;
                            s--;
                            printf("S");
                        }
                    }
                } else if (word[i] == 'P') {
                    if (s > 0) {
                        s--;
                        printf("S");
                    } else {
                        if (pLeft > 0) {
                            pLeft--;
                            p--;
                            printf("P");
                        } else if (rLeft > 0) {
                            rLeft--;
                            r--;
                            printf("R");
                        }
                    }
                } else {
                    if (r > 0) {
                        r--;
                        printf("R");
                    } else {
                        if (pLeft > 0) {
                            pLeft--;
                            p--;
                            printf("P");
                        } else if (sLeft > 0) {
                            sLeft--;
                            s--;
                            printf("S");
                        }
                    }
                }
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}