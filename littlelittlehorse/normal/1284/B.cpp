#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, a[100001], b[100001], c[100001];

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int l;
        scanf("%d", &l);
        for (int j = 1; j <= l; j++)
            scanf("%d", &a[j]);
        bool ok = true;
        for (int j = 2; j <= l && ok; j++)
            if (a[j] > a[j - 1])
                ok = false;
        if (ok)
            b[++cnt] = a[1], c[cnt] = a[l];
    }
    sort(b + 1, b + cnt + 1);
    sort(c + 1, c + cnt + 1);
    int l = 1;
    long long ans = 0;
    for (int i = 1; i <= cnt; i++) {
        for (; l <= cnt && c[i] >= b[l]; ++l);
        ans += l - 1;
    }
    printf("%I64d\n", 1LL * n * n - ans);
}