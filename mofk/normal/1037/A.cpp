#include <bits/stdc++.h>

using namespace std;

int n;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = 0;
    while (n) ++ans, n >>= 1;
    cout << ans << endl;
    return 0;
}