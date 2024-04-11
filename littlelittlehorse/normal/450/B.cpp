#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long a[3], f[3][3];
const int P = 1000000007;
int n;

inline void af(){
    long long w[3];
    memset(w, 0, sizeof(w));
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            w[i] += a[j] * f[j][i] % P, 
            w[i] %= P;
    for (int i = 1; i <= 2; i++) a[i] = w[i];
}

inline void ff(){
    long long w[3][3];
    memset(w, 0, sizeof(w));
    for (int i = 1; i <= 2; i++)
        for (int k = 1; k <= 2; k++)
            if (f[i][k])
                for (int j = 1; j <= 2; j++)
                    if (f[k][j])
                        w[i][j] += f[i][k] * f[k][j] % P,
                        w[i][j] %= P;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++) f[i][j] = w[i][j];
}
    
int main(){
    cin >> a[1] >> a[2];
    if (a[1] < 0) a[1] += P;
    if (a[2] < 0) a[2] += P;
    cin >> n;
    f[1][1] = 0; f[1][2] = P - 1;
    f[2][1] = 1; f[2][2] = 1;
    n -= 1;
    for (; n; n >>= 1, ff())
        if (n & 1) af();
    cout << a[1] << endl;
}