#include <bits/stdc++.h>

using namespace std;

template<typename value_t, value_t mod, typename big_t>
struct Modular {
    using mval = Modular<value_t, mod, big_t>;

    value_t val;

    template<typename T>
    static T normalize(T x, value_t m = mod) {
        if (x < -m || x >= 2 * m)
            x %= m;
        if (x >= m)
            x -= m;
        if (x < 0)
            x += m;
        return x;
    }

    template<typename T>
    static inline mval power(mval base, T degree) {
        degree = normalize(degree, mod - 1);
        mval res = 1;
        for (; degree > 0; degree >>= 1) {
            if (degree & 1)
                res *= base;
            base *= base;
        }
        return res;
    }

    inline mval rev() const {
        return power(*this, -1);
    }

    Modular() : val(0) {}
    template<typename T>
    Modular(T x) : val(normalize(x)) {}

    mval operator * (mval x) const {
        return mval(big_t(val) * big_t(x.val));
    }
    mval operator + (mval x) const {
        return mval(val + x.val);
    }
    mval operator - (mval x) const {
        return mval(val - x.val);
    }
    mval operator / (mval x) const {
        return *this * x.rev();
    }

    mval& operator *= (mval x) {
        return *this = *this * x;
    }
    mval& operator += (mval x) {
        return *this = *this + x;
    }
    mval& operator -= (mval x) {
        return *this = *this - x;
    }
    mval& operator /= (mval x) {
        return *this = *this / x;
    }

    mval& operator ++ () {
        val++;
        if (val >= mod)
            val -= mod;
        return *this;
    }
    mval& operator -- () {
        val--;
        if (val < 0)
            val += mod;
        return *this;
    }
    mval operator ++ (int) {
        val++;
        if (val >= mod)
            val -= mod;
        return *this;
    }
    mval operator -- (int) {
        val--;
        if (val < 0)
            val += mod;
        return *this;
    }

    friend istream& operator >> (istream &in, mval &val) {
        value_t x;
        in >> x;
        val = mval(x);
        return in;
    }
    friend ostream& operator << (ostream &out, mval val) {
        return out << val.val;
    }
};

constexpr int MOD = int(1e9) + 7;
// constexpr int MOD = 998244353;
using mint = Modular<int, MOD, long long>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    if (n == 1 && m == 1) {
        cout << "1\n";
        return 0;
    }

    vector<vector<int>> cnt_down(n + 1, vector<int>(m));
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            cnt_down[i][j] = cnt_down[i + 1][j] + (a[i][j] == 'R');
    vector<vector<int>> cnt_right(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--)
            cnt_right[i][j] = cnt_right[i][j + 1] + (a[i][j] == 'R');

    vector<vector<mint>> sum_right(n, vector<mint>(m + 1)), sum_down(n + 1, vector<mint>(m));
    sum_right[0][0]++;
    sum_right[0][1]--;
    sum_down[0][0]++;
    sum_down[1][0]--;
    for (int i = 0; i < n; i++) {
        if (i)
            for (int j = 0; j < m; j++)
                sum_down[i][j] += sum_down[i - 1][j];
        for (int j = 0; j < m; j++) {
            int cnt = cnt_right[i][j + 1];
            sum_right[i][j + 1] += sum_down[i][j];
            sum_right[i][m - cnt] -= sum_down[i][j];
        }
        for (int j = 1; j < m; j++)
            sum_right[i][j] += sum_right[i][j - 1];
        for (int j = 0; j < m; j++) {
            int cnt = cnt_down[i + 1][j];
            sum_down[i + 1][j] += sum_right[i][j];
            sum_down[n - cnt][j] -= sum_right[i][j];
        }
    }
    cout << sum_right[n - 1][m - 1] + sum_down[n - 1][m - 1] << '\n';
}