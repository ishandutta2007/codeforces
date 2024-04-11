#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
string s;
int n, q, w;
int64_t sum[nax];

array <int, 4> ans[9][9];

void solve() {
    cin >> s;

    cin >> w >> q;
    n = s.size();
    for (int i = 1 ; i <= n ; ++ i) {
        sum[i] = sum[i - 1] + s[i - 1] - '0';
    }

    vector <int> where[10];

    for (int i = 1 ; i + w - 1 <= n ; ++ i) {
        int s = (sum[i + w - 1] - sum[i - 1]) % 9;
        s %= 9;
        where[s].push_back(i);
    }

    while (q --) {
        int k, l, r;
        cin >> l >> r >> k;
        int v = (sum[r] - sum[l - 1]) % 9;
        vector <pair <int, int>> ans;
        for (int i = 0 ; i < 9 ; ++ i) {
            for (int j = 0 ; j < 9 ; ++ j) {
                bool ok = ((v * i + j) % 9 == k);
                if (!ok) continue;
                if (i == j && where[i].size() > 1) {
                    ans.emplace_back(where[i][0], where[i][1]);
                } else if (i != j && where[i].size() && where[j].size()) {
                    ans.emplace_back(where[i][0], where[j][0]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.empty())
            cout << "-1 -1\n";
        else cout << ans[0].first << ' ' << ans[0].second << '\n';
    }

}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}