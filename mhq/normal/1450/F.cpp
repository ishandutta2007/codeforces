#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int a[maxN];
int cnt[maxN];
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
            cin >> a[i];
            cnt[i] = 0;
        }
        cnt[a[1]]++;
        cnt[a[n]]++;
        vector<int> cuts;
        int bad = 0;
        cuts.emplace_back(0);
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i + 1]) {
                bad++;
                cuts.emplace_back(i);
                cnt[a[i]]++;
                cnt[a[i + 1]]++;
            }
        }
        cuts.emplace_back(n);
        int pos = 0;
        int F = 0;
        for (int i = 1; i <= n; i++) {
            F += cnt[i];
            if (pos == 0 || cnt[i] > cnt[pos]) pos = i;
        }
        int mx = cnt[pos];
        if (2 * mx - F <= 2) {
            cout << bad << '\n';
            continue;
        }
        int add = 2 * mx - F - 2;
        for (int i = 0; i + 1 < cuts.size(); i++) {
            int from = cuts[i] + 1;
            int to = cuts[i + 1];
            for (int j = from; j < to; j++) {
                if (a[j] != pos && a[j + 1] != pos) {
                    if (add > 0) {
                        add -= 2;
                        bad++;
                    }
                }
            }
        }
        if (add <= 0) {
            cout << bad << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }

    return 0;
}