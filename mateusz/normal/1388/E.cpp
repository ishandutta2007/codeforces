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

#define ll long double

struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const ll inf = 1/.0;
  ll div(ll a, ll b) { // floored division
    return a / b; }
  bool isect(iterator x, iterator y) {
    if (y == end()) { x->p = inf; return false; }
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};



const int N = 2005;




int n;
int from[N], to[N], h[N];

pair<long long, long long> check(long long dx, long long dy) {
//     debug(dx, dy);
//     long double maxX = -1e18;
//     long double minX = 1e18;
    
    long long lol = 1e18;
    long long maxX = -1e18;
    long long maxH = -1e18;
    long long minX = 1e18;
    long long minH = 1e18;
    for (int i = 1; i <= n; i++) {
//         long double xA = (long double)from[i] + dx * (long double)h[i] / dy;
//         long double xB = (long double)to[i] + dx * (long double)h[i] / dy;
        if (maxX == -lol || (long long)from[i] * dy + dx * h[i] > maxX * dy + dx * maxH) {
            maxX = from[i];
            maxH = h[i];
        }
        if (minX == lol || (long long)from[i] * dy + dx * h[i] < minX * dy + dx * minH) {
            minX = from[i];
            minH = h[i];
        }
        if (maxX == -lol || (long long)to[i] * dy + dx * h[i] > maxX * dy + dx * maxH) {
            maxX = to[i];
            maxH = h[i];
        }
        if (minX == lol || (long long)to[i] * dy + dx * h[i] < minX * dy + dx * minH) {
            minX = to[i];
            minH = h[i];
        }
    }
//     debug(maxX, minX);
// assert(maxX - minX >= 0);
    return {maxX - minX, maxH - minH};
//     return maxX - minX + (long double)dx * (maxH - minH) / (long double)dy;
}
int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &from[i], &to[i], &h[i]);
    }
    
    vector<pair<pair<int, int>, int> > events;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (h[i] > h[j]) {
                pair<int, int> a = make_pair(to[j] - from[i], h[i] - h[j]);
                pair<int, int> b = make_pair(from[j] - to[i], h[i] - h[j]);
                if (a.first > b.first) {
                    swap(a, b);
                }
//                 assert(a.first != b.first);
                events.push_back({a, 0});
                events.push_back({b, 1});
            }
        }
    }
    
//     debug(events);
    sort(events.begin(), events.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
       pair<int, int> l = a.first;
       pair<int, int> r = b.first;
       
//        if 
//        
       if ((long long)l.first * r.second == (long long)r.first * l.second) {
           return a.second > b.second;
       }
//        debug(l, r, l.second * r.first, r.second * l.first);
       return (long long)l.first * r.second < (long long)r.first * l.second;
    });
//     debug(events);
    int cnt = 0;
    vector<pair<int, int> > toCheck;
//     debug(events.size());
    for (auto e : events) {
        if (e.second == 1) {
            cnt--;
        }
//         assert(cnt >= 0);
//         debug(cnt);
        if (cnt == 0) {
            toCheck.push_back(e.first);
        }
        if (e.second == 0) {
            cnt++;
        }
    }
    assert(cnt == 0);
    if (toCheck.empty()) {
        toCheck.push_back({0, 1});
    }
    
    LineContainer chtMin, chtMax;
    for (int i = 1; i <= n; i++) {
        chtMin.add(-h[i], -from[i]);
        chtMax.add(h[i], to[i]);
    }
    
    long double ans = 2e18;
    long long bestX = -1, bestY = -1, bestdx = -1, bestdy = -1;
    for (auto e : toCheck) {
        ans = min(ans, chtMax.query((long double)e.first / e.second) + chtMin.query((long double)e.first / e.second));
//         auto ret = check(e.first, e.second);
//         long long dx = e.first;
//         long long dy = e.second;
// //         ans = min(ans, );
//         if (bestdy == -1 || ret.first * bestdy + dx * ret.second < bestX * dy + bestdx * bestY) {
//             bestX = ret.first;
//             bestY = ret.second;
//             bestdx = dx;
//             bestdy = dy;
//         }
    }
//     assert(bestX >= 0);
    printf("%.10Lf\n", ans);
    return 0;
}