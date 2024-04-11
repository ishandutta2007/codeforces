#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int d[maxN];
int p[maxN];
int n;
int x;
bool used[maxN];
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u  >> v;
        d[u]++;
        d[v]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int root = max_element(d + 1, d + n + 1) - d;
    if (d[root] != (n - 1)) {
        cout << "Alice\n";
        return;
    }
    else {
        if (x != root) {
            int pos = find(p + 1, p + n + 1, root) - p;
            if (p[root] != root) {
                if (p[root] == x) {
                    cout << "Bob\n";
                    return;
                }
                else {
                    swap(p[pos], p[root]);
                    x = root;
                }
            }
            else {
                vector<int> tt;
                for (int i = 1; i <= n; i++) {
                    if (p[i] != i) {
                        tt.emplace_back(i);
                    }
                }
                if (tt.empty() || (tt.size() == 2 && tt[0] != x && tt[1] != x)) {
                    cout << "Alice\n";
                    return;
                }
                else {
                    if (n == 3) {
                        cout << "Bob\n";
                        return;
                    }
                    int c1 = 1;
                    while (c1 == root || p[c1] == x) c1++;
                    int c2 = c1 + 1;
                    while (c2 == root || p[c2] == x) c2++;
                    assert(c1 <= n && c2 <= n);
                    swap(p[c1], p[c2]);
                    x = root;
                }
            }
        }
        assert(x == root);
        if (p[root] != root) {
            cout << "Bob\n";
        }
        else {
            bool ok = true;
            for (int i = 1; i <= n; i++) {
                used[i] = false;
                if (p[i] != i) ok = false;
            }
            if (ok) {
                cout << "Alice\n";
                return;
            }
            int inv = (n - 1) & 1;
            for (int i = 1; i <= n; i++) {
                if (i == root) continue;
                if (!used[i]) {
                    inv ^= 1;
                    int c = i;
                    while (!used[c]) {
                        used[c] =  true;
                        c = p[c];
                    }
                }
            }
            if (!inv) {
                cout << "Bob\n";
            }
            else {
                cout << "Alice\n";
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}