#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int A = 101;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> a(n);
    vec<int> freq(A);
    for (auto &x : a) {
        cin >> x;
        freq[x]++;
    }

    if (len(set<int>(all(a))) <= 2) {
        cout << n << '\n';
        return 0;
    }

    int sum = accumulate(all(a), 0);
    a.insert(a.begin(), 0);
    int ans = 0;
    for (int w = 1; w < A; w++)
        if (freq[w]) {
            vec<vec<char>> dp(freq[w] + 1, vec<char>(n * A + 1));
            dp[0][0] = 1;
            for (int i = 1; i <= n; i++)
                if (a[i] != w)
                    for (int j = freq[w]; j; j--)
                        for (int k = sum; k >= a[i]; k--)
                            if (dp[j - 1][k - a[i]])
                                dp[j][k] = 1;

            for (int i = 1; i <= freq[w]; i++) {
                if (dp[i][i * w])
                    break;
                ans = max(ans, i);
            }
        }
    cout << ans << '\n';
}