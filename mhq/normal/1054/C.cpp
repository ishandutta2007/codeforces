#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e3 + 10;
int l[maxN], r[maxN];
int n;
bool used[maxN];
bool in_cur[maxN];
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> r[i];
    int mx = n;
    for (int iter = 1; iter <= n; iter++) {
        memset(in_cur, 0, sizeof in_cur);
        vector < int > all;
        bool all_used = true;
        for (int i = 1; i <= n; i++) {
            if (used[i] == true) continue;
            all_used = false;
            if (l[i] == 0 && r[i] == 0) {
                ans[i] = mx;
                in_cur[i] = true;
                used[i] = true;
                all.push_back(i);
            }
        }
        mx--;
        if (all_used) break;
        if (all.empty()) {
            cout << "NO";
            return 0;
        }
        int cnt_r = all.size();
        int cnt_l = 0;
        for (int i = 1; i <= n; i++) {
            if (in_cur[i]) cnt_l++, cnt_r--;
            if (used[i]) continue;
            l[i] -= cnt_l;
            r[i] -= cnt_r;
            if (l[i] < 0 || r[i] < 0) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}