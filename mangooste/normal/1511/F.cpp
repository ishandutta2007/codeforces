// #pragma GCC optimize("O3,Ofast,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

constexpr int MOD = 998'244'353;

struct Matrix {
    vector<vector<int>> mat;

    Matrix(int n, int m) : mat(n, vector<int>(m)) {}

    inline Matrix operator*(const Matrix &matrix) const {
        assert(len(mat[0]) == len(matrix.mat));
        Matrix result(len(mat), len(matrix.mat[0]));
        for (int i = 0; i < len(result.mat); i++)
            for (int j = 0; j < len(result.mat[0]); j++) {
                ll sum = 0;
                for (int k = 0; k < len(matrix.mat); k++)
                    sum += 1ll * mat[i][k] * matrix.mat[k][j] % MOD;

                result.mat[i][j] = sum % MOD;
            }

        return result;
    }
};

Matrix power(Matrix &base, int deg) {
    assert(deg > 0);
    auto prod = base;
    for (deg--; deg; deg >>= 1, base = base * base)
        if (deg & 1)
            prod = prod * base;

    return prod;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;

    map<string, int> mp;
    int current_id = 0;
    vector<string> str;
    for (auto s : a)
        for (int i = 1; i <= len(s); i++) {
            string t = s.substr(i);
            if (mp.find(t) == mp.end()) {
                mp[t] = current_id++;
                str.push_back(t);
            }
        }

    const int LAYERS = 5;
    const int EACH = current_id;
    const int SIZE = LAYERS * EACH;
    const int SHIFT = (LAYERS - 1) * EACH;
    const int EMPTY = mp[""];

    Matrix dp(SIZE, SIZE);
    for (int layer = 0; layer < LAYERS - 1; layer++)
        for (int i = 0; i < EACH; i++)
            dp.mat[layer * EACH + i + EACH][layer * EACH + i]++;

    for (int i = 0; i < EACH; i++)
        if (i != EMPTY) {
            for (auto s : a)
                if (len(s) <= len(str[i])) {
                    if (str[i].substr(0, len(s)) != s)
                        continue;

                    int layer = LAYERS - len(s);
                    int new_id = mp[str[i].substr(len(s))];
                    dp.mat[layer * EACH + i][SHIFT + new_id]++;
                } else {
                    if (s.substr(0, len(str[i])) != str[i])
                        continue;

                    int layer = LAYERS - len(str[i]);
                    int new_id = mp[s.substr(len(str[i]))];
                    dp.mat[layer * EACH + i][SHIFT + new_id]++;
                }
        }

    for (int i = 0; i < SIZE; i++)
        dp.mat[i][SHIFT + EMPTY] *= 2;

    sort(all(a), [](const string &a, const string &b) {
        return len(a) < len(b);
    });
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            if (a[j].substr(0, len(a[i])) != a[i])
                continue;

            int layer = LAYERS - len(a[i]);
            int new_id = mp[a[j].substr(len(a[i]))];
            dp.mat[layer * EACH + EMPTY][SHIFT + new_id]++;
        }

    dp = power(dp, m);
    cout << dp.mat[SHIFT + EMPTY][SHIFT + mp[""]] << '\n';
}