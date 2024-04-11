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

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x = abs(x);
    }

    int answer = 0;
    while (!a.empty()) {
        const int MAX = *max_element(all(a));
        const int CNT = count(all(a), MAX);

        vector<int> new_a;
        new_a.reserve(len(a) - CNT);
        vector<int> positions;
        positions.reserve(CNT);

        for (int i = 0; i < len(a); i++)
            if (a[i] == MAX)
                positions.push_back(i);
            else
                new_a.push_back(a[i]);

        vector<int> dp(CNT + 1, n * n);
        dp[0] = 0;

        for (int i = 0; i < CNT; i++)
            for (int j = i + 1; j >= 0; j--) {
                if (j != i + 1)
                    dp[j] += (positions[i] - i) + j;

                if (j > 0)
                    dp[j] = min(dp[j], dp[j - 1] + (len(a) - positions[i] - 1) - (CNT - i - 1));
            }

        answer += *min_element(all(dp));
        a = new_a;
    }

    cout << answer << '\n';
}