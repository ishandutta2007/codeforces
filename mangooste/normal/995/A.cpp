#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vec<vec<int>> a(4, vec<int>(n));
    for (auto &vec : a)
        for (auto &x : vec)
            cin >> x, x--;

    vec<char> ok(k);
    int bad = k;
    vec<ar<int, 3>> ops;

    auto relax = [&]() {
        for (int i = 0; i < n; i++) {
            if (a[1][i] == a[0][i] && a[1][i] != -1) {
                ok[a[1][i]] = 1;
                bad--;
                ops.push_back({a[1][i], 0, i});
                a[1][i] = -1;
            }

            if (a[2][i] == a[3][i] && a[2][i] != -1) {
                ok[a[2][i]] = 1;
                bad--;
                ops.push_back({a[2][i], 3, i});
                a[2][i] = -1;
            }
        }
    };

    vec<vec<pair<int, int>>> prev(4, vec<pair<int, int>>(n));
    for (int i = 0; i < n; i++) {
        prev[1][i] = (i == n - 1 ? pair<int, int>{2, i} : pair<int, int>{1, i + 1});
        prev[2][i] = (i == 0 ? pair<int, int>{1, i} : pair<int, int>{2, i - 1});
    }

    auto move = [&]() {
        dbg("before");
        dbg(a);

        pair<int, int> free{-1, -1};
        for (int i = 1; i <= 2 && free.first == -1; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == -1) {
                    free = {i, j};
                    break;
                }

        if (free.first == -1) {
            cout << "-1\n";
            exit(0);
        }

        pair<int, int> cur = prev[free.first][free.second];
        pair<int, int> before = free;

        while (cur != free) {
            if (a[cur.first][cur.second] != -1) {
                ops.push_back({a[cur.first][cur.second], before.first, before.second});
                a[before.first][before.second] = a[cur.first][cur.second];
                a[cur.first][cur.second] = -1;
            }

            before = cur;
            cur = prev[cur.first][cur.second];
        }

        dbg("after");
        dbg(a);
        dbg("-----");
    };

    relax();
    while (bad) {
        move();
        relax();
    }

    cout << len(ops) << '\n';
    for (auto [i, x, y] : ops)
        cout << i + 1 << ' ' << x + 1 << ' ' << y + 1 << '\n';
}