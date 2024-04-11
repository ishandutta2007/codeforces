#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int N = 1e7 + 5;

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

        vec<int> shift(n, -1);
        vec<int> dp(n);
        int l = -1;
        for (int i = 0; i < n; i++) {
            l = max(l, shift[i]);
            dp[i] = 1 + (l == -1 ? 0 : dp[l]);
            if (nxt_bad[i] != -1)
                shift[nxt_bad[i]] = max(shift[nxt_bad[i]], i);
        }
        cout << dp.back() << '\n';
    }
}