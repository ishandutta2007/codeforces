#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5005;
int p[maxN];
int pref[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        for (int c = 1; c <= n; c++) {
            for (int a = 1; a <= n; a++) {
                pref[c][a] = pref[c][a - 1];
                if (p[c] > p[a]) pref[c][a]++;
            }
        }
        ll ans = 0;
        for (int b = 1; b <= n; b++) {
            int cur_score = 0;
            for (int c = n; c > b; c--) {
                if (c + 1 <= n && p[b] > p[c + 1]) cur_score++;
                ans += cur_score * pref[c][b - 1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}