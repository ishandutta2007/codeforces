#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 10;
ll x[maxN];
string s[maxN];
const int maxM = 1e4 + 10;
vector<int> gg[3 * maxN];
int score[maxM];
int cnt[3 * maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int best_mask = -1;
        ll best_ans = -1e18;
        for (int i = 0; i < (1 << n); i++) {
            ll ans = 0;
            for (int z = -n; z <= n; z++) {
                cnt[z + n] = 0;
//                gg[z + n].clear();
            }
            for (int t = 0; t < m; t++) score[t] = 0;

            for (int z = 0; z < n; z++) {
                if (i & (1 << z))  {
                    ans += x[z];
                    for (int t = 0; t < m; t++) {
                        if (s[z][t] == '1') score[t] -= 1;
                    }
                }
                else {
                    ans -= x[z];
                    for (int t = 0; t < m; t++) {
                        if (s[z][t] == '1') score[t] += 1;
                    }
                }
            }
//            cout << ans << " ?? " << endl;
            for (int t = 0; t < m; t++) {
                assert(-n <= score[t] && score[t] <= n);
//                cout << " hi " << score[t] << endl;
                cnt[score[t] + n] += 1;
            }
            int val = 1;
            for (int z = -n; z <= n; z++) {
                for (int u = 0; u < cnt[z + n]; u++) {
                    ans += val * z;
                    val++;
                }
            }
            if (ans > best_ans) {
                best_ans = ans;
                best_mask = i;
            }
        }

        for (int z = -n; z <= n; z++) {
            gg[z + n].clear();
        }
        for (int t = 0; t < m; t++) score[t] = 0;

        for (int z = 0; z < n; z++) {
            if (best_mask & (1 << z))  {
                for (int t = 0; t < m; t++) {
                    if (s[z][t] == '1') score[t] -= 1;
                }
            }
            else {
                for (int t = 0; t < m; t++) {
                    if (s[z][t] == '1') score[t] += 1;
                }
            }
        }
        for (int t = 0; t < m; t++) {
            assert(-n <= score[t] && score[t] <= n);
            gg[score[t] + n].emplace_back(t);
//            cnt[score[t] + n] += 1;
        }
        vector<int> perm(m);
        int val = 1;
        for (int z = -n; z <= n; z++) {
            for (int u : gg[z + n]) {
                perm[u] = val;
                val++;
            }
        }
        for (int c : perm) cout << c << " ";
        cout << '\n';
    }
    return 0;
}