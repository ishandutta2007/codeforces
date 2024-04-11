#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;
int cnt[2][2];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int A = a[i] - '0', B = b[i] - '0';
        if (B == 1) ans += cnt[!A][0];
        else ans += cnt[!A][0] + cnt[!A][1];
        ++cnt[A][B];
    }
    cout << ans << endl;
    return 0;
}