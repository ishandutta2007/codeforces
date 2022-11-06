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

bool cmp(int x, int y) {
    return abs(x) < abs(y);
}

int n;
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> xs, ys;
        int x, y;
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d %d", &x, &y);
            if (x == 0) {
                ys.push_back(y);
            } else {
                xs.push_back(x);
            }
        }
        assert(xs.size() == n && ys.size() == n);
        sort(xs.begin(), xs.end(), cmp);
        sort(ys.begin(), ys.end(), cmp);
        long double ans = 0.0;
        for (int i = 0; i < n; i++) {
            ans += sqrt(xs[i] * (long long)xs[i] + ys[i] * (long long)ys[i]);
        }
        printf("%.15Lf\n", ans);
    }
    
    return 0;
}