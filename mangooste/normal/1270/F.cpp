#pragma GCC optimize("O3,unroll-loops")

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

    string s;
    cin >> s;
    const int n = len(s);

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + (s[i] - '0');

    constexpr int B = 240;
    const int MAX = n * B + n + 1;

    vector<int> cnt(MAX);
    ll answer = 0;
    for (int k = 1; k < B; k++) {
        for (int i = 0; i <= n; i++)
            cnt[pref[i] * k - i + n] = 0;

        for (int i = 0; i <= n; i++)
            answer += cnt[pref[i] * k - i + n]++;
    }

    vector<int> positions;
    positions.reserve(pref.back());
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            positions.push_back(i);

    const int m = len(positions);
    for (int i = 0; i < m; i++)
        for (int j = i; j < m && (j - i + 1) * B <= n; j++) {
            int length = positions[j] - positions[i] + 1;
            int a = positions[i] - (i == 0 ? -1 : positions[i - 1]) - 1;
            int b = (j == m - 1 ? n : positions[j + 1]) - positions[j] - 1;
            int base = j - i + 1;
            if (a > b)
                swap(a, b);

            auto get_sum = [&](int max, int remainder) -> ll {
                if (max < remainder)
                    return 0;

                int k = (max - remainder) / base;
                return 1ll * (k + 1) * remainder + 1ll * base * k * (k + 1) / 2 + k + 1;
            };

            int start = max(0, B * base - length);
            int remainder = ((base - length) % base + base) % base;

            if (start <= a)
                answer += get_sum(a, remainder) - get_sum(start - 1, remainder);

            auto get_correct = [&](int max, int remainder) {
                if (max < remainder)
                    return 0;

                return (max - remainder) / base + 1;
            };

            if (start <= b && a != b)
                answer += 1ll * (get_correct(b, remainder) - get_correct(max(start - 1, a), remainder)) * (a + 1);

            if (remainder > a + b)
                continue;

            int new_remainder = (a + b - remainder) % base;
            if (start <= a + b)
                answer += get_sum(min(a - 1, a + b - start), new_remainder);
        }

    cout << answer << '\n';
}