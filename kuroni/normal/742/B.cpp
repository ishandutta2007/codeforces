#include <bits/stdc++.h>
using namespace std;

const int MX = 1E6 + 5;

int n, x, a[MX], cnt[MX];
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]--;
        ans += cnt[a[i] ^ x];
    }
    cout << ans;
}