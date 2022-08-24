#include <bits/stdc++.h>
using namespace std;
const int maxN = 5005;
int n, k, v;
int a[maxN];
bool dp[maxN][maxN];
bool used[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k >> v;
    memset(dp, 0, sizeof dp);
    dp[0][0] = true;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < v) {
        cout << "NO";
        return 0;
    }
    //cout << "HERE" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] |= dp[i - 1][(((j - a[i]) % k + k) % k)];
        }
    }
    if (dp[n][v % k] == false) {
        cout << "NO";
        return 0;
    }
    int cur = v % k;
    for (int i = n; i >= 1; i--) {
        if (dp[i - 1][cur] == true) continue;
        cur = ((cur - (a[i] % k)) + k) % k;
        used[i] = true;
    }
    cout << "YES" << '\n';
    if (v % k == 0) {
        for (int i = 2; i <= n; i++) {
            cout << (int)1e9 << " " << i << " " << 1 << '\n';
        }
        if (v > 0) cout << (v / k) << " " << 1 << " " << 2;
        return 0;
    }
    vector < int > f, s;
    for (int i = 1; i <= n; i++) {
        if (used[i]) f.push_back(i);
        else s.push_back(i);
    }
    int inds = -1;
    if (s.size() != 0) {
        inds = s[0];
        for (int i = 1; i < s.size(); i++) {
            cout << (int)1e9 << " " << s[i] << " " << inds << '\n';
        }
    }
    int curv = a[f[0]];
    int indf = f[0];
    for (int i = 1; i < f.size(); i++) {
        cout << (int)1e9 << " " << f[i] << " " << indf << '\n';
        curv += a[f[i]];
    }
    if (curv > v) {
        if (s.size() > 0) {
            cout << (curv - v) / k << " " << indf << " " << inds << '\n';
        }
        else {
            cout << (curv - v) / k << " " << indf << " " << f[1] << '\n';
        }
    }
    else if (curv < v) {
        cout << (v - curv) / k << " " << inds << " " << indf << '\n';
    }
    return 0;
}