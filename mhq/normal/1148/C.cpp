#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 3 * (int)1e5 + 100;
int p[maxN];
int where[maxN];
vector < pair < int, int > > ans;
void add(int a, int b) {
    ans.emplace_back(a, b);
    swap(p[a], p[b]);
    where[p[b]] = b;
    where[p[a]] = a;
}
bool can(int a, int b) {
    return (abs(a - b) >= (n / 2));
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        where[p[i]] = i;
    }
    for (int i = 2; i <= n - 1; i++) {
        if (where[i] != i) {
            int c = where[i];
            if (can(c, n)) {
                add(c, n);
                if (can(i, n)) {
                    add(i, n);
                    continue;
                }
                else {
                    add(1, n);
                    add(1, i);
                    continue;
                }
            }
            else {
                add(c, 1);
                if (can(i, 1)) {
                    add(i, 1);
                    continue;
                }
                else {
                    add(1, n);
                    add(i, n);
                    continue;
                }
            }
        }
    }
    if (where[1] != 1) {
        assert(where[1] == n);
        add(1, n);
    }
    for (int i = 1; i <= n; i++) {
        assert(p[i] == i);
    }
    cout << ans.size() << '\n';
    for (auto t : ans) {
        cout << t.first << " " << t.second << '\n';
    }
    return 0;
}