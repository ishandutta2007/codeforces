#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; 
long long sqr(long long a) {
    return a * a;
}

int main() {
    long long x[3], y[3];
    for(int i = 0; i < 3; ++i)
            cin >> x[i] >> y[i];
    int p[3] = {0, 1, 2};
    for(int i = 0; i < 6; ++i) {
            int a = p[0], b = p[1], c = p[2];
            if((sqr(x[a] - x[b]) + sqr(y[a] - y[b]) + sqr(x[a] - x[c]) + sqr(y[a] - y[c])) == (sqr(x[b] - x[c]) + sqr(y[c] - y[b]))) {
                        cout << "RIGHT";
                        return 0;
            }
            next_permutation(p, p + 3);
    }
    
    for(int j = 0; j < 3; ++j)
      for(int k = 0; k < 4; ++k) {
              p[0] = 0;
              p[1] = 1;
              p[2] = 2;
              x[j] = x[j] + dx[k];
              y[j] = y[j] + dy[k];
              bool ok = true;
              long long A = y[2] - y[0], B = x[0] - x[2], C = -(A * x[0] + B * y[0]);
              if(A * x[1] + B * y[1] + C != 0 && ok) {
                  for(int i = 0; i < 6; ++i) {
                        int a = p[0], b = p[1], c = p[2];
                        if(sqr(x[a] - x[b]) + sqr(y[a] - y[b]) + sqr(x[a] - x[c]) + sqr(y[a] - y[c]) == sqr(x[b] - x[c]) + sqr(y[c] - y[b])) {
                                    cout << "ALMOST";
                                    return 0;
                        }
                        next_permutation(p, p + 3);
                 }
              }
             x[j] = x[j] - dx[k];
             y[j] = y[j] - dy[k];
    }
    cout << "NEITHER";
    
    cin >> x[0];
    return 0;
}