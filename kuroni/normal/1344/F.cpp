#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, k, u, ans[2 * N];
char c;
string s;
vector<pair<bitset<2 * N>, int>> bas;

struct matrix {
    int f[2][2];

    matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
        f[0][0] = a; f[0][1] = b;
        f[1][0] = c; f[1][1] = d;
    }

    matrix operator*(const matrix &oth) const {
        matrix ans(0, 0, 0, 0);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ans.f[i][j] ^= (f[i][k] & oth.f[k][j]);
                }
            }
        }
        return ans;
    }
} val[N];

int convert(char c) {
    switch (c) {
    case 'W': return 0;
    case 'R': return 1;
    case 'B': return 2;
    case 'Y': return 3;
    }
}

char convert(int u) {
    switch (u) {
    case 0: return '.';
    case 1: return 'R';
    case 2: return 'B';
    case 3: return 'Y';
    }
}

void elim(vector<pair<bitset<2 * N>, int>> &bas, bitset<2 * N> cur) {
    for (auto &[pr, _] : bas) {
        if (cur.test(pr._Find_first())) {
            cur ^= pr;
        }
    }
    if ((int)cur._Find_first() == 2 * n) {
        cout << "NO";
        exit(0);
    } else if (cur._Find_first() < 2 * N) {
        bas.push_back({cur, cur._Find_first()});
        for (int i = bas.size() - 1; i > 0; i--) {
            if (bas[i].second < bas[i - 1].second) {
                swap(bas[i], bas[i - 1]);
            } else {
                break;
            }
        }
    }
}

void solve(vector<pair<bitset<2 * N>, int>> &bas) {
    reverse(bas.begin(), bas.end());
    for (auto &[pr, u] : bas) {
        int cur = pr.test(2 * n);
        for (int i = u + 1; i < 2 * n; i++) {
            if (pr.test(i)) {
                cur ^= ans[i];
            }
        }
        ans[u] = cur;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        val[i] = matrix(1, 0, 0, 1);
    }
    while (m--) {
        cin >> s >> k;
        if (s == "mix") {
            bitset<2 * N> cur[2];
            while (k--) {
                cin >> u; --u;
                for (int i = 0; i < 2; i++) {
                    cur[i].set(2 * u, val[u].f[i][0]);
                    cur[i].set(2 * u + 1, val[u].f[i][1]);
                }
            }
            cin >> c;
            cur[0].set(2 * n, convert(c) & 1);
            cur[1].set(2 * n, convert(c) >> 1);
            elim(bas, cur[0]);
            elim(bas, cur[1]);
        } else {
            matrix tra;
            if (s == "RB") {
                tra = matrix(0, 1, 1, 0);
            } else if (s == "YB") {
                tra = matrix(1, 1, 0, 1);
            } else {
                tra = matrix(1, 0, 1, 1);
            }
            while (k--) {
                cin >> u; --u;
                val[u] = tra * val[u];
            }
        }
    }
    solve(bas);
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << convert((ans[2 * i + 1] << 1) ^ ans[2 * i]);
    }
}