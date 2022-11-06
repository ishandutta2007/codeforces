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

char s[N], t[N];
int n, m;
int nxt[N][30];

int main() {
    
    int tests;
    scanf("%d", &tests);
    while (tests--) {
        scanf("%s %s", &s[1], &t[1]);
        n = strlen(s + 1);
        m = strlen(t + 1);
        for (int i = 0; i < 26; i++) {
            nxt[n + 1][i] = n + 1;
        }
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < 26; j++) {
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][s[i] - 'a'] = i;
        }
        int ptr = 1;
        int ans = 0;
        bool good = true;
        while (ptr <= m) {
            ans++;
            int pos = 1;
            bool found = false;
            while (pos <= n && ptr <= m) {
                int newPos = nxt[pos][t[ptr] - 'a'];
                if (newPos <= n) {
                    found = true;
                    pos = newPos + 1;
                    ptr++;
                } else {
                    break;
                }
            }
            if (!found) {
                good = false;
                break;
            }
        }
        if (good) {
            printf("%d\n", ans);
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}