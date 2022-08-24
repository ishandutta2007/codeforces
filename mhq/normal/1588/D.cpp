#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 10;
string s[maxN];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> a(n);
    vector<bool> ok(52, true);
    for (int i = 0; i < n; i++) {
        vector<bool> can(52, false);
        for (int j = 0; j < s[i].size(); j++) {
            if ('a' <= s[i][j] && s[i][j] <= 'z') {
                can[s[i][j] - 'a'] = true;
            }
            else {
                can[s[i][j] - 'A' + 26] = true;
            }
        }
        for (int z = 0; z < 52; z++) {
            if (!can[z]) ok[z] = false;
        }
    }
    vector<vector<pair<int,int>>> st(n, vector<pair<int,int>>(52, make_pair(-1, -1)));
    vector<vector<int>> vals(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            int x = 0;
            if ('a' <= s[i][j] && s[i][j] <= 'z') x = s[i][j] - 'a';
            else x = s[i][j] - 'A' + 26;
            if (ok[x]) {
                vals[i].emplace_back(x);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vals[i].size(); j++) {
            if (st[i][vals[i][j]].first == -1) st[i][vals[i][j]].first = j;
            else st[i][vals[i][j]].second = j;
        }
    }
    vector<vector<int>> dp(52, vector<int>(1 << n, -1e9));
    vector<vector<pair<int,int>>> prv(52, vector<pair<int,int>>(1 << n));
    for (int let = 0; let < 52; let++) {
        if (!ok[let]) continue;
        dp[let][0] = 1;
    }
    vector<pair<int,int>> order;
    for (int x = 0; x < vals[0].size(); x++) {
        if (st[0][vals[0][x]].first == x) order.emplace_back(vals[0][x], 0);
        else order.emplace_back(vals[0][x], 1);
    }
    for (auto& it : order) {
        int letter = it.first;
        int pos = it.second;
        for (int z = 0; z < (1 << (n - 1)); z++) {
            int our_mask = pos + 2 * z;
            if (dp[letter][our_mask] < 0) continue;
            for (int new_letter = 0; new_letter < 52; new_letter++) {
                if (!ok[new_letter]) continue;
                int new_mask = 0;
                bool good = true;
                for (int x = 0; x < n; x++) {
                    int was_pos = ((our_mask & (1 << x)) ? st[x][letter].second : st[x][letter].first);
                    assert(was_pos != -1);
                    if (st[x][new_letter].first > was_pos) {
                        //nothing
                    }
                    else if (st[x][new_letter].second > was_pos) {
                        new_mask |= (1 << x);
                    }
                    else {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    if (dp[new_letter][new_mask] < dp[letter][our_mask] + 1) {
                        dp[new_letter][new_mask] = dp[letter][our_mask] + 1;
                        prv[new_letter][new_mask] = {letter, our_mask};
                    }
                }
            }
        }
    }
    int ans = 0;
    int best_mask = -1;
    int best_letter = -1;
    for (int z = 0; z < 52; z++) {
        for (int x = 0; x < (1 << n); x++) {
            if (ans < dp[z][x]) {
                ans = dp[z][x];
                best_letter = z;
                best_mask = x;
            }
        }
    }
    if (ans == 0) {
        cout << 0 << '\n' << '\n';
    }
    else {
        string ans_s;
        for (int p = 0; p < ans; p++) {
            if (best_letter < 26) {
                ans_s += (char)('a' + best_letter);
            }
            else {
                ans_s += (char)('A' + (best_letter - 26));
            }
            int new_letter = prv[best_letter][best_mask].first;
            int new_mask = prv[best_letter][best_mask].second;
            best_letter = new_letter;
            best_mask = new_mask;
        }

        reverse(ans_s.begin(), ans_s.end());
        cout << ans_s.size() << '\n';
        cout << ans_s << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}