/*
    author:  Maksim1744
    created: 13.11.2020 19:09:41
*/

#include <stdio.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

long long a[200050];

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int ii = 0; ii < 2; ++ii) {
        for (int l = 0; l + 3 <= n; ++l) {
            long long s = a[l + 1];
            for (int r = l + 2; r < n; ++r) {
                if (s > a[l] * 2) break;
                if ((a[l] ^ a[r]) == s) {
                    if (a[l] > a[r]) {
                        ans++;
                    }
                }
                s += a[r];
            }
        }
        for (int i = 0; i < n - i - 1; ++i) {
            long long c = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = c;
        }
    }
    printf("%d", ans);
    return 0;
}