#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, ile, x;
int cnt[N];

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ile);
        while (ile--) {
            scanf("%d", &x);
            cnt[x] = true;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 0) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}