#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int n;
int a[maxN];
int cnt[maxN];
int pref[maxN];
const int SHIFT = maxN;
int lst[maxN + SHIFT];
vector<int> poses[maxN];
int when[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        poses[a[i]].emplace_back(i);
    }
    int f = 1;
    for (int c = 1; c <= n; c++) {
        if (cnt[c] > cnt[f]) f = c;
    }
    memset(when, -1, sizeof when);
    when[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        if (a[i] == f) {
            pref[i]++;
            when[pref[i]] = i;
        }
    }
    int lim = min(n, 3 * (int)sqrt(n));
    int best = 0;
    for (int i = 1; i <= n; i++) {
        if (i == f) continue;
        if (cnt[i] >= lim) {
            memset(lst, -1, sizeof lst);
            lst[SHIFT] = 0;
            int cur_val = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j] == f) cur_val--;
                else if (a[j] == i) cur_val++;
                if (lst[SHIFT + cur_val] != -1) {
                    best = max(best, j - lst[SHIFT + cur_val]);
                } else {
                    lst[SHIFT + cur_val] = j;
                }
            }
        }
        else {
            if (poses[i].empty()) continue;
            for (int a = 0; a < poses[i].size(); a++) {
                int x = poses[i][a];
                for (int b = poses[i].size() - 1; b >= a; b--) {
                    int y = poses[i][b];
                    int cur_sum = b - a + 1 - pref[y] + pref[x - 1];
                    if (cur_sum < 0) continue;
                    int cnt_before = pref[x - 1];
                    int cnt_tot = pref[y];
                    for (int take = 0; take <= cur_sum; take++) {
                        int l1 = (cnt_before < take ? 1 : (when[cnt_before - take] + 1));
                        int r1 = ((cur_sum - take + cnt_tot >= cnt[f]) ? n : (when[cnt_tot + cur_sum - take + 1] - 1));
                        best = max(best, r1 - l1 + 1);
                    }
                    break;
                }
            }
        }
    }
    cout << best;
    return 0;
}