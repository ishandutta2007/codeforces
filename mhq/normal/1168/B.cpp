#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
char tp[maxN];
int nxt[maxN][2];
int val[maxN];
int n;
const int BUBEN = 20;
bool check(int l, int r) {
    for (int j = l; j <= r; j++) {
        for (int len = 1; 2 * len + j <= r; len++) {
            if (tp[j] == tp[j + len] && tp[j] == tp[j + 2 * len]) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; i++) {
        tp[i] = (s[i - 1] - '0');
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int r = min(i + BUBEN, n);
        for (int j = i; j <= r; j++) {
            if (check(i, j)) {
                ans++;
            }
        }
        ans += max(0, n - r);
    }
    cout << ans;
    return 0;
}