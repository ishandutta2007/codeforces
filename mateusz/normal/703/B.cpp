#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k, x;
int c[N];
bool isCapital[N];

int main() {

    scanf("%d %d", &n, &k);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        sum += c[i];
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d", &x);
        isCapital[x] = true;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (isCapital[i]) {
            sum -= c[i];
            ans += (long long)c[i] * sum;
        } else {
            if (i == 1) {
                if (!isCapital[n]) {
                    ans += (long long)c[i] * c[n];
                }
            } else {
                if (!isCapital[i - 1]) {
                    ans += (long long)c[i] * c[i - 1];
                }
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}