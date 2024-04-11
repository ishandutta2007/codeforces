/*
    author:  Maksim1744
    created: 13.11.2020 17:45:46
*/

#include <stdio.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

int a[100050];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int xr = 0;
    for (int i = 0; i < n; ++i) {
        xr ^= a[i];
    }
    if (n % 2 == 0 && xr != 0) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    printf("%d\n", (n - 1) / 2 * 2);

    for (int r = 2; r < n; r += 2) {
        printf("%d %d %d\n", r - 1, r, r + 1);
    }
    for (int r = (n - 1) / 2 * 2; r >= 2; r -= 2) {
        printf("%d %d %d\n", r - 1, r, r + 1);
    }

    return 0;
}