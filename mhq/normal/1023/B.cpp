#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    ll l = max(1 * 1LL, k - n);
    ll r = min(n, (k - 1) / 2);
    cout << max(r - l + 1, 0LL);
    return 0;
}