#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, m;
bool active[nax];
int cnt_other[nax];

int solve() {
    cin >> m >> n;
    vector <array <int, 3>> e;
    for (int i = 1 ; i <= m ; ++ i) {
        for (int j = 1 ; j <= n ; ++ j) {
            int x;
            cin >> x;
            e.push_back({x, j, i});
        }
    }
    sort(e.begin(), e.end());
    fill(active, active + n + 2, false);
    fill(cnt_other, cnt_other + m + 2, 0);
    int cnt_active = 0;
    bool g = false;
    while (!e.empty()) {
        int cur_cst = e.back()[0];
        while (!e.empty() && e.back()[0] == cur_cst) {
            if (!active[e.back()[1]]) {
                active[e.back()[1]] = true;
                cnt_active += 1;
            }
            cnt_other[e.back()[2]] += 1;
            if (cnt_other[e.back()[2]] > 1) g = true;
            e.pop_back();
        }
      //  printf("cur_cst %d %d %d\n", cur_cst, cnt_active, int(g));
        if (cnt_active == n && g) return cur_cst;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << solve() << '\n';
    }
}