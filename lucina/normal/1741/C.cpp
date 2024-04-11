#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];


void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    int sum = 0;
    int ans = n;
    for (int i = 1 ; i <= n ; ++ i) {
        sum += a[i];
        int longest = i;
        for (int j = 1 ; j <= n ; ) {
            int k = j;
            int v = 0;
            while (k <= n && v < sum) v += a[k++];
            if (v != sum) {
                longest = n;
                break;
            }
            longest = max(longest, k - j);
            j = k;
        }
        ans = min(ans, longest);
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