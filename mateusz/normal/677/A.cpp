#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, h, x, ans;

int main() {

    scanf("%d %d", &n, &h);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x > h) {
            ans++;
        }
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}