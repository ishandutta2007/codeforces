#include <bits/stdc++.h>
#define fi first
#define se second
#define __lg(x) (x == 0 ? -1 : __lg(x))
using namespace std;

const int MOD = 1E9 + 7;

int n, u, cnt[3];
long long l, r, m, pre = 2;
vector<pair<long long, int>> eve;

struct matrix {
    long long f[3][3];

    matrix(bool _id = false) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                f[i][j] = 0;
            }
            if (_id) {
                f[i][i] = 1;
            }
        }
    }

    matrix operator*(const matrix &oth) const {
        matrix ans = matrix();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    (ans.f[i][j] += f[i][k] * oth.f[k][j]) %= MOD;
                }
            }
        }
        return ans;
    }

    matrix operator^(long long p) const {
        matrix ans = matrix(true);
        for (int i = __lg(p); i >= 0; i--) {
            ans = ans * ans;
            if (p >> i & 1) {
                ans = ans * (*this);
            }
        }
        return ans;
    }
} bas, cur, ans(true);

void init() {
    for (int i = 0; i < 3; i++) {
        for (int j = max(0, i - 1); j <= min(2, i + 1); j++) {
            bas.f[i][j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> u >> l >> r;
        eve.push_back({l, u});
        eve.push_back({r + 1, -u});
    }
    eve.push_back({m + 1, 1});
    sort(eve.begin(), eve.end());
    for (pair<long long, int> &v : eve) {
        cur = bas;
        for (int i = 0; i < 3; i++) {
            if (cnt[i] != 0) {
                for (int j = 0; j < 3; j++) {
                    cur.f[j][i] = 0;
                }
            }
        }
        ans = ans * (cur ^ (v.first - pre));
        pre = v.first;
        cnt[abs(v.second) - 1] += v.second / abs(v.second);
    }
    cout << ans.f[1][1];
}