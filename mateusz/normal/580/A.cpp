#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, x;

int main() {

    scanf("%d", &n);
    int last = 1e9 + 5;
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x < last) {
            cur = 1;
        } else {
            cur++;
        }
        ans = max(ans, cur);
        last = x;
    }
    printf("%d\n", ans);

    return 0;
}