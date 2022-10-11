#include <iostream>
#include <cstdio>
using namespace std;

int n, f[2][2];
string a, b;

int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        f[a[i] - '0'][b[i] - '0']++;
    printf("%lld", 1LL * f[0][0] * f[1][1] + 1LL * f[0][1] * f[1][0] + 1LL * f[0][0] * f[1][0]);
}