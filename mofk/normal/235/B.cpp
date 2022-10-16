#include <bits/stdc++.h>

using namespace std;

int n;
double x, ans, len;

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        ans += x * (2 * len + 1);
        len = (len + 1) * x;
    }
    cout << setprecision(12) << fixed << ans << endl;
}