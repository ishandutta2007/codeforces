/*
    author:  Maksim1744
    created: 27.10.2020 17:52:14
*/

#include <stdio.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

int a[200050];

void test_case() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int last_layer = 1;
    int next_layer = 0;
    int ans = 1;
    int i = 1;
    while (i < n) {
        if (last_layer == 0) {
            last_layer = next_layer;
            next_layer = 0;
            ++ans;
        }
        last_layer--;
        ++i;
        ++next_layer;
        while (i < n && a[i] > a[i - 1]) {
            ++i;
            ++next_layer;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test_case();
    }
    return 0;
}