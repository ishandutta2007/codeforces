#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 5005;

int c[N][N];

void init() {
    for (int i = 0; i < N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    if (k == 0) {
        return cout << "1\n", 0;
    }
    string s; cin >> s;
    if (count_if(s.begin(), s.end(), [](const char c) { return c == '1'; }) < k) {
        return cout << "1\n", 0;
    }
    init();
    vector<int> ve;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cur++;
        } else {
            ve.push_back(cur);
            cur = 0;
        }
    }
    ve.push_back(cur);
    long long ans = 0;
    for (int i = 0, sum = 0; i < ve.size(); i++) {
        sum += ve[i];
        if (i >= k) {
            (ans += c[sum + k][k]) %= MOD;
            if (i > k) {
                (ans -= c[sum - ve[i] + k - 1][k - 1]) %= MOD;
            }
            sum -= ve[i - k];
        }
    }
    cout << (ans + MOD) % MOD;
}