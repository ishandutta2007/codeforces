#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 25 * 10000 + 5;
int ddP[maxN];
int ddS[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    memset(ddP, -1, sizeof ddP);
    memset(ddS, -1, sizeof ddS);
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dif(n);
    vector<bool> inter(m);
    int sz = 0;
    for (int i = 1; i < n; i++) {
        for (int x = 0; x < m; x++) {
            if (a[0][x] != a[i][x]) {
                dif[i].emplace_back(x);
                if (!inter[x]) {
                    sz++;
                }
                inter[x] = true;
            }
        }
        if (dif[i].size() > 4) {
            cout << "No";
            return 0;
        }
    }
    vector<int> ans_not;
    for (int i = 0; i < m; i++) {
        if (!inter[i]) ans_not.emplace_back(a[0][i]);
    }
    vector<vector<int>> na(n, vector<int>(sz));
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            if (inter[j]) {
                na[i][cur] = a[i][j];
                cur++;
            }
        }
    }
    a = na;
    vector<vector<int>> ndif(n);
    for (int i = 1; i < n; i++) {
        for (int x = 0; x < sz; x++) {
            if (a[0][x] != a[i][x]) {
                ndif[i].emplace_back(x);
            }
        }
        assert(ndif[i].size() <= 4);
    }
    dif = ndif;
    vector<int> cnt_dif(n);
    auto print_ans = [&](vector<int> t) {
        assert(t.size() == sz);
        int ptr1 = 0;
        int ptr2 = 0;
        cout << "Yes\n";
        for (int u = 0; u < m; u++) {
            if (!inter[u]) {
                cout << ans_not[ptr1] << " ";
                ptr1++;
            }
            else {
                cout << t[ptr2] << " ";
                ptr2++;
            }
        }
        assert(ptr1 == ans_not.size() && ptr2 == t.size());
        exit(0);
    };
    vector<int> cur_ans(sz);
    vector<vector<int>> aue(n, vector<int>(sz, 0));
    for (int i = 0; i < sz; i++) {
        vector<int> c;
        for (int x = 0; x < n; x++) c.emplace_back(a[x][i]);
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (int x = 0; x < n; x++) {
            aue[x][i] = lower_bound(c.begin(), c.end(), a[x][i]) - c.begin();
        }
    }
    auto combine = [&](int x, int y) {
        if (x == -2 || y == -2) return -2;
        if (x == -1 || y == -1) return (x + y + 1);
        if (x == y) return x;
        return -2;
    };
    for (int x = -1; x < sz; x++) {
        for (int y = (x == -1 ? -1 : (x + 1)); y < sz; y++) {
            bool ok = true;
            int who = -1;
            for (int r = 0; r < n; r++) {
                cnt_dif[r] = 0;
                for (int t : dif[r]) {
                    if (t != x && t != y) cnt_dif[r]++;
                }
                if (cnt_dif[r] > 2) {
                    ok = false;
                    break;
                }
                if (cnt_dif[r] == 2) {
                    who = r;
                    break;
                }
            }
            if (!ok) continue;
            if (who != -1) {
                vector<int> auf;
                if (x != -1) auf.emplace_back(x);
                if (y != -1) auf.emplace_back(y);
                for (int r = 0; r < n; r++) {
                    cnt_dif[r] = 0;
                    for (int t : dif[r]) {
                        if (t != x && t != y) cnt_dif[r]++;
                    }
                    for (int t : auf) {
                        if (a[r][t] != a[who][t]) cnt_dif[r]++;
                    }
                    if (cnt_dif[r] > 2) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    for (int i = 0; i < sz; i++) {
                        if (i != x && i != y) cur_ans[i] = a[0][i];
                        else cur_ans[i] = a[who][i];
                    }
                    print_ans(cur_ans);
                }
                else {
                    continue;
                }
            }
            //who = -1
            if (x == -1 || y == -1) {
                for (int i = 0; i < sz; i++) {
                    if (i != x && i != y) cur_ans[i] = a[0][i];
                    else cur_ans[i] = 228;
                }
                print_ans(cur_ans);
            }
            for (int r = 0; r <= n; r++) {
                ddP[r] = -1;
                ddS[r] = -1;
            }
            for (int r = 0; r < n; r++) {
                if (cnt_dif[r] == 0) continue;
                assert(cnt_dif[r] == 1);
                int val = a[r][y];
                ddP[aue[r][x]] = combine(ddP[aue[r][x]], val);
                ddS[aue[r][x]] = combine(ddS[aue[r][x]], val);
            }
            for (int he = 1; he <= n; he++) {
                ddP[he] = combine(ddP[he - 1], ddP[he]);
            }
            for (int he = n - 1; he >= 0; he--) {
                ddS[he] = combine(ddS[he], ddS[he + 1]);
            }
            for (int r = 0; r < n; r++) {
                int c = -1;
                if (aue[r][x] != 0) c = ddP[aue[r][x] - 1];
                int D = combine(c, ddS[aue[r][x] + 1]);
                if (D != -2) {
                    if (D == -1) D = 15;
                    for (int i = 0; i < sz; i++) {
                        if (i != x && i != y) cur_ans[i] = a[0][i];
                        else {
                            if (i == x) cur_ans[i] = a[r][x];
                            else cur_ans[i] = D;
                        }
                    }
                    print_ans(cur_ans);
                }
            }
        }
    }
    cout << "No";
    return 0;
}