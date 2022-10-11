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

    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<vector<int>> pref(n + 1, vector<int>(k + 1));
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];
        if (s[i] != '?')
            pref[i + 1][s[i] - 'a']++;
        else
            pref[i + 1][k]++;
    }

    auto can = [&](int ln) {
        vector<vector<int>> suf(n + 1, vector<int>(k, n + 1));
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            for (int j = 0; j < k; j++)
                if (n - i >= ln && pref[i + ln][j] - pref[i][j] + pref[i + ln][k] - pref[i][k] == ln)
                    suf[i][j] = i + ln;
        }

        const int MASK = (1 << k);
        vector<int> dp(MASK, n + 1);
        dp[0] = 0;
        for (int mask = 0; mask < MASK; mask++)
            for (int who = 0; who < k; who++)
                if ((mask >> who) & 1) {
                    int submask = mask ^ (1 << who);
                    if (dp[submask] > n)
                        continue;

                    dp[mask] = min(dp[mask], suf[dp[submask]][who]);
                }

        return dp[MASK - 1] <= n;
    };

    int l = 0, r = n / k + 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (can(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}