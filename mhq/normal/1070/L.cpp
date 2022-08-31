#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
int n, m;
const int maxN = 2005;
vector < int > g[maxN];
int deg[maxN];
struct myBitset{
    vector < ull > v;
    myBitset(int n) {
        v.resize(n / 64 + 1);
    }

    inline bool operator[](int q) const {
        int pos = q >> 6, val = q & 63;
        return (v[pos] >> val) & 1;
    }

    inline void set(int q) {
        int pos = q >> 6;
        int val = q & 63;
        v[pos] ^= (ull)1 << val;
    }

    inline void do_xor(myBitset& other) {
        for (int i = 0; i < v.size(); i++) {
            v[i] ^= other.v[i];
        }
    }
};
void solve() {
    string tr;
    getline(cin, tr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        deg[i] = 0;
    }
    vector < myBitset > all(n, myBitset(n + 1));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        all[a].set(b);
        all[b].set(a);
        deg[a]++;
        deg[b]++;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (deg[i] % 2 == 1) {
            ok = false;
            all[i].set(i);
            all[i].set(n);
        }
    }
    if (ok) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) cout << 1 << " ";
        cout << '\n';
        return ;
    }
    vector < bool > used(n, false);
    vector < int > take(n, -1);
    for (int col = 0; col < n; col++) {
        int where = -1;
        for (int row = 0; row < n; row++) {
            if (used[row]) continue;
            if (all[row][col]) {
                where = row;
                break;
            }
        }
        if (where == -1) {
            continue;
        }
        take[col] = where;
        used[where] = true;
        for (int row = 0; row < n; row++) {
            if (row == where) continue;
            if (all[row][col]) {
                all[row].do_xor(all[where]);
            }
        }
    }
    cout << 2 << '\n';
    for (int i = 0; i < n; i++) {
        if (take[i] == -1) {
            cout << 1 << " ";
        }
        else {
            cout << all[take[i]][n] + 1 << " ";
        }
    }
    cout << '\n';
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}