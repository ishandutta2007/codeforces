#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, k;
vector < int > all;
int get_id(int v) {
    return lower_bound(all.begin(), all.end(), v) - all.begin();
}
bool has[205][205];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> m >> k;
    vector < pair < int, int > > ed;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        all.push_back(a);
        all.push_back(b);
        ed.emplace_back(a, b);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto t : ed) {
        int id1 = get_id(t.first);
        int id2 = get_id(t.second);
        has[id1][id2] = true;
        has[id2][id1] = true;
    }
    for (int i = 0; i < all.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < all.size(); j++) {
            if (has[i][j]) cnt++;
        }
        vector < int > ans;
        for (int j = 0; j < all.size(); j++) {
            if (i == j) continue;
            if (has[i][j]) continue;
            int num = 0;
            for (int k = 0; k < all.size(); k++) {
                if (has[i][k] && has[j][k]) num++;
            }
            if (cnt != 0 && num * 100 >= cnt * k) ans.push_back(j);
        }
        cout << all[i] << ": " << ans.size() << " ";
        for (int v : ans) cout << all[v] << " ";
        cout << '\n';
    }
}