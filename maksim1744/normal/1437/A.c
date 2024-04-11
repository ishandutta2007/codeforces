/*
    author:  Maksim1744
    created: 27.10.2020 17:36:51
*/

#include <stdio.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

void test_case() {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    long long a = r + 1;
    long long last = a - 1;
    long long first = last - (r - l);
    if (first <= 0 || first * 2 < a) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test_case();
    }
    return 0;
}