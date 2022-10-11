#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cout << max({
            min(a, b) * min(c, d),
            min(a, c) * min(b, d),
            min(a, d) * min(b, c)
        }) << '\n';
    }
}