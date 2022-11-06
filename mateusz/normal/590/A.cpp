#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n;
int tab[N], ans[N], pref[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    int cur = 0;
    int best = 0;

    ans[1] = tab[1];
    ans[n] = tab[n];

    for (int i = 2; i < n; i++) {
        if (tab[i] != tab[i - 1] && tab[i] != tab[i + 1]) {
            cur++;
        } else {
            cur = 0;
        }
        pref[i] = cur;
    }

    cur = 0;
    for (int i = n - 1; i > 1; i--) {
        if (tab[i] != tab[i - 1] && tab[i] != tab[i + 1]) {
            cur++;
        } else {
            cur = 0;
        }
        ans[i] = (tab[i] + min(pref[i], cur)) % 2;
        best = max(best, min(pref[i], cur));
    }

    printf("%d\n", best);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}