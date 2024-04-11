#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
array <int, 4> a[nax];
int ans[nax];
int color[nax];

void solve_tc() {
    cin >> n;

    vector <array <int, 4>> sc;
    for (int i = 1 ; i <= n;  ++ i) {
        for (int j = 0 ; j < 3 ; ++ j)
            cin >> a[i][j];
        a[i][3] = i;
        auto &[l, r, c, _id] = a[i];
        sc.push_back({l, 1, c, i});
        sc.push_back({r + 1, -1, c, i});
    }

    for (int i = 1 ; i <= n ; ++ i) {
        ans[i] = INT_MAX;
        color[i] = 0;
    }
    int in = 0;

    vector <pair <int, int>> ord;
    sort(sc.begin(), sc.end());
    for (auto &y : sc) {
        if (y[1] == -1) {
            color[y[2]] -= 1;
            in -= 1;
        } else {
            in += 1;
            color[y[2]] += 1;
            if (color[y[2]] != in) {
                ans[y[3]] = 0;
            }
        }
        ord.emplace_back(y[2], y[3]);
    }
    sc.clear();
    for (int i = 1 ; i <= n ; ++ i) {
        auto &[l, r, c, _id] = a[i];
        sc.push_back({-l + 1, -1, c, i});
        sc.push_back({-r, 1, c, i});
        color[i] = 0;
    }
    in = 0;
    sort(sc.begin(), sc.end());

    for (auto &y : sc) {
        if (y[1] == -1) {
            color[y[2]] -= 1;
            in -= 1;
        } else {
            in += 1;
            color[y[2]] += 1;
            if (color[y[2]] != in) {
                ans[y[3]] = 0;
            }
        }
    }

    auto dist = [](int i, int j) -> int {
        int l1 = a[i][0], r1 = a[i][1];
        int l2 = a[j][0], r2 = a[j][1];
        if (max(l1, l2) <= min(r1, r2)) return 0;
        return max(l1, l2) - min(r1, r2);
    };

    for (int iter = 0 ; iter < 2 ; ++ iter) {
        pair <int, int> last_same = make_pair(ord[0].first, 1);

        for (int i = 1 ; i < ord.size() ; ++ i) {
            auto [c, id] = ord[i];
            if (c == last_same.first) {
                last_same.second += 1;
                int to = i - last_same.second;
                if (to >= 0) {
                    ans[id] = min(ans[id], dist(ord[to].second, id));
                    ans[ord[to].second] = min(ans[ord[to].second], dist(ord[to].second, id));
                }
            } else {
                int to = i - 1;
                ans[id] = min(ans[id], dist(ord[to].second, id));
                ans[ord[to].second] = min(ans[ord[to].second], dist(ord[to].second, id));
                last_same = make_pair(c, 1);
            }
        }
        reverse(ord.begin(), ord.end());
    }


    for (int i = 1 ; i <= n ; ++ i)
        cout << ans[i] << ' ';
    cout << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve_tc();
    }
}