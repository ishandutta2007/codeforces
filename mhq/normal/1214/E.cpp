#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
int d[maxN];
vector < pair < int, int > > ans;
void add(int x, int y) {
    ans.emplace_back(x, y);
}
int pos[maxN];
int ord[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        all.emplace_back(d[i], i);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int i = 0; i < all.size(); i++) {
        pos[i + 1] = 2 * all[i].second;
        ord[i + 1] = all[i].second;
    }
    for (int i = 0; i + 1 < all.size(); i++) {
        add(2 * all[i].second, 2 * all[i + 1].second);
    }
    int now_lim = n;
    for (int i = 1; i <= n; i++) {
        add(pos[i + d[ord[i]] - 1], 2 * ord[i] - 1);
        assert(i + d[ord[i]] - 1 <= now_lim);
        if (i + d[ord[i]] - 1 == now_lim) {
            now_lim++;
            pos[now_lim] = 2 * ord[i] - 1;
        }
    }
    for (auto it : ans) {
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}