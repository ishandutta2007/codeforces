#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t a[nax];
int64_t ans;
int real_max_c;

pair <int64_t, int> memo_pre[nax];
pair <int64_t, int> memo_suf[nax];

void upd_ans(int64_t a, int max_c) {
    if (max_c > real_max_c) {
        ans = a;
        real_max_c = max_c;
    } else if (max_c == real_max_c) {
        ans = min(ans, a);
    }
}

void solve() {
    cin >> n;


    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        memo_pre[i] = memo_suf[i] = make_pair(int64_t(-1), -1);
    }

    int max_c = 0;
    int64_t sum = 0;
    ans = 1e17;
    real_max_c = 0;

    for (int add = 0 ; add < 2 ; ++ add) {
        max_c = 0;
        sum = 0;

        for (int i = 2 + add; i < n ; i += 2) {
            max_c += 1;
            sum += max(max(a[i - 1], a[i + 1]) + 1 - a[i], int64_t(0));
            memo_pre[i] = make_pair(sum, max_c);
        }
        upd_ans(sum, max_c);
        max_c = 0;
        sum = 0;
        for (int i = n - 1 - add ; i > 1 ; i -= 2) {
            max_c += 1;
            sum += max(max(a[i - 1], a[i + 1]) + 1 - a[i], int64_t(0));
            memo_suf[i] = make_pair(sum, max_c);
        }
        upd_ans(sum, max_c);
    }

    for (int i = 2 ; i < n ; ++ i) {
        if (i + 3 < n) {
            int64_t sum = memo_pre[i].first + memo_suf[i + 3].first;
            int max_c = memo_pre[i].second + memo_suf[i + 3].second;
            upd_ans(sum, max_c);
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
/*
    rated div.2, quite a while though
*/