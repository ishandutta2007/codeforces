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

const int N = 100005;

void test() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int cnt = 0;
    if (b < c) swap(b, c);
    if (a < b) swap(a, b);
    if (b < c) swap(b, c);
    if (a > 0) {
        a--;
        cnt++;
    }
    if (b > 0) {
        b--;
        cnt++;
    }
    if (c > 0) {
        c--;
        cnt++;
    }
    if (min(a, b) > 0) {
        a--;
        b--;
        cnt++;
    }
    if (min(a, c) > 0) {
        a--;
        c--;
        cnt++;
    }
    if (min(b, c) > 0) {
        b--;
        c--;
        cnt++;
    }
    if (min(min(a, b), c) > 0) {
        a--;
        b--;
        c--;
        cnt++;
    }
    printf("%d\n", cnt);
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) test();
    
    return 0;
}