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

int n;
long long h[5];
int main() {
    
    cin >> h[1] >> h[2] >> h[3];
    cout << "First" << endl;
    cout << (long long)1e10 << endl;
    int which;
    cin >> which;
    h[which] += 1e10;
//     cerr << h[1] << " " << h[2] << " " << h[3] << endl;
    long long y = 3 * h[which] - h[1] - h[2] - h[3];
    cout << y << endl;
    
    cin >> which;
    h[which] += y;
    
//     cerr << h[1] << " " << h[2] << " " << h[3] << endl;
    
    sort(h + 1, h + 1 + 3);
    cout << h[2] - h[1] << endl;
    cin >> which;
    assert(which == 0);
    
    
    
    return 0;
}