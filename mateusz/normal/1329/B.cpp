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

const int N = 35;

int dp[N][N];
int pot[N];
int d, m;

int mul(int w, int u) {
    return (long long)w * u % m;
}

void add(int &w, int u) {
    w += u;
    if (w >= m) w -= m;
}

int getDP(int x, int y) {
    if (x <= 0) return 1;
    if (y < 0) return 0;
    return dp[x][y];
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &d, &m);
        pot[0] = 1;
        for (int i = 1; i <= 30; i++) {
            pot[i] = mul(pot[i - 1], 2);
        }
        int biggestBit = 0;
        for (int i = 0; i < 30; i++) {
            if (d >> i) {
                biggestBit = i;
            }
        }
        debug(biggestBit);
        for (int i = 1; i <= biggestBit; i++) {
            for (int j = 0; j < biggestBit; j++) {
                dp[i][j] = 0;
                for (int k = -1; k < j; k++) {
                    add(dp[i][j], mul(getDP(i - 1, k), pot[j]));
                    if (i == 1) break;
                }
                debug(i, j, dp[i][j]);
            }
        }
        
        int ans = 0;
        int ile = d - (1 << biggestBit) + 1;
        add(ans, ile);
        for (int i = 1; i <= biggestBit; i++) {
            for (int j = -1; j < biggestBit; j++) {
                int d = getDP(i, j);
                debug(i, j, d, ile);
                add(ans, mul(getDP(i,j), ile));
                if (i > 0) {
                    add(ans, getDP(i,j));
                }
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}