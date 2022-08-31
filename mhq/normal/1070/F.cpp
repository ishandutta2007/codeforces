#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 4 * (int)1e5 + 10;
int a[maxN];
vector < int > all[2][2];
vector < int > pref[2][2];
signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int val;
        cin >> val;
        all[s[0] - '0'][s[1] - '0'].push_back(val);
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sort(all[i][j].begin(), all[i][j].end());
            reverse(all[i][j].begin(), all[i][j].end());
            pref[i][j].resize(all[i][j].size() + 1);
            pref[i][j][0] = 0;
            for (int k = 0; k < all[i][j].size(); k++) {
                pref[i][j][k + 1] = pref[i][j][k] + all[i][j][k];
            }
        }
    }
    int ans = pref[1][1].back();
    //cout << ans << endl;
    int can = 0;
    int cnt_11 = all[1][1].size();
    for (int dif = -5 * (int)1e5; dif <= 5 * (int)1e5; dif++) {
        int take = max(0LL, -dif);
        if (take > min((int)all[1][0].size(), (int)all[0][1].size() - dif)) continue;
        take = min((int)all[1][0].size(), (int)all[0][1].size() - dif);
        int lim_00 = min(cnt_11 - abs(dif), (int)all[0][0].size());
        if (lim_00 < 0) continue;
        //cout << take << " " << dif << " " << lim_00 << endl;
        //cout << pref[0][0][lim_00];
        can = max(can, pref[0][0][lim_00] + pref[1][0][take] + pref[0][1][take + dif]);
    }
    cout << ans + can;
    return 0;
}