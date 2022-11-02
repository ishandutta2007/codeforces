#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, k;

void solve() {
    cin >> n >> k;
    if (n%2==0) {
        int ans = (k-1) % n + 1;
        cout << ans << '\n';
        return;
    } else {
        int mid = (n-1)/2;
        int ans = k % n;
        int nover = (k-1) / mid;
        nover %= n;
        ans += nover;
        ans %= n;
        if (ans<=0) ans += n;
        cout << ans << '\n';
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}