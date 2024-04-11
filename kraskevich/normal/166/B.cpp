#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
using namespace std;

typedef long long ll;

struct point {
       ll x, y;
       point(ll xx = 0, ll yy = 0): x(xx), y(yy) {}
       point operator - (const point & p) const {
             return point(x - p.x, y - p.y);
       }
       ll operator * (const point & p) const {
                   return x * p.y - p.x * y;
       }
};

point p0;

bool cmp(point a, point b) {
     return (a - p0) * (b - p0) < 0;
}

ll skalar(point a, point b) {
   return a.x * b.x + a.y * b.y;
}

const double eps = 1e-7;

bool belong(point p, point a, point b) {
     return (p - a) * (b - a) == 0;
} 

ll Abs(ll a) {
       return a > 0 ? a : -a;
} 

ll s(point a, point b) {
           return Abs(a * b);
} 

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    point t[n];
    for(int i = 0; i < n; ++i)
            cin >> t[i].x >> t[i].y;
    int cur = 0;
    for(int i = 0; i < n; ++i)
            if(t[i].x < t[cur].x || t[i].x == t[cur].x && t[i].y < t[cur].y)
                      cur = i;
    point p[n];
    for(int i = 0; i < n; ++i)
            p[i] = t[(i + cur) % n];
    int m;
    bool ok = true;
    cin >> m;
    for(int i = 0; i < m; ++i) {
            point test;
            cin >> test.x >> test.y;
            if(test.x <= p[0].x) {
                      ok = false;
                      continue;
            }
            int l = 1, r = n - 1;
            while(l < r - 1) {
                    int m = (l + r) / 2;
                    if((test - p[0]) * (p[m] - p[0]) >= 0)
                             l = m;
                    else
                        r = m;
            }
            if((test - p[0]) * (p[l] - p[0]) < 0)
                     ok = false;
            if((test - p[0]) * (p[r] - p[0]) > 0)
                     ok = false;
            if(belong(test, p[l], p[r]))
                            ok = false;
            if(belong(test, p[(r + 1) % n], p[r]))
                            ok = false;
            if(belong(test, p[l - 1], p[l]))
                            ok = false;
            if(s(p[l] - p[0], p[r] - p[0]) != s(test -  p[l], test - p[r])  + s(p[l] - p[0], test -  p[0]) + s(p[r] - p[0], test - p[0]))
                       ok = false;
    }
    cout << (ok ? "YES" :  "NO") << endl;
    cin >> n;
    return 0;
}