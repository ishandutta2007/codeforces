#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const long long INF = 1000000000000000LL;

int n, k;
int a[N];
long long pref[N], suf[N], wsp[N];
bool failed[N];
int main() {

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n + 1; i++) {
        scanf("%d", &a[i]);
    }

    reverse(a + 1, a + n + 2);

    for (int i = 1; i <= n + 1; i++) {
        wsp[i] = a[i];
    }
    suf[n + 2] = 1LL;
    for (int i = n + 1; i >= 1; i--) {
        suf[i] = min(suf[i + 1], wsp[i] % 2 == 0? 1LL : 0LL);
        wsp[i - 1] += wsp[i] / 2;
    }

    for (int i = 1; i <= n + 1; i++) {
        pref[i] = max(-INF, min(INF, pref[i - 1] * 2 + a[i]));
        if (pref[i] == INF || pref[i] == -INF || failed[i - 1]) {
            failed[i] = true;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        long long v = 2 * pref[i - 1] + wsp[i] - a[i];
        if (i == 1 && wsp[i] == a[i]) continue;
        if (max(v, -v) < INF && failed[i] == false && suf[i + 1] == 1 && max(v, -v) <= k) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}