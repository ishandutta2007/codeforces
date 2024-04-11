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

int tab[N];

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        debug(s);
        string ans = s;
        int bestK = 1;
        for (int i = 0; i < n; i++) {
            string pref = s.substr(i);
            string suf = s.substr(0, i);
            if ((n - i) % 2 == 1) {
                reverse(suf.begin(), suf.end());
            }
            debug(pref, suf);
            if (pref + suf < ans) {
                ans = pref + suf;
                bestK = i + 1;
            }
        }
        reverse(s.begin(), s.end());
        if (s < ans) {
            ans = s;
            bestK = n;
        }
        cout << ans << "\n" << bestK << endl;
    }
    
    return 0;
}