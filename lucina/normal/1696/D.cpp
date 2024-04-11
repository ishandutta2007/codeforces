#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int r_sm[nax];
int r_gt[nax];


void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    {
        vector <pair <int, int>> stk;

        for (int i = n ; i >= 1 ; -- i) {

            while (!stk.empty() && stk.back().first >= a[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                r_sm[i] = n + 1;
            } else r_sm[i] = stk.back().second;
            stk.emplace_back(a[i], i);
        }

        stk.clear();
        for (int i = n ; i >= 1 ; -- i) {

            while (!stk.empty() && stk.back().first <= a[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                r_gt[i] = n + 1;
            } else r_gt[i] = stk.back().second;
            stk.emplace_back(a[i], i);
        }
    }

    int ans = 0;

    for (int i = 1 ; i < n ; ) {
        ans ++;
        if (r_sm[i] <= r_gt[i]) {
            int cr = i;
            while (true) {
                int nxt_r = r_sm[cr];
                if (nxt_r == cr || nxt_r >= r_gt[i]) break;
                cr = nxt_r;
            }
            i = cr;
        } else {
            int cr = i;
            while (true) {
                int nxt_r = r_gt[cr];
                if (nxt_r == cr || nxt_r >= r_sm[i]) break;
                cr = nxt_r;
            }

            i = cr;
        }
    }
    cout << ans << '\n';

}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    ....Global round....
*/