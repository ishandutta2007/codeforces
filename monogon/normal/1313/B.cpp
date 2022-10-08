
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll n, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        ll m1 = x + y - n + 1, m2 = x + y - 1;
        m1 = clamp(m1, 1LL, n);
        m2 = clamp(m2, 1LL, n);
        cout << m1 << " " << m2 << endl;
    }
}