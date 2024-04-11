/*
    author:  Maksim1744
    created: 23.10.2020 01:30:50
*/

#include <stdio.h>

int a[300000 + 20];

void test_case() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int eq = 1;
    int mx = -1;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] != a[i + 1]) {
            eq = 0;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > mx)
            mx = a[i];
    }
    if (eq) {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == mx) {
            if (i + 1 < n && a[i] > a[i + 1] || i - 1 >= 0 && a[i] > a[i - 1]) {
                printf("%d\n", i + 1);
                return;
            }
        }
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