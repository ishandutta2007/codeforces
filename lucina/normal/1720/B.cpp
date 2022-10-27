#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    cout << a[n] + a[n - 1] - (a[1] + a[2]) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}