#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;
    vec<ar<char, 5>> dp(n, {0, 0, 0, 0, 0});
    for (int i = 0; i < 5; i++)
        dp[0][i] = 1;
    vec<ar<int, 5>> par(n, {-1, -1, -1, -1, -1});
    for (int i = 1; i < n; i++) {
        auto relax = [&](int cur, int prev) {
            if (dp[i - 1][prev]) {
                dp[i][cur] = 1;
                par[i][cur] = prev;
            }
        };
        if (a[i - 1] < a[i]) {
            for (int cur = 0; cur < 5; cur++)
                for (int prev = 0; prev < cur; prev++)
                    relax(cur, prev);
        } else if (a[i - 1] > a[i]) {
            for (int cur = 0; cur < 5; cur++)
                for (int prev = cur + 1; prev < 5; prev++)
                    relax(cur, prev);
        } else {
            for (int cur = 0; cur < 5; cur++)
                for (int prev = 0; prev < 5; prev++)
                    if (cur != prev)
                        relax(cur, prev);
        }
    }

    for (int i = 0; i < 5; i++)
        if (dp.back()[i]) {
            vec<int> res;
            for (int j = n - 1; j >= 0; j--) {
                res.push_back(i);
                i = par[j][i];
            }
            reverse(all(res));
            for (auto x : res)
                cout << x + 1 << ' ';
            cout << '\n';
            return 0;
        }
    cout << "-1\n";
}