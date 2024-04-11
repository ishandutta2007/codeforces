
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll a, b, n, s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> a >> b >> n >> s;
        ll x = min(s / n, a);
        ll y = s - x * n;
        cout << (y <= b ? "YES" : "NO") << endl;
    }
}