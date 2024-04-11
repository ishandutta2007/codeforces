#include <iostream>
#include <cstdio>
using namespace std;

double f[1001][1001], d[1001][1001];

int main() {
    int b, w;
    
    cin >> w >> b;
    
    cout.setf(ios::fixed);
    
    for(int i = 0; i <= w; ++i) {
            for(int j = 0; j <= b; ++j) {
                    f[i][j] = d[i][j] = 0;
                    if(i + j == 0) {
                         f[i][j] = 0;
                         d[i][j] = 1;
                        // cout << f[i][j] << " "  << d[i][j] << "  ";
                         continue;
                    }
                    if(i == 0) {
                         f[i][j] = 0;
                         d[i][j] = 1;
                         //cout << f[i][j] << " "  << d[i][j] << "  ";
                         continue;
                    
                    }
                    double wh = i, bl = j, sum = i + j;
                    f[i][j] = wh / sum;
                    if(j)
                         f[i][j] += (1 - d[i][j - 1]) * bl / sum;
                    if(i + j <= 2) {
                           d[i][j] = 1;
                          // cout << f[i][j] << " "  << d[i][j] << "  ";
                           continue;
                    }
                    d[i][j] = wh / sum;
                    if(j >= 2)
                         d[i][j] += (1 - f[i][j - 2]) * (bl / sum * (bl - 1) / (sum - 1));
                    if(i >= 1 && j >= 1)
                         d[i][j] += (1 - f[i - 1][j - 1]) * (bl / sum * wh / (sum - 1));
                    //cout << f[i][j] << " "  << d[i][j] << "  ";
            }
           // cout << endl;
    }
    
    printf("%.12lf", f[w][b]);
    
    cin >> w;
    
    return 0;
}