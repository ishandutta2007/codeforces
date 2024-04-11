#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

void solve() {
    int n;
    string d;
    cin >> n >> d;

    int ok = 1;
    for (int i = 0; i + 1 < n; i++) {
        if (d[i] > d[i + 1]) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        cout << string(n, '1') << "\n";
        return;
    }
    for (int x = 0; x + 1 < 10; x++) {
        int xx = 0;
        int yy = 0;
        ok = 1;
        for (int i = 0; i < n; i++) {
            int y = d[i] - '0';
            if (y <= x) {
                if (y < xx) {
                    ok = 0;
                    break;
                } else {
                    xx = y;
                }
            } else {
                if (y < yy) {
                    ok = 0;
                    break;
                } else {
                    yy = y;
                }
            }
        }
        if (ok) {
            for (int i = 0; i < n; i++) {
                int y = d[i] - '0';
                if (y <= x) {
                    cout << '1';
                } else {
                    cout << '2';
                }
            }
            cout << '\n';
            return;
        }
    }

    for (int x = 0; x + 1 < 10; x++) {
        int pp = -1;
        for (int i = 0; i < n; i++) {
            int y = d[i] - '0';
            if (y < x) {
                pp = i;
            }
        }
        if (pp == -1) continue;
        int qq = -1;
        for (int i = 0; i < n; i++) {
            int y = d[i] - '0';
            if (y == x && i > pp) {
                qq = i;
                break;
            }
        }
        if (qq == -1) continue;
        vector<int> s1, s2;
        s1.reserve(n);
        s2.reserve(n);
        for (int i = 0; i < n; i++) {
            int y = d[i] - '0';
            if (y < x || (y == x && i >= qq)) {
                s1.push_back(i);
            } else {
                s2.push_back(i);
            }
        }
        ok = 1;
        for (int it = 1; it < (int) s1.size(); it++) {
            int now = s1[it];
            int prv = s1[it - 1];
            if (d[prv] > d[now]) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        for (int it = 1; it < (int) s2.size(); it++) {
            int now = s2[it];
            int prv = s2[it - 1];
            if (d[prv] > d[now]) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        string res(n, '?');
        for (int i : s1) res[i] = '1';
        for (int i : s2) res[i] = '2';
        cout << res << "\n";
        return;
    }

    for (int x = 0; x + 1 < 10; x++) {
        int pp = -1;
        for (int i = 0; i < n; i++) {
            int y = d[i] - '0';
            if (y > x) {
                pp = i;
                break;
            }
        }
        if (pp == -1) continue;
        int qq = -1;
        for (int i = 0; i < n; i++) {
            int y = d[i] - '0';
            if (y == x && i < pp) {
                qq = i;
            }
        }
        if (qq == -1) continue;
        vector<int> s1, s2;
        s1.reserve(n);
        s2.reserve(n);
        for (int i = 0; i < n; i++) {
            int y = d[i] - '0';
            if (y < x || (y == x && i > qq)) {
                s1.push_back(i);
            } else {
                s2.push_back(i);
            }
        }
        ok = 1;
        for (int it = 1; it < (int) s1.size(); it++) {
            int now = s1[it];
            int prv = s1[it - 1];
            if (d[prv] > d[now]) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        for (int it = 1; it < (int) s2.size(); it++) {
            int now = s2[it];
            int prv = s2[it - 1];
            if (d[prv] > d[now]) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        string res(n, '?');
        for (int i : s1) res[i] = '1';
        for (int i : s2) res[i] = '2';
        cout << res << "\n";
        return;
    }

    cout << "-\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;

    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}