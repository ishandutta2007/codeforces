#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long;
int n;
ll a[nax];
ll b[nax][3];

int main() {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%lld", a + i);
    }

    if (n == 1) {
        puts("1 1");
        printf("%d\n", -a[1]);
        puts("1 1");
        printf("0\n");
        puts("1 1");
        printf("0\n");
        return 0;
    }

    printf("%d %d\n", 1, n);
    for (int i = 1 ; i <= n ; ++ i)
        printf("%lld ", -a[i] * n);
    printf("\n%d %d\n", 1, n - 1);
    for (int i = 1 ; i < n ; ++ i) {
        printf("%lld ", a[i] * (n - 1));
    }

    printf("\n%d %d\n", n, n);
    printf("%lld\n", a[n] * (n - 1));

}
/*
    Long time no CF round...
*/