#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int a[n][n], res = 0;
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    cin >> a[i][j];
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                    int s1 = 0, s2 = 0;
                    for(int k = 0; k < n; ++k)
                            s1 += a[i][k], s2 += a[k][j];
                    if(s1 < s2)
                          ++res;
            }
    cout << res;
    cin >> n;
    return 0;
}