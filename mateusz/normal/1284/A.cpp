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

const int N = 1005;

int n, m;
string s[N], t[N], res[N];

int main() {
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    
    int p = 0, q = 0;
    for (int i = 0; i < n * m; i++) {
        res[i] = s[p] + t[q];
        p++;
        q++;
        if (p == n) p = 0;
        if (q == m) q = 0;
    }
    
    cin >> q;
    
    while (q--) {
        cin >> p;
        cout << res[((p - 1) % (n * m))] << endl;
    }
    
    return 0;
}