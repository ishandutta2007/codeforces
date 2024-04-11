#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, h[N], ans[N];

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }

    int curMax = 0;
    for (int i = n; i >= 1; i--) {
        ans[i] = max(0, curMax + 1 - h[i]);
        curMax = max(curMax, h[i]);
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}