#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    long long a, b, ab;
    cin >> a >> b >> ab;
    long long ans = 2 * ab;
    int d = min(a, b);
    ans += 2 * d;
    a -= d, b -= d;
    if (a > 0 || b > 0) ++ans;
    cout << ans << endl;
    return 0;
}