#include <iostream>
#include <vector>
using namespace std;

long long dist(int a, int b, int c, int d) {
     return (a - c) * (a - c) + (b - d) * (b - d);
}

int main() {
    int xa, xb, ya, yb;
    
    cin >> xa >> ya >> xb >> yb;
    
    if(xa > xb)
          swap(xa, xb);
    if(ya > yb)
          swap(ya, yb);
    vector<int> x, y;
    for(int i = ya; i < yb; ++i) {
            x.push_back(xa);
            y.push_back(i);
    }
    for(int i = xa; i < xb; ++i) {
            x.push_back(i);
            y.push_back(yb);
    }
    for(int i = yb; i > ya; --i) {
            x.push_back(xb);
            y.push_back(i);
    }
    for(int i = xb; i > xa; --i) {
            x.push_back(i);
            y.push_back(ya);
    }
    int m = x.size(), n;
    
    cin >> n;
    
    int X[n], Y[n], r[n];
    
    for(int i = 0; i < n; ++i)
            cin >> X[i] >> Y[i] >> r[i];
    
    int res = 0;
    
    for(int i = 0; i < m; ++i) {
            bool ok = false;
            for(int j = 0; j < n; ++j)
                    if(dist(x[i], y[i], X[j], Y[j]) <= r[j] * r[j])
                                  ok = true;
            if(!ok)
                   ++res;
    }
    
    cout << res;
    
    cin >> n;
    
    return 0;
}