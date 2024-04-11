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
#define F first
#define S second
#define pb push_back

struct event { // 0  - end 1 - begin
       double x;
       int type;
       event(double d, int t): x(d), type(t) {}
};

bool cmp(event a, event b) {
     return a.x < b.x || a.x == b.x && a.type < b.type;
}

vector<event> e;

int main() {
    ll n, l, v1, v2;
    
    cin >> n >> l >> v1 >> v2;
    ll x[n];
    for(int i = 0; i < n; ++i)
            cin >> x[i];
            
    vector<event> e;
    for(int i = 0; i < n; ++i) {
            double dx = (double) l * v2 / (double)(v1 + v2);
            double xs = x[i] - dx, xe = x[i];
            if(xs < 0) {
                  e.push_back(event(xs + 2 * l, 1));
                  e.push_back(event(2 * l, 0));
                  e.push_back(event(0, 1));
            }
            else
                e.push_back(event(xs, 1));
            e.push_back(event(xe, 0));
    }
    sort(e.begin(), e.end(), cmp);
    
    double dist[n + 1];
    for(int i = 0; i <= n; ++i)
            dist[i] = 0;
    int cur = 0;
    double any = 0;
    for(int i = 0; i < e.size(); ++i) {
            if(e[i].type == 1)
                         ++cur;
            else
                --cur;
            if(cur) {
                   dist[cur] += e[i + 1].x - e[i].x;
                   any += e[i + 1].x - e[i].x;
            }
    }
    
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << (double)(2 * l - any) / (double)(2 * l) << endl;
    for(int i = 1; i <= n; ++i)
            cout << dist[i] / (double)(2 * l) << endl;
    cin >> n;
    return 0;
}