
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll t, n, x, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x >> a >> b;
        cout << min(n - 1, abs(a - b) + x) << endl;
    }
}