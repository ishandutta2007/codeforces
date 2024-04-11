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

int used = 0;
long long f(int x) {
    if (used == 0) {
        return (long long)x * (x - 1) / 2;
    } else if (used == 1) {
        return x;
    } else {
        return 1;
    }
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        string s;
        used = 0;
        while (n > 0) {
            if (f(n - 1) >= k) {
                s += 'a';
            } else {
                s += 'b';
                k -= f(n - 1);
                used++;
            }
            n--;
        }
        printf("%s\n", s.c_str());
    }
    
    return 0;
}