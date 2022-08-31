#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    //2 * a_1 - 1 + 2 * a_2 - 1 + .. + 2 * a_k - 1 =
    for (int i = 1; i <= 100; i++) {
        for (int cnt = 1; cnt <= 100 && cnt <= i; cnt++) {
            if (n % 2 != cnt % 2) continue;
            int need = (n + cnt) / 2;
            vector<int> cur(cnt + 1);
            for (int z = 1; z <= cnt; z++) {
                cur[z - 1] = z;
                need -= z;
            }
            if (need < 0) continue;
            cur[cnt] = i + 1;
            for (int p = cnt - 1; p >= 0; p--) {
                int lim = min(need, cur[p + 1] - cur[p] - 1);
                need -= lim;
                cur[p] += lim;
            }
            if (need == 0) {
                reverse(cur.begin(), cur.begin() + cnt);
                vector<vector<char>> ans(i + 1, vector<char>(i + 1, '.'));
                for (int x = 1; x <= cnt; x++) {
                    for (int y = x; y <= x + cur[x - 1] - 1; y++) {
                        ans[i + 1 - x][y] = 'o';
                        ans[i + 1 - y][x] = 'o';
                    }
                }
                cout << i << '\n';
                for (int x = 1; x <= i; x++) {
                    for (int y = 1; y <= i; y++) {
                        cout << ans[x][y];
                    }
                    cout << '\n';
                }
                return 0;
            }

        }
    }
    cout << -1;
    return 0;
}