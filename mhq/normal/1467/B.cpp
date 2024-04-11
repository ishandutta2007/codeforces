#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int f = 0;
        for (int i = 1; i + 1 < n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) f++;
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) f++;
        }
        int best = f;
        int cur = 0;
        auto add = [&](int where) {
            if (where <= 0 || where >= n - 1) return;
            if (a[where] > a[where - 1] && a[where] > a[where + 1]) cur++;
            if (a[where] < a[where - 1] && a[where] < a[where + 1]) cur++;
        };
        auto del = [&](int where) {
            if (where <= 0 || where >= n - 1) return;
            if (a[where] > a[where - 1] && a[where] > a[where + 1]) cur--;
            if (a[where] < a[where - 1] && a[where] < a[where + 1]) cur--;
        };
        for (int x = 0; x < n; x++) {
            vector<int> vals;
            if (x > 0) vals.emplace_back(a[x - 1] - 1);
            if (x > 0) vals.emplace_back(a[x - 1] + 1);
            if (x > 0) vals.emplace_back(a[x - 1]);
            if (x + 1 < n) vals.emplace_back(a[x + 1] + 1);
            if (x + 1 < n) vals.emplace_back(a[x + 1] - 1);
            if (x + 1 < n) vals.emplace_back(a[x + 1]);
            vals.emplace_back(-1e9);
            vals.emplace_back(1e9);
            for (int p : vals) {
                cur = f;
                int was = a[x];
                del(x);
                del(x - 1);
                del(x + 1);
                a[x] = p;
                add(x);
                add(x + 1);
                add(x - 1);
                best = min(best, cur);
                a[x] = was;
            }
        }
        cout << best << '\n';
    }
    return 0;
}