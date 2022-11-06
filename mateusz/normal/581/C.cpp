#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k;
int a[N];

int main() {

    scanf("%d %d", &n, &k);
    int bn = n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ans += a[i] / 10;
    }

    for (int i = n; i >= 1; i--) {
        if (a[i] == 100) {
            swap(a[i], a[n]);
            n--;
        }
        a[i] %= 10;
    }

    sort(a + 1, a + 1 + n);

    for (int i = n; i >= 1; i--) {
        if (10 - (a[i] % 10) > k) {
            break;
        }
        ans++;
        k -= 10 - (a[i] % 10);
    }

    printf("%d\n", min(10 * bn, ans + k / 10));

    return 0;
}