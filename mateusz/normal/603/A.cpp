#include <bits/stdc++.h>

using namespace std;

const int N = 100005, INF = 1e9;

int n;
char tab[N];
int suf1[N], suf0[N], pref1, pref0;

int main() {

    scanf("%d", &n);
    scanf("%s", &tab[1]);

    for (int i = 1; i <= n; i++) {
        tab[i] -= 48;
    }

    for (int i = n; i >= 1; i--) {
        if (tab[i]) {
            suf1[i] = max(suf1[i + 1], suf0[i + 1] + 1);
            suf0[i] = suf0[i + 1];
        } else {
            suf0[i] = max(suf1[i + 1] + 1, suf0[i + 1]);
            suf1[i] = suf1[i + 1];
        }
    }
    int ans = max(suf0[1], suf1[1]);
    bool found = false;
    for (int i = 2; i < n; i++) {
        if (tab[i] == 0 && tab[i - 1] == 0 && tab[i + 1] == 0) {
            ans += 2;
            found = true;
            break;
        }
        if (tab[i] == 1 && tab[i - 1] == 1 && tab[i + 1] == 1) {
            ans += 2;
            found = true;
            break;
        }
    }

    if (!found) {
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (tab[i] == 0 && tab[i - 1] == 0) {
                cnt++;
            }
            if (tab[i] == 1 && tab[i - 1] == 1) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            ans += 2;
        } else if (cnt) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}