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

bool differentDigits(int x) {
    int cnt = 0;
    set<int> digits;
    while (x > 0) {
        cnt++;
        digits.insert(x % 10);
        x /= 10;
    }
    return digits.size() == cnt;
}

int main() {
    
    int l, r;
    scanf("%d %d", &l, &r);
    
    for (int x = l; x <= r; x++) {
        if (differentDigits(x)) {
            printf("%d\n", x);
            return 0;
        }
    }
    
    printf("-1\n");
    
    return 0;
}