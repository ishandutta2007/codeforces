#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int n, k;
char s[nax];
int a[nax];

void solve() {
    cin >> n >> k;
    cin >> s + 1;
    int ans = 1e9;
    for (int i = 1 ; i <= n ; ++ i) {
        a[i] = a[i - 1] + (s[i] == 'B');
        if (i >= k) {
            int sum = a[i] - a[i - k];
            ans = min(ans, k - sum);
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