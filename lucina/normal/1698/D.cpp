#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int a[nax];

void query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    for (int x = l ; x <= r ; ++ x)
        cin >> a[x];
}

void solve() {
    cin >> n;
    int l = 1, r = n;
    int ans = -1;
    while (l < r) {
        int x = l + r >> 1;
        if (x % 2) {
            query(1, x);
            int cnt = 0;
            for (int j = 1 ; j <= x ; ++ j) {
                if (a[j] > x) cnt += 1;
            }
            if (cnt % 2) {
                l = x + 1;
            } else r = x;
        } else {
            query(x + 1, n);
            int cnt = 0;
            for (int j = x + 1 ; j <= n ; ++ j) {
                if (a[j] <= x) cnt += 1;
            }
            if (cnt % 2 == 0) {
                l = x + 1;
            } else r = x;
        }
    }
    cout << "! " << l << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}