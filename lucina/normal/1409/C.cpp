#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int x, y;

void solve() {
    cin >> n >> x >> y;
    int a1, dif;
    int ans = INT_MAX;

    int c = y - x;

    for (int d = 1 ; d <= 50 ; ++ d) {
        if (c % d) continue;
        int inside = (y - x) / d + 1;
        if (inside > n) continue;
        int can_left = (x - 1) / d;
        int res = max(0, n - inside - can_left);
        int new_y = y + res * d;
        if (new_y < ans) {
            ans = new_y;
            a1 = new_y - (n - 1) * d;
            dif = d;
        }
    }

    for (int i = 1 ; i <= n ; ++ i) {
        cout << a1 << ' ';
        a1 += dif;
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    I have been too lazy, lately.
*/