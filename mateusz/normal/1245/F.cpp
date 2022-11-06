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

const int N = 30;

void add(long long &w, long long u) {
    w += u;
}

int a, b;
long long dp[N + 5][2][2][2][2];

long long getDP(int w, int x, int y, int p, int q) {
    if (w < 0) {
        return 1;
    }
    return dp[w][x][y][p][q];
}

void test() {
    scanf("%d %d", &a, &b);
    
    for (int i = 0; i < N; i++) {
        for (int IeqA = 0; IeqA < 2; IeqA++) {
            for (int IeqB = 0; IeqB < 2; IeqB++) {
                for (int JeqA = 0; JeqA < 2; JeqA++) {
                    for (int JeqB = 0; JeqB < 2; JeqB++) {
                        dp[i][IeqA][IeqB][JeqA][JeqB] = 0;
                        for (int ib = 0; ib < 2; ib++) {
                            for (int jb = 0; jb < 2; jb++) {
                                if (ib == 1 && jb == 1) {
                                    continue;
                                }
                                if (IeqA && ib < (a >> i) % 2) {
                                    continue;
                                }
                                if (IeqB && ib > (b >> i) % 2) {
                                    continue;
                                }
                                if (JeqA && jb < (a >> i) % 2) {
                                    continue;
                                } 
                                if (JeqB && jb > (b >> i) % 2) {
                                    continue;
                                }
                                add(dp[i][IeqA][IeqB][JeqA][JeqB], getDP(i - 1, IeqA && (ib == (a >> i) % 2), IeqB && (ib == (b >> i) % 2),
                                    JeqA && (jb == (a >> i) % 2), JeqB && (jb == (b >> i) % 2)));
                            }
                        }
                    }
                }
            }
        }
    }
    long long ans = 0; 
    add(ans, getDP(N - 1, 1, 1, 1, 1));
                    
    printf("%lld\n", ans);
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    
    return 0;
}