
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll n, a, b, c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> c >> d;
        cout << ((a + b) * n >= c - d && (a - b) * n <= c + d ? "YES" : "NO") << "\n";
    }
}