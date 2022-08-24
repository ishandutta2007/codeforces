#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        map<int,int> all;
        int f = 2;
        int n;
        cin >> n;
        all[f] = 1;
        while (1LL * f * f <= n) {
            f *= f;
            all[f] = 1;
        }
        vector<int> a(n + 1);
        iota(a.begin(), a.end(), 0);
        vector<pair<int,int>> op;
        for (int i = 2; i < n; i++) {
            if (all.count(i)) continue;
            op.emplace_back(i, n);
            a[i] = (a[i] + n - 1) / n;
        }
        if (!all.count(n)) {
            a[n] = (a[n] + f - 1) / f;
            a[n] = (a[n] + f - 1) / f;
            op.emplace_back(n, f);
            op.emplace_back(n, f);
            assert(a[n] == 1);
        }
        while (f > 2) {
            int was = sqrt(f) + 2;
            while (was * was > f) was--;
            a[f] = (a[f] + was - 1) / was;
            a[f] = (a[f] + was - 1) / was;
            op.emplace_back(f, was);
            op.emplace_back(f, was);
            assert(a[f] == 1);
            f = was;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for (int& v : a) {
            if (v == 1) cnt1++;
            if (v == 2) cnt2++;
        }
        assert(cnt1 == n - 1 && cnt2 == 1);
        assert(op.size() <= n + 5);
        cout << op.size() << '\n';
        for (auto& it : op) {
            cout << it.first << " " << it.second << '\n';
        }
    }
    return 0;
}