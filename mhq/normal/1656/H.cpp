#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1005;
#ifdef DEBUG
#define __int128_t long long
#endif
typedef __int128_t i128;
i128 gcd(i128 a, i128 b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
i128 t[2][maxN][4 * maxN];
i128 a[maxN], b[maxN];
i128 val[2][maxN][maxN];
void build(int id, int ind, int v, int tl, int tr) {
    if (tl == tr) {
        t[id][ind][v] = val[id][ind][tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(id, ind, 2 * v, tl, tm);
    build(id, ind, 2 * v + 1, tm + 1, tr);
    t[id][ind][v] = gcd(t[id][ind][2 * v], t[id][ind][2 * v + 1]);
}
void ch(int id, int ind, int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[id][ind][v] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) ch(id, ind, 2 * v, tl, tm, pos);
    else ch(id, ind, 2 * v + 1, tm + 1, tr, pos);
    t[id][ind][v] = gcd(t[id][ind][2 * v], t[id][ind][2 * v + 1]);
}

i128 geti128() {
    string s;
    cin >> s;
    i128 t = 0;
    for (char& c : s) {
        t = 10 * t + (c - '0');
    }
    return t;
}
void printi128(i128 x) {
    string s;
    while (x > 0) {
        s += (char)(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << " ";
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i] = geti128();
    }
    for (int i = 1; i <= m; i++) {
        b[i] = geti128();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            i128 gc = gcd(a[i], b[j]);
            val[0][i][j] = a[i] / gc;
            val[1][j][i] = b[j] / gc;
        }
    }
    for (int i = 1; i <= n; i++) {
        build(0, i, 1, 1, m);
    }
    for (int i = 1; i <= m; i++) {
        build(1, i, 1, 1, n);
    }
    vector<int> c1, c2;
    for (int i = 1; i <= n; i++) c1.emplace_back(i);
    for (int i = 1; i <= m; i++) c2.emplace_back(i);
    while (!c1.empty() && !c2.empty()) {
        int a = -1;
        for (int x : c1) {
            if (t[0][x][1] > 1) {
                a = x;
                break;
            }
        }
        if (a != -1) {
            c1.erase(find(c1.begin(), c1.end(), a));
            for (int j : c2) {
                ch(1, j, 1, 1, n, a);
            }
        }
        else {
            int b = -1;
            for (int x : c2) {
                if (t[1][x][1] > 1) {
                    b = x;
                    break;
                }
            }
            if (b != -1) {
                c2.erase(find(c2.begin(), c2.end(), b));
                for (int j : c1) {
                    ch(0, j, 1, 1, m, b);
                }
            }
            else {
                cout << "YES\n";
                cout << c1.size() << " ";
                cout << c2.size() << '\n';
                for (int u : c1) {
                    printi128(::a[u]);
                }
                cout << '\n';
                for (int u : c2) {
                    printi128(::b[u]);
                }
                cout << '\n';
                return;
            }
        }
    }
    cout << "NO\n";
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