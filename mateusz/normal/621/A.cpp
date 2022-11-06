#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, tab[N];
long long sum;

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        sum += tab[i];
    }

    if (sum % 2 == 0) {
        printf("%I64d\n", sum);
        return 0;
    }

    sort(tab + 1, tab + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (tab[i] % 2 == 1) {
            printf("%I64d\n", sum - tab[i]);
            return 0;
        }
    }

    return 0;
}