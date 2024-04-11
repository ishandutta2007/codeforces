#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, s;
int depth[N];
int cnt[N];
int suf[N];

int main() {

    scanf("%d %d", &n, &s);

    int rootMistake = 0;
    int additional = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &depth[i]);
        if (i == s) {
            if (depth[i] != 0) {
                rootMistake++;
            }
        } else if (depth[i] == 0) {
            additional++;
        } else {
            cnt[depth[i]]++;
        }
    }

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + cnt[i];
    }

    int ans = n;
    int empty = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (cnt[i] == 0) {
            empty++;
        }
        ans = min(ans, suf[i + 1] + max(0, empty - suf[i + 1] - additional));
    }

    printf("%d\n", ans + rootMistake + additional);
    return 0;
}