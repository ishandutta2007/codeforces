#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
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
        set<int> s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        if (s.size() == n) {
            cout << n << '\n';
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << '\n';
            continue;
        }
        if (s.size() == n - 1) {
            vector<int> cnt(n + 1);
            for (int i = 1; i <= n; i++) cnt[a[i]]++;
            vector<int> t;
            int x = -1;
            for (int i = 1; i <= n; i++) {
                if (cnt[i] > 1) {
                    assert(x == -1);
                    x = i;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] == x) t.emplace_back(i);
            }
            assert(t.size() == 2);
            int y = -1;
            for (int i = 1; i <= n; i++) {
                if (cnt[i] == 0) y = i;
            }
            if (t[1] != y) {
                a[t[1]] = y;
            }
            else {
                a[t[0]] = y;
            }
            cout << n - 1 << '\n';
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << '\n';
            continue;
        }
        vector<int> who(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            who[a[i]] = i;
        }
        vector<int> p1, p2;
        for (int i = 1; i <= n; i++) {
            if (who[a[i]] != i && who[i] == -1) {
                p1.emplace_back(i);
                p2.emplace_back(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (who[a[i]] != i && who[i] != -1) {
                p1.emplace_back(i);
            }
            if (who[a[i]] == i && who[i] == -1) {
                p2.emplace_back(i);
            }
        }
        assert(p1.size() == p2.size());
        assert(p1.size() >= 2);
        for (int x = 0; x < p1.size(); x++) {
            a[p1[x]] = (p2[(x + 1) % p1.size()]);
        }
        cout << s.size() << '\n';
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << '\n';
    }
    return 0;
}