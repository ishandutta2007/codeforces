#include <bits/stdc++.h>
using namespace std;

const int A = 52, INF = 1E9;

int n;
vector<vector<vector<int>>> pos;
vector<vector<vector<string>>> dp;

string maxi(const string &x, const string &y) {
    return x.size() > y.size() ? x : y;
}

int code(char c) {
    if (isupper(c)) {
        return c - 'A';
    } else {
        return c - 'a' + 26;
    }
}

char to_char(int c) {
    if (c < 26) {
        return c + 'A';
    } else {
        return c - 26 + 'a';
    }
}

string calc(int msk, int ch, int bit) {
    if (dp[msk][ch][bit + 1] != "-1") {
        return dp[msk][ch][bit + 1];
    }
    string &ans = dp[msk][ch][bit + 1];
    if (bit >= 0) {
        ans = calc(msk, ch, bit - 1);
        if (msk >> bit & 1) {
            ans = maxi(ans, calc(msk ^ (1 << bit), ch, bit - 1));
        }
        return ans;
    } else {
        // cout << ch << " " << msk << '\n';
        ans = "";
        for (int i = 0; i < n; i++) {
            if (pos[i][ch][msk >> i & 1] == -1) {
                return ans;
            }
        }
        for (int pr = 0; pr < A; pr++) {
            int pm = 0;
            for (int i = 0; i < n; i++) {
                if (pos[i][pr][1] != -1 && pos[i][pr][1] < pos[i][ch][msk >> i & 1]) {
                    pm ^= (1 << i);
                } else if (pos[i][pr][0] == -1 || pos[i][pr][0] >= pos[i][ch][msk >> i & 1]) {
                    pm = -1;
                    break;
                }
            }
            if (pm != -1) {
                ans = maxi(ans, calc(pm, pr, n - 1));
            }
        }
        // cout << ch << " " << msk << ": " << ans + 1 << '\n';
        return ans += to_char(ch);
    }
}

void solve() {
    cin >> n;
    pos = vector<vector<vector<int>>>(n, vector<vector<int>>(A, vector<int>(2, -1)));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            int u = code(s[j]);
            pos[i][u][pos[i][u][0] >= 0] = j;
        }
    }
    dp = vector<vector<vector<string>>>(1 << n, vector<vector<string>>(A, vector<string>(n + 1, "-1")));
    string ans = "";
    for (int i = 0; i < A; i++) {
        ans = maxi(ans, calc((1 << n) - 1, i, n - 1));
    }
    cout << ans.size() << '\n' << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}