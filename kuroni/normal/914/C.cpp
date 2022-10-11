#include <bits/stdc++.h>
using namespace std;

const int MX = 2005, MOD = 1E9 + 7;

int k, ans = 0, cur = 0, f[MX], c[MX][MX];
string s;
vector<int> ve;

void init() {
    for (int i = 0; i < MX; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    for (int i = 2; i < MX; i++) {
        f[i] = f[__builtin_popcount(i)] + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> s >> k;
    if (k == 0) {
        return cout << 1, 0;
    }
    for (int i = 1; i < MX; i++) {
        if (f[i] == k - 1) {
            ve.push_back(i);
        }
    }
    reverse(s.begin(), s.end());
    s += '0';
    for (int i = 0; i < s.size(); i++) {
        s[i] = '0' ^ '1' ^ s[i];
        if (s[i] == '1') {
            break;
        }
    }
    // cout << s << '\n';
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            for (int &v : ve) {
                if (v - cur >= 0 && v - cur <= i) {
                    (ans += c[i][v - cur]) %= MOD;
                }
            }
            cur++;
        }
    }
    cout << (ans + (MOD - (k == 1))) % MOD;
}