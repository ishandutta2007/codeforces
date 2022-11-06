#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
int a[N];

int main() {


    scanf("%d", &n);
    int mini = 1e9 + 5;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mini = min(mini, a[i]);
    }

    int best = 0;
    int cur = 0;
    int pos = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (a[pos] > mini) {
            cur++;
            best = max(best, cur);
        } else {
            cur = 0;
        }
        pos++;
        if (pos > n) {
            pos -= n;
        }
    }

    printf("%I64d\n", (long long)mini * n + best);

    return 0;
}