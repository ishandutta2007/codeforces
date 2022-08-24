#include <bits/stdc++.h>
using namespace std;
int n;
int ne;
int ans(int x) {
    return max(min((x / 2), n) - max(x - n, 1) + 1, 0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n <= 4) {
        cout << (n * (n - 1)) / 2;
        return 0;
    }
    long long t = 2 * n - 1;
    long long qq = 10;
    long long pw = 0;
    while (t >= qq - 1) {
        qq = qq * 10;
        pw = pw * 10 + 9;
    }
    for (long long i = pw; i <= 2 * n - 1; i += (pw + 1)) {
        //cout << ans(9);
        ne += ans(i);
    }
    cout << ne;
    return 0;
}