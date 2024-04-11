#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int64_t a[nax];

bool solve() {
    cin >> n >> k;
    for (int i = 0 ; i < k ; ++ i) {
        cin >> a[i];
    }
    for (int i = k - 1 ; i > 0 ; -- i) {
        a[i] -= a[i - 1];
    }
    if (k == 1) return true;

    if (!is_sorted(a + 1, a + k)) return false;
    int64_t b = a[1];
    int cnt = n - k + 1;
    int64_t can = cnt * a[1];
    return a[0] <= can;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}