#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int N = 1e7 + 5;

inline void setmin(int &a, int b) {
    if (a > b)
        a = b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    vec<int> p(N);
    iota(all(p), 0);
    for (int i = 2; i < N; i++)
        if (p[i] == i)
            for (int j = i; j < N; j += i)
                if (p[j] == j)
                    p[j] = i;

    auto get_mask = [&](int x) {
        int mask = 1;
        while (x != 1) {
            int prime = p[x];
            int cnt = 0;
            while (x % prime == 0) {
                x /= prime;
                cnt++;
            }
            if (cnt & 1)
                mask *= prime;
        }
        return mask;
    };

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vec<int> a(n);
        for (auto &x : a) {
            cin >> x;
            x = get_mask(x);
        }

        map<int, int> last;
        vec<int> nxt_bad(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (last.find(a[i]) != last.end())
                nxt_bad[i] = last[a[i]];
            last[a[i]] = i;
        }

        vec<vec<int>> dp(n, vec<int>(k + 1, n));
        vec<vec<int>> sub(k + 1, vec<int>(n));
        vec<int> cnt(k + 1);
        vec<int> id(k + 1);

        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(a[i]) != mp.end()) {
                int prev = mp[a[i]];
                for (int j = 0; j <= k; j++)
                    if (id[j] <= prev) {
                        sub[j][prev + 1]++;
                        cnt[j]++;
                        while (cnt[j] > j) {
                            id[j]++;
                            cnt[j] -= sub[j][id[j]];
                        }
                    }
            }
            mp[a[i]] = i;

            for (int j = 0; j <= k; j++) {
                for (int k = 0; k <= j; k++)
                    setmin(dp[i][j], (id[k] ? dp[id[k] - 1][j - k] : 0) + 1);
                if (j)
                    setmin(dp[i][j], dp[i][j - 1]);
            }

            // cout << i << ":" << endl;
            // cout << "id: ";
            // for (auto x : id)
            //     cout << x << ' ';
            // cout << endl;
            // cout << "dp: ";
            // for (auto x : dp[i])
            //     cout << x << ' ';
            // cout << endl;
            // cout << endl;
        }
        cout << dp.back().back() << '\n';
    }
}