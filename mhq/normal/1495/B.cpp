#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int lenL[maxN];
int lenR[maxN];
int p[maxN];
int secL[maxN];
int secR[maxN];
int pref[maxN], suf[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (i == 1 || p[i - 1] > p[i]) lenL[i] = 0;
        else lenL[i] = lenL[i - 1] + 1;
    }
    for (int i = n; i >= 1; i--) {
        if (i == n || p[i + 1] > p[i]) lenR[i] = 0;
        else lenR[i] = lenR[i + 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1 || p[i - 1] < p[i]) secL[i] = 0;
        else secL[i] = secL[i - 1] + 1;
    }
    for (int i = n; i >= 1; i--) {
        if (i == n || p[i + 1] < p[i]) secR[i] = 0;
        else secR[i] = secR[i + 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = max(pref[i - 1], max(secL[i], secR[i]));
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = max(suf[i + 1], max(secL[i], secR[i]));
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (lenL[i] == 0 || lenR[i] == 0) continue;
        int at_least = 0;
        if (i - lenL[i] - 1 > 0) at_least = max(at_least, pref[i - lenL[i] - 1]);
        at_least = max(at_least, secL[i - lenL[i]]);
        if (i + lenR[i] + 1 <= n) at_least = max(at_least, suf[i + lenR[i] + 1]);
        at_least = max(at_least, secR[i + lenR[i]]);
        if (at_least >= max(lenL[i], lenR[i])) continue;
        if (lenL[i] % 2 == 1 && max(secR[i - lenL[i]], secL[i - lenL[i]]) >= lenR[i]) continue;
        if (lenR[i] % 2 == 1 && max(secR[i + lenR[i]], secL[i + lenR[i]]) >= lenL[i]) continue;
        if (lenL[i] % 2 == 0 && lenL[i] - 1 >= lenR[i]) continue;
        if (lenR[i] % 2 == 0 && lenR[i] - 1 >= lenL[i]) continue;
        cnt++;
    }
    cout << cnt;
    return 0;
}