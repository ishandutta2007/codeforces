#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int mod = 998244353;

struct mint {
    int val;

    explicit mint() : val(0) {}
    explicit mint(int val) : val(val) {}

    inline mint operator + (mint m) const {
        int sum = val + m.val;
        if (sum >= mod)
            sum -= mod;
        return mint(sum - mod * (sum >= mod));
    }

    inline mint operator - (mint m) const {
        int sub = val - m.val;
        return mint(sub + mod * (sub < 0));
    }

    inline mint operator * (mint m) const {
        return mint(1ll * val * m.val % mod);
    }

    friend ostream& operator << (ostream &out, mint m) {
        return out << m.val;
    }
};

inline mint power(mint a, int b) {
    mint prod(1);
    for (; b; b /= 2) {
        if (b & 1)
            prod = prod * a;
        a = a * a;
    }
    return prod;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k, len;
    cin >> n >> k >> len;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
        if (x != -1)
            x--;
    }

    vec<vec<int>> right(n + 1, vec<int>(k));
    for (int i = n - 1; i >= 0; i--)
        if (a[i] == -1)
            for (int j = 0; j < k; j++)
                right[i][j] = right[i + 1][j] + 1;
        else
            right[i][a[i]] = right[i + 1][a[i]] + 1;

    vec<vec<mint>> sub(n + 1, vec<mint>(k));
    vec<vec<mint>> dp(n, vec<mint>(k));
    vec<mint> to_add(k);

    auto add = [&](int i, int j, mint val) {
        int to = i + min(right[i][j], len - 1);
        if (to == i)
            return;
        to_add[j] = to_add[j] + val;
        sub[to][j] = sub[to][j] + val;
    };

    if (a[0] == -1)
        fill(all(dp[0]), mint(1));
    else
        dp[0][a[0]] = mint(1);

    mint cur_sum = accumulate(all(dp[0]), mint(0));
    for (int j = 0; j < k; j++)
        add(0, j, dp[0][j]);

    for (int i = 1; i < n; i++) {
        mint prev_sum = accumulate(all(dp[i - 1]), mint(0));
        for (int j = 0; j < k; j++)
            if (a[i] == -1 || j == a[i])
                add(i, j, prev_sum - dp[i - 1][j]);
        for (int j = 0; j < k; j++)
            to_add[j] = to_add[j] - sub[i][j];
        dp[i] = to_add;
    }

    if (n == 1)
        cout << "0\n";
    else
        cout << accumulate(all(dp.back()), mint(0)) << '\n';
}