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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005;

int x[5], y[5], xs[5], ys[5];

int main() {
    
    for (int i = 1; i <= 3; i++) {
        scanf("%d %d", &x[i], &y[i]);
        xs[i] = x[i];
        ys[i] = y[i];
    }
    
    sort(xs + 1, xs + 1 + 3);
    sort(ys + 1, ys + 1 + 3);
    
    
    vector<pair<int, int> > cells;
    for (int i = 1; i <= 3; i++) {
        int xx = x[i];
        int yy = y[i];
        while (xx > xs[2]) {
            cells.push_back({xx, yy});
            xx--;
        }
        
        while (xx < xs[2]) {
            cells.push_back({xx, yy});
            xx++;
        }
        
        while (yy > ys[2]) {
            cells.push_back({xx, yy});
            yy--;
        }
        
        while (yy < ys[2]) {
            cells.push_back({xx, yy});
            yy++;
        }
    }
    
    cells.push_back({xs[2], ys[2]});
    
    printf("%d\n", cells.size());
    for (auto p : cells) {
        printf("%d %d\n", p.first, p.second);
    }
    
    return 0;
}