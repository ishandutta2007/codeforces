#include <iostream>
using namespace std;

const long long base = 1000 * 1000 * 1000 + 7;
long long f[4000][4000];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < 4000; ++i)
            for(int j = 0; j < 4000; ++j)
                    f[i][j] = 0;
    for(int i = 0; i < 4000; ++i) {
            for(int j = 0; j < 4000; ++j)
                    if(i == j || j == 0)
                         f[i][j] = 1;
                    else
                        f[i][j] = (i < j ? 0 : (f[i - 1][j - 1] + f[i - 1][j]) % base);
    }
    cout << (f[n - 1][k * 2] * f[m - 1][k * 2]) % base;  
    cin >> n;
    return 0;        
}