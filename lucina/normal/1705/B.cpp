#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int x;

void solve() {
    cin >> n;
    int64_t ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        ans += a[i];
    }
    ans -= a[n];
    a[n] = 1;
    int st = 1;
    while (a[st] == 0) st++;
    int head = st;
    for (int i = st ; i < n ; ++ i) {
        if (a[i] == 0) {
            if (a[head] == 0) {
                head += 1;
            }
            a[head] -= 1;
            ans += 1;
            a[i] += 1;
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