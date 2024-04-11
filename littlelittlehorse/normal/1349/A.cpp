#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

bool b[200001];
int n, a[200001];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    memset(b, false, sizeof(b));
    for (int i = 2; i <= 200000; i++) 
        if (!b[i])
            for (int j = i + i; j <= 200000; j += i)
                b[j] = true;
    long long res = 1;
    for (int i = 2; i <= 200000; i++)
        if (!b[i]) {
            for (;;) {
                int cnt = 0;
                for (int j = i; j <= 200000; j += i)
                    if (a[j])
                        cnt += a[j], a[j / i] += a[j], a[j] = 0;
                if (cnt >= n - 1)
                    res *= i;
                else
                    break;
            }
        }
    printf("%lld\n", res);
}