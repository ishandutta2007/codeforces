#include <bits/stdc++.h>
using namespace std;;
int f[1005];
const int mod = (int)1e9 + 7;
string s;
int k;
int c[1005][1005];
int solve(string s, int x) {
    //int res = c[s.size() - 1][x];
    //int cur = 1;
    int res = 0;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (cur > x) break;
        if (s[i] == '0') continue;
        res = (res + c[s.size() - i - 1][x - cur]) % mod;
        cur++;
    }
    if (cur == x) res++;
    if (x == 1) res--;
    return res;
}
void calc() {
    c[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    calc();
    cin >> s >> k;
    f[1] = 0;
    for (int i = 2; i <= 1000; i++) {
        int t = i;
        int cnt = 0;
        while (t > 0) {
            cnt += (t % 2);
            t /= 2;
        }
        f[i] = f[cnt] + 1;
    }
    if (k == 0) {
        cout << 1;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (f[i] == k - 1) {
            //cout << i << '\n';
            ans = (ans + solve(s, i)) % mod;
        }
    }
    cout << ans;
    return 0;
}