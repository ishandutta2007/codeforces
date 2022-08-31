/*
    author:  Maksim1744
    created: 27.10.2020 17:39:33
*/

#include <stdio.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

char s[100020];

void test_case() {
    int n;
    scanf("%d", &n);
    scanf("%s", &s);
    int sim = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1]) {
            sim++;
        }
    }
    printf("%d\n", (sim + 1) / 2);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test_case();
    }
    return 0;
}