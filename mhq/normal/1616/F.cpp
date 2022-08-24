#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 3;

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int mult(int a, int b) {
    return (a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

struct Gauss{
    Gauss() {

    }
    vector<int> solve(vector<vector<int>>& a) {
        assert(!a.empty());
        int n = a.size();
        int m = a[0].size() - 1;
        vector<int> where(m, -1);
        for (int col = 0, row = 0; col < m && row < n; col++) {
            int ind = row;
            for (int i = row; i < n; i++) {
                if (a[i][col] != 0) {
                    ind = i;
                    break;
                }
            }
            if (a[ind][col] == 0) continue;
            for (int i = col; i <= m; i++) {
                swap(a[ind][i], a[row][i]);
            }
            where[col] = row;
            int coef = pw(a[row][col], mod - 2);
            for (int c = 0; c <= m; c++) a[row][c] = mult(a[row][c], coef);
            for (int i = 0; i < n; i++) {
                if (row == i) continue;
                if (!a[i][col]) continue;
                int val = a[i][col];
                for (int j = col; j <= m; j++) {
                    a[i][j] = sub(a[i][j], mult(val, a[row][j]));
                }
            }
            ++row;
        }
        vector<int> ans(m);
        for (int j = m - 1; j >= 0; j--) {
            if (where[j] != -1) {
                ans[j] = mult(a[where[j]][m], pw(a[where[j]][j], mod - 2));
                continue;
            }
        }
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                cur = sum(cur, mult(a[i][j], ans[j]));
            }
            if (cur != a[i][m]) {
                return vector<int>();
            }
        }
        return ans;
    }
}gs;
int n, m;
const int maxN = 322;
int id[maxN][maxN];
int clr[maxN];

void solve() {
    cin >> n >> m;
    memset(id, -1, sizeof id);
    memset(clr, -1, sizeof clr);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            id[i][j] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        assert(id[a][b] == id[b][a] && id[a][b] == -1);
        if (c == 3) c = 0;
        id[a][b] = id[b][a] = i;
        clr[i] = c;
    }

    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (id[i][j] == -1 || id[i][k] == -1 || id[j][k] == -1) continue;
                vector<int> A(m);

                A[id[i][j]] = A[id[j][k]] = A[id[i][k]] = 1;
                A.emplace_back(0);
                a.emplace_back(A);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (clr[i] != -1) {
            vector<int> A(m);
            A[i] = 1;
            A.emplace_back(clr[i]);
            a.emplace_back(A);
        }
    }

    if (a.empty()) {
        for (int i = 0; i < m; i++) {
            if (clr[i] <= 0) clr[i] = 3;
            cout << clr[i] << " ";
        }
        cout << '\n';
        return;
    }
    auto res = gs.solve(a);
    auto ans = res;
    if (ans.empty()) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < ans.size(); i++) {
        clr[i] = ans[i];
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (id[i][j] == -1 || id[i][k] == -1 || id[j][k] == -1) continue;
                int f = 0;
                f = sum(f, clr[id[i][j]]);
                f = sum(f, clr[id[i][k]]);
                f = sum(f, clr[id[j][k]]);
                assert(f == 0);
            }
        }
    }


    for (int i = 0; i < m; i++) {
        if (clr[i] == 0) clr[i] = 3;
        cout << clr[i] << " ";
    }
    cout << '\n';
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