#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 100005, P = 105;
const long long INF = 1E18 + 7;

int n, m, p, h, t, d[N];
long long a[M], dp[M][P];

struct line {
    int a;
    long long b;

    line(int _a, long long _b) : a(_a), b(_b) {}

    double intersect(const line &oth) const {
        return 1.0 * (oth.b - b) / (a - oth.a);
    }

    long long at(long long x) {
        return a * x + b;
    }
};
deque<line> opt[P];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> p;
    for (int i = 2; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> h >> t;
        a[i] = t - d[h];
    }
    sort(a + 1, a + m + 1);
    opt[0].push_back(line(0, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = p; j >= 1; j--) {
            if (opt[j - 1].empty()) {
                dp[i][j] = INF;
            } else {
                int sz = opt[j - 1].size();
                while (sz >= 2 && opt[j - 1][0].at(a[i]) >= opt[j - 1][1].at(a[i])) {
                    opt[j - 1].pop_front();
                    sz--;
                }
                dp[i][j] = opt[j - 1][0].at(a[i]) + i * a[i];
            }
            int sz = opt[j].size();
            line cur = line(-i, dp[i][j]);
            while (sz >= 2 && opt[j][sz - 2].intersect(cur) < opt[j][sz - 2].intersect(opt[j][sz - 1])) {
                opt[j].pop_back();
                sz--;
            }
            opt[j].push_back(cur);
        }
        // cout << i << " " << j << ": " << dp[i][j] << '\n';
    }
    cout << *min_element(dp[m] + 1, dp[m] + p + 1) - accumulate(a + 1, a + m + 1, 0LL);
}