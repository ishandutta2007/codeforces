#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, k;
pair <int, int> a, b;
void solve () {
    cin >> n >> k;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    if (a.first > b.first) swap(a, b);
    auto [l, r] = a;
    auto [x, y] = b;

    int in = min(y, r) - max(l, x);
    int intersect_cost;
    if (in > 0) intersect_cost = 0;
    else intersect_cost = -in;
    in = max(in, 0);
    int can_use = max(0, max(y, r) - min(x, l) - in);


    long long ans = LLONG_MAX;

 //   fprintf(stderr, "huh %d %d %d\n", in, can_use, intersect_cost);

    for (int i = 1 ; i <= n ; ++ i) {
        long long w = 1LL * intersect_cost * i;
        long long cur_ct = 1LL * in * n;
        long long has = 1LL * i * can_use;
        long long res = (long long)k - cur_ct;
        if (res <= 0) {
            ans = min(ans, w);
            continue;
        }
        if (has >= res) {
            ans = min(ans, w + res);
            continue;
        }

        res -= has;
        ans = min(ans, w + has + 2 * res);
    }

    cout << ans << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/