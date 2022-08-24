#include <bits/stdc++.h>
using namespace std;
const int maxN = 205;
const int mod = (int)1e9 + 7;
int dp[maxN][maxN][maxN][2], to[maxN][2];
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int n;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        string t = "";
        for (int j = 0; j < i; j++) t += s[j];
        string nt = t + "(";
        for (int len = nt.size(); len >= 0; len--) {
            if (nt.substr(nt.size() - len) == s.substr(0, len)) {
                to[i][1] = len;
                break;
            }
        }
        nt = t + ")";
        for (int len = nt.size(); len >= 0; len--) {
            if (nt.substr(nt.size() - len) == s.substr(0, len)) {
                to[i][0] = len;
                break;
            }
        }
    }
    /*for (int state = 0; state < s.size(); state++) {
        for (int x = 0; x < 2; x++) {
            cout << to[state][x] << " ";
        }
        cout << endl;
    }*/
    to[s.size()][0] = 0;
    to[s.size()][1] = 0;
    dp[0][0][0][0] = 1;
    for (int i = 0; i + 1 <= 2 * n; i++) {
        for (int bal = 0; bal <= n; bal++) {
            for (int state = 0; state <= s.size(); state++) {
                for (int ok = 0; ok < 2; ok++) {
                    for (int step = -1; step <= 1; step += 2) {
                        int o = (step + 1) / 2;
                        if (bal + step < 0) continue;
                        if (ok == 1) {
                            dp[i + 1][bal + step][to[state][o]][ok] = sum(dp[i + 1][bal + step][to[state][o]][ok], dp[i][bal][state][ok]);
                        }
                        else {
                            int nok = (to[state][o] == s.size());
                            dp[i + 1][bal + step][to[state][o]][nok] = sum(dp[i + 1][bal + step][to[state][o]][nok], dp[i][bal][state][ok]);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int state = 0; state <= s.size(); state++) {
        ans = sum(dp[2 * n][0][state][1], ans);
    }
    cout << ans;
    return 0;
}