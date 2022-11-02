#include <iostream>
#include <map>
#include <cmath>
using namespace std;

long long v[500 * 1000], x[500 * 1000], n;

bool can(double t) {
     double maxF = -1e15;
     bool ok = false;
     for(int i = 0; i < n && !ok; ++i) {
             double X = (double)x[i] + (double)v[i] * t;
             if(v[i] > 0) 
                     maxF = max(maxF, X);
             else 
                 if(maxF >= X)
                         ok = true;
     }
     return ok;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i)
            cin >> x[i] >> v[i];
    bool b = false, f = false;
    for(int i = 0; i < n; ++i)
            if(v[i] > 0)
                    b = true;
            else
                f = true;
    if(!(b && f)) {
           cout << -1;
           cin >> n;
           return 0;
    }
    int minf = -1;
    for(int i = 0; i < n; ++i)
            if(v[i] > 0) {
                    minf = i;
                    break;
            }
    int maxb;
    for(int i = n - 1; i >= 0; --i) 
            if(v[i] < 0) {
                    maxb = i;
                    break;
            }
    if(minf >= maxb) {
            cout << -1;
            return 0;
    }
    double l = 0, r = 1e9;
    for(int i = 0; i < 100; ++i) {
            double m = (l + r) / 2.0;
            if(can(m))
                      r = m;
            else
                l = m;
    }
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << l;
    cin >> n;
    return 0;
}