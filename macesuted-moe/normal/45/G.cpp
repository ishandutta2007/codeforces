#include <bits/stdc++.h>
using namespace std;

int ans[6005];

bool prime(int p) {
    for (int i = 2; i <= sqrt(p); i++)
        if (p % i == 0) return false;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) ans[i] = 1;
    int m = n * (n + 1) >> 1;
    if (!prime(m)) {
        if (m & 1 && !prime(m - 2)) ans[3] = 3, m -= 3;
        for (int i = 2; i <= n; i++)
            if (prime(i) && prime(m - i)) {
                ans[i] = 2;
                break;
            }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
    return 0;
}