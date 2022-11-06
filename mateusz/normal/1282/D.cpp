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

int ask(string s) {
    cout << s << endl;
    int res;
    cin >> res;
    if (res == 0) exit(0);
    return res;
}

int main() {
    
    
    int n = ask("a");
    
    if (n == 300) {
        string zap = "";
        for (int i = 0; i < n; i++) {
            zap += 'b';
        }
        ask(zap);
    }
    
    string zap;
    for (int i = 0; i < n + 1; i++) {
        zap += 'a';
    }
    
    int r = ask(zap);
    if (r == n + 1) {
        string ans;
        for (int i = 0; i < n; i++) {
            ans += 'b';
        }
        assert(ask(ans) == 0);
        return 0;
    }
    
    n++;
    for (int i = 0; i < n - 1; i++) {
        zap[i] = 'b';
        int r2 = ask(zap);
        if (r2 > r) {
            zap[i] = 'a';
            continue;
        }
        r = r2;
    }
    
    assert(r <= 1);
    
    if (r == 1) {
        zap[n - 1] = 'b';
    }
    
    ask(zap);
    
    return 0;
}