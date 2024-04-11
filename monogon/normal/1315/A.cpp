
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, a, b, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> x >> y;
        cout << max(max(x, a - x - 1) * b, max(y, b - y - 1) * a) << endl;
    }
}