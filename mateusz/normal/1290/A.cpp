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
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 3505;

int n, m, k;
int tab[N];

void test() {
    
    scanf("%d %d %d", &n, &m, &k);
    k = min(k, m - 1);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    
    vector<int> minis;
    
    for (int i = 0; i < m; i++) {
        minis.push_back(max(tab[i + 1], tab[n - (m - 1 - i)]));
        debug(i, minis.back());
    }
    
    int best = 0;
    for (int i = 0; i <= k; i++) {
        int mini = 2e9;
        for (int j = i; j < m - (k - i); j++) {
            mini = min(mini, minis[j]);
        }
        best = max(best, mini);
    }
    
//     vector<pair<int, int> > s;
//     for (int i = 0; i < m - k; i++) {
//         while (!s.empty() && s.back().first >= minis[i]) {
//             s.pop_back();
//         }
//         s.push_back({minis[i], i});
//     }
//     int best = s[0].first;
//     debug(best);
//     int poc = 0;
//     for (int i = m - k; i < m; i++) {
//         while (!s.empty() && s.back().first >= minis[i]) {
//             s.pop_back();
//         }
//         s.push_back({minis[i], i});
//         while (poc < s.size() && i - s[poc].second + 1 > m - k) {
//             poc++;
//         }
//         debug(i, poc);
//         if (poc < s.size()) {
//             debug(s[poc].first);
//             best = max(best, s[poc].first);
//         }
//     }
    printf("%d\n", best);
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    
    return 0;
}