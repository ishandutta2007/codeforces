#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int pref[3][3][maxN];
map < char, int > mp;
int n, k;
void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int t = 0; t < 3; t++) {
                pref[t][j][i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int p = 0; p < 3; p++) {
            for (int g = 0; g < 3; g++) {
                pref[p][g][i] = pref[p][g][i - 1];
            }
        }
        pref[i % 3][mp[s[i - 1]]][i]++;
    }
    int mn = n + 10;
    for (int l = 1; l + k - 1 <= n; l++) {
        int r = l + k - 1;
        for (int st = 0; st < 3; st++) {
            int need = 0;
            for (int res = 0; res < 3 && res <= r; res++) {
                int total = max((r - res) / 3 - (l - res + 2) / 3 + 1, 0);
                need += total - (pref[res][(st + res) % 3][r] - pref[res][(st + res) % 3][l - 1]);
            }
            mn = min(mn, need);
        }
    }
    cout << mn << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}