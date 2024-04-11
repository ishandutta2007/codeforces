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

struct lemming {
       ll m, v, nn;
};

bool cmp(lemming a, lemming b) {
     return a.m < b.m || (a.m == b.m && a.v < b.v);
}

lemming a[200 * 1000];
ll n, k, h;

bool can(double t, bool print) {
     int cur = 0;
     for(int i = 0; i < k; ++i) {
             while(cur < n && t * a[cur].v < h * (i + 1))
                       ++cur;
             if(cur == n)
                    return false;
             if(print)
                      cout << a[cur].nn << " ";
             ++cur;
     }
     return true;
}        

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k >> h;
    
    for(int i = 0; i < n; ++i) {
            a[i].nn = i + 1;
            cin >> a[i].m;
    }
    for(int i = 0; i < n; ++i)
            cin >> a[i].v;
    sort(a, a + n, cmp);
    double l = 0, r = 1e19;
    for(int i = 0; i < 200; ++i) {
            double m = (l + r) / 2.0;
            if(can(m, false))
                      r = m;
            else
                l = m;
    }
    can(r, true);
    cin >> n;
    return 0;
}