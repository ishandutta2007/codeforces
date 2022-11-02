#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, P, m;
long long a[250001];

int main() {
    scanf("%d%d", &n, &P);
    a[0] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] * i % P;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] * a[n - i] % P * (n - i + 1) % P * (n - i + 1) % P,
        ans %= P;
    printf("%I64d\n", ans);
}