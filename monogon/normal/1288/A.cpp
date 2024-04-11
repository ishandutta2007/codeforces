
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int T;
ll n, d;

// x + d/(x+1) <= n
// d <= (n - x)(x + 1)
// x^2 + (1 - n) x + (d - n) <= 0
// minimum occurs at 2x + (1 - n) = 0
// x = (n - 1) / 2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> n >> d;
        ll x = (n - 1) / 2;
        cout << (x + (d + x) / (x + 1) <= n ? "YES" : "NO") << endl;
    }
}