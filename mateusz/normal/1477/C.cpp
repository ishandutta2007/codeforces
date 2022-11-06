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
int x[5005], y[5005];

long long dist(int a, int b) {
    return (long long)(x[a] - x[b]) * (x[a] - x[b]) + (long long)(y[a] - y[b]) * (y[a] - y[b]);
}

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    vector<int> ans;
    ans.push_back(1);
    int cur = 1;
    vector<int> points;
    for (int i = 2; i <= n; i++) {
        points.push_back(i);
    }
    
    while (!points.empty()) {
        int best = 0;
        for (int i = 1; i < points.size(); i++) {
            if (dist(points[i], cur) > dist(points[best], cur)) {
                best = i;
            }
        }
        ans.push_back(points[best]);
        cur = points[best];
        swap(points[best], points.back());
        points.pop_back();
    }
    
    for (auto p : ans) {
        printf("%d ", p);
    }
    printf("\n");
    
    return 0;
}