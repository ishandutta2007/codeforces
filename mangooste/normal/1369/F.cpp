#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

bool try_play(ll x, ll y, bool first) {
    ll from = y;
    int type = 0;

    auto query = [&](ll x) -> bool {
        if (type == 0) return first;
        return first ^ ((x - from) & 1);
    };

    while (from > x) {
        ll new_from = (from + 1) >> 1;
        if (type == 0 ? !first : !query((from << 1) - 2)) {
            first = true;
            type = 0;
        } else {
            first ^= (from - new_from) & 1;
            type = 1;
        }
        from = new_from;
    }
    return query(x);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<bool> can_win(n), can_loose(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y, y++;
        can_win[i] = try_play(x, y, true);
        can_loose[i] = try_play(x, y, false);
    }

    bool ans_win = can_win[n - 1], ans_loose = can_loose[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        bool new_ans_win = (can_win[i] && !ans_win) || (can_loose[i] && ans_win);
        bool new_ans_loose = (can_win[i] && !ans_loose) || (can_loose[i] && ans_loose);
        ans_win = new_ans_win;
        ans_loose = new_ans_loose;
    }
    cout << ans_win << ' ' << ans_loose << '\n';
}