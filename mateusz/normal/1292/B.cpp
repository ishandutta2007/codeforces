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

long long x0, yy0, ax, ay, bx, by, ys, xs, t;

int main() {
    
    scanf("%lld %lld %lld %lld %lld %lld", &x0, &yy0, &ax, &ay, &bx, &by);
    scanf("%lld %lld %lld", &xs, &ys, &t);
    
    vector<long long> x, y;
    
    while (x0 - xs + yy0 - ys <= t) {
        x.push_back(x0);
        y.push_back(yy0);
        x0 = ax * x0 + bx;
        yy0 = ay * yy0 + by;
    }
    
    int ans = 0;
    for (int i = 0; i < x.size(); i++) {
        for (int j = i; j < x.size(); j++) {
            long long dist = min(abs(xs - x[i]) + abs(ys - y[i]), abs(xs - x[j]) + abs(ys - y[j]));
            if (dist > t) continue;
            for (int k = i + 1; k <= j; k++) {
                dist += abs(x[k] - x[k - 1]) + abs(y[k] - y[k - 1]);
                if (dist > t) break;
            }
            if (dist > t) continue;
            ans = max(ans, j - i + 1);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}