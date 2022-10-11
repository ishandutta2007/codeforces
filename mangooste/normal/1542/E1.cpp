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



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, mod;
    cin >> n >> mod;
    if (mod == 1 || n == 1) {
        cout << "0\n";
        return 0;
    }

    auto add = [&](int a, int b) {
        a += b;
        return a - mod * (a >= mod);
    };
    auto mult = [&](int a, int b) {
        return 1ll * a * b % mod;
    };
    auto sub = [&](int a, int b) {
        a -= b;
        return a + mod * (a < 0);
    };

    vector<vector<int>> dp(n);
    dp[1] = {1};
    for (int ln = 2; ln < n; ln++) {
        dp[ln].resize(ln * (ln - 1) / 2 + 1);
        int sum = 0;
        for (int invs = 0; invs < len(dp[ln]); invs++) {
            if (invs < len(dp[ln - 1]))
                sum = add(sum, dp[ln - 1][invs]);

            if (invs - ln >= 0)
                sum = sub(sum, dp[ln - 1][invs - ln]);

            dp[ln][invs] = sum;
        }
    }

    vector<vector<int>> choose(n + 1);
    for (int i = 0; i <= n; i++) {
        choose[i].resize(i + 1, 1);
        for (int j = 1; j < i; j++)
            choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
    }

    vector<int> factorial(n + 1, 1);
    for (int i = 1; i <= n; i++)
        factorial[i] = mult(factorial[i - 1], i);

    int answer = 0;
    for (int pref = 0; pref < n - 1; pref++) {
        int suf = n - pref - 1;
        vector<int> coeff(suf + 1);
        for (int delta = 1; delta < suf + 1; delta++)
            coeff[delta] = sub((suf + 1) % mod, delta % mod);

        for (int i = 1; i < len(coeff); i++)
            coeff[i] = add(coeff[i - 1], coeff[i]);

        int current = 0;
        for (int delta = 1; delta < len(dp[suf]); delta++) {
            int sum = 0;
            for (int invs = 0; invs + delta < len(dp[suf]); invs++)
                sum = add(sum, mult(dp[suf][invs], dp[suf][invs + delta]));

            current = add(current, mult(sum, coeff[min(delta - 1, len(coeff) - 1)]));
        }
        answer = add(answer, mult(current, mult(choose[n][pref], factorial[pref])));
    }
    cout << answer << '\n';
}