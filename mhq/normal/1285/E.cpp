#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int n;
int l[maxN], r[maxN];
pair < int, int > max_l[maxN];
vector < int > events[maxN];
pair < int, int > sec_max[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    const int INF = 2e9 + 100;
    while (tst--) {
        cin >> n;
        vector < pair < int, int > > all;
        for (int i = 1; i <= n; i++) {
            int l, r;
            cin >> l >> r;
            all.emplace_back(l, r);
        }
        sort(all.begin(), all.end(), [](pair < int, int >& a, pair < int, int >& b) {
            return a.second < b.second;
        });
        for (int i = 0; i < n; i++) {
            l[i + 1] = all[i].first;
            r[i + 1] = all[i].second;
        }
        int best = -100;
        int tot = n - 1;
        max_l[n + 1] = {INF, n + 1};
        sec_max[n + 1] = {INF, n + 1};
        for (int i = 1; i <= n; i++) {
            events[i].clear();
        }
        for (int i = n - 1; i >= 1; i--) {
            max_l[i + 1] = max_l[i + 2];
            sec_max[i + 1] = sec_max[i + 2];
            pair < int, int > t = {l[i + 1], i + 1};
            if (t <= max_l[i + 1]) {
                sec_max[i + 1] = max_l[i + 1];
                max_l[i + 1] = t;
            }
            else if (t <= sec_max[i + 1]) {
                sec_max[i + 1] = t;
            }
            if (max_l[i + 1].first <= r[i]) {
                events[max_l[i + 1].second].push_back(i);
                tot--;
            }
        }
        //cout << tot << endl;
        for (int i = 1; i <= n; i++) {
            int wtot = tot;
            // delete
            if (i < n && max_l[i + 1].first <= r[i]) wtot++;
            for (auto it : events[i]) {
                wtot++;
                if (sec_max[it + 1].first <= r[it]) wtot--;
            }
            best = max(best, wtot);
        }
        cout << best  << '\n';
    }
    return 0;
}