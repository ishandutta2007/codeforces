#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
bool okPref[maxN];
bool okSuf[maxN];
int a[maxN];
vector<int> byPos[maxN];
bool ex[maxN];
bool oktot[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            byPos[i].clear();
            ex[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            byPos[a[i]].emplace_back(i);
            ex[a[i]] = true;
        }
        oktot[0] = true;
        okSuf[n + 1] = true;
        okPref[0] = true;
        for (int i = 1; i <= n; i++) {
            oktot[i] = oktot[i - 1];
            if (!ex[i]) {
                oktot[i] = false;
            }
        }
        for (int i = 1; i <= n; i++) {
            okPref[i] = okPref[i - 1];
            if (i > 1 && a[i] <= a[i - 1]) {
                okPref[i] = false;
            }
        }
        for (int i = n; i >= 1; i--) {
            okSuf[i] = okSuf[i + 1];
            if (i < n && a[i] <= a[i + 1]) {
                okSuf[i] = false;
            }
        }
        vector<bool> good(n + 1, false);
        int l = n + 1;
        int r = 0;
        int cnt = 0;
        for (int k = 1; k <= n; k++) {
            for (int v : byPos[n - k + 1]) {
                l = min(l, v);
                r = max(r, v);
                cnt++;
            }
            if (k == 1) {
                if (oktot[n]) {
                    good[k] = true;
                }
                continue;
            }
            if ((r - l + 1) != k || cnt != k) continue;
            if (!oktot[n - k + 1]) continue;
            if (!okPref[l - 1] || !okSuf[r + 1]) continue;
            good[k] = true;
        }
        for (int i = 1; i <= n; i++) {
            if (good[i]) cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }

    return 0;
}