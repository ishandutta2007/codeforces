#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

const double eps = 1e-7;

int main() {
    double vp, vd, t, f, c;
    
    cin >> vp >> vd >> t >> f >> c;
    
    if(vp >= vd) {
          cout << 0;
          return 0;
    }
    
    int ans = 0;
    double x = vp * t, xd = 0;
    
    while(x < c) {
            double tm = (x - xd) / (vd - vp);
            x += tm * vp;
            if(x + eps >= c)
                 break;
            ans++;
            tm = x / vd + f;
            xd = 0;
            x += tm * vp;
    }
    
    cout << ans << endl;
    
    cin >> c;
    
    return 0;
}