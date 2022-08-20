/*
    author:  Maksim1744
    created: 23.10.2020 01:34:43
*/

#include <stdio.h>

int a[5050];

void test_case() {
    int n;
    scanf("%d", &n);
    int eq = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i != 0 && a[i] != a[i - 1]) eq = 0;
    }
    if (eq) {
        printf("NO\n");
        return;
    }
    int another = -1;
    printf("YES\n");
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[0]) {
        } else {
            another = i;
            printf("%d %d\n", 1, i + 1);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[0]) {
            printf("%d %d\n", another + 1, i + 1);
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