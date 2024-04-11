#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 200010;

inline bool Cmin(int &a, int b) {
    return (!~a || a > b) ? (a = b, 1) : 0;
}

int n, m;
int a[N], b[N], c[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    int res = -1, sum = 0, rest = 0;
    for (int i = 1; i <= m; ++i)
        if (b[i]) ++rest;
    int t;
    for (t = 1; t <= n; ++t)
        if (++c[a[t]] > b[a[t]]) ++sum;
        else if (c[a[t]] == b[a[t]]) {
            if (!--rest) break;
        }
    if (t <= n) res = sum;
    for (int i = 2; t <= n; ++i) {
        if (--c[a[i - 1]] < b[a[i - 1]]) {
            for (; t < n && c[a[i - 1]] < b[a[i - 1]]; ) {
                ++c[a[++t]];
                if (c[a[t]] > b[a[t]]) ++sum;
            }
            if (c[a[i - 1]] < b[a[i - 1]]) break;
        } else --sum;
        Cmin(res, sum);
    }
    printf("%d\n", res);
    return 0;
}