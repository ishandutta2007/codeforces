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

const int N = 405;

int Next[N][105];
int dp[N][N];

bool good(string a, string s, string t) {
    s = '#' + s;
    t = '#' + t;
    int l = a.size() - 1;
    int n = s.size() - 1;
    int m = t.size() - 1;
    vector<int> nxt(26, l + 1);
    for (int i = 0; i < 26; i++) {
        Next[l + 1][i] = l + 1;
    }
    for (int i = l; i >= 1; i--) {
        nxt[a[i]] = i;
        for (int j = 0; j < 26; j++) {
            Next[i][j] = nxt[j];
        }
    }
    
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) continue;
            dp[i][j] = min(i > 0 ? Next[min(l + 1, dp[i - 1][j] + 1)][s[i]] : 1e9,
                           j > 0 ? Next[min(l + 1, dp[i][j - 1] + 1)][t[j]] : 1e9);
        }
    }
    
    if (dp[n][m] < l + 1) {
        return true;
    }
    return false;
    
}

int main() {
    
    int tests;
    cin >> tests;
    while (tests--) {
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < s.size(); i++) {
            s[i] -= 'a';
        }
        for (int i = 0; i < t.size(); i++) {
            t[i] -= 'a';
        }
        s = '#' + s;
        bool found = false;
        for (int i = 0; i < t.size(); i++) {
            if (good(s, t.substr(0, i), t.substr(i))) {
                found = true;
                break;
            }
        }
        
        printf(found ? "YES\n" : "NO\n");
        
    }
    
    return 0;
}