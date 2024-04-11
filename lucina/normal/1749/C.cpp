#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int k = 0 ; k <= n + 1 ; ++ k) {
        deque <int> d;
        for (int i = 1 ; i <= n ; ++ i) {
            d.push_back(a[i]);
        }
        bool ok = true;
        for (int j = k ; j >= 1 ; -- j) {
            while (!d.empty() && d.back() > j) d.pop_back();
            if (d.empty()) {
                ok = false;
                break;
            }
            d.pop_back();
            if (!d.empty()) {
                d.pop_front();
            }
        }
        if (!ok) {
            cout << k - 1 << '\n';
            return;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}