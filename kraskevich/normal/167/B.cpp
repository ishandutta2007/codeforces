#include <iostream>
#include <map>
using namespace std;

double f[212][212][440];
const int maxN = 210;

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    int a[n];
    double p[n];
    
    for(int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i] /= 100.0;
    }
    
    for(int i = 0; i < n; ++i) 
            cin >> a[i]; 
            
    for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= n; ++j)
                    for(int t = 0; t <= 2 * n; ++t)
                            f[i][j][t] = 0;
                            
    f[0][0][k + maxN] = 1.0;
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j <= i; ++j)
                    for(int t = 0; t < 2 * maxN; ++t) {
                                 if(t + a[i] < 0)
                                      continue;
                                 f[i + 1][j + 1][min(2 * maxN - 1, t + a[i])] += p[i] * f[i][j][t];
                                 f[i + 1][j][t] += (1.0 - p[i]) * f[i][j][t];
                    }
    double res = 0;
    for(int i = l; i <= n; ++i)
            for(int j = maxN; j < 2 * maxN; ++j)
                    res += f[n][i][j];
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << res;
    return 0;
}