#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector deletable(n, vector(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            deletable[i][j] = c == '1';
        }
    }
    vector ans(n, vector(n, '1'));
    vector shift(n - k + 1, vector(n - k + 1, 0));
    for (int i = 0; i < n - k + 1; ++i) {
        for (int j = 0; j < n - k + 1; ++j) {
            int cur = max(i ? shift[i - 1][j] : 0, j ? shift[i][j - 1] : 0);
            while (cur + i < n && cur + j < n && !deletable[cur + i][cur + j]) cur++;
            if (cur + i == n || cur + j == n) answer("NO");
            shift[i][j] = cur;
            ans[i + cur][j + cur] = '0';
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << ans[i][j];
        cout << '\n';
    }
}