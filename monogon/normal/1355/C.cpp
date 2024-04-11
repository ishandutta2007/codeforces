
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// x + y > z
// for each possible z, how many sums?
// x + y > z, A <= x <= B <= y <= C
// max(B, z - x + 1) <= y <= C
// sum_{x = A}^B max(0, C - max(B, z - x + 1) + 1)
// three cases.
// z - x + 1 <= B, z - x >= C, and other

// [R, B) => case 1
// [A, L) => case 2
// [L, R) => case 3
// A -- L -- R -- B
// case 1: x >= z - B + 1 => C - B + 1
// case 2: x <= z - C => 0
// case 3: other => sum [ C - (z - x + 1) + 1 ]

// sum^(R - 1) - sum^(L - 1)

// sum_1^k [ C - z + x ] = (C - z) * k + k * (k + 1) / 2

ll a, b, c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for(ll z = c; z <= d; z++) {
        // for(ll x = a; x <= b; x++) {
        //     ans += max(0LL, c - max(b, z - x + 1) + 1);
        // }
        ll R = clamp(z - b + 1, a, b);
        ll L = clamp(z - c, a, b);
        // cout << ": " << L << ", " << R << '\n';
        ans += max(0LL, c - max(b, z - b + 1) + 1);
        ans += (c - b + 1) * (b - R);
        ans += (c - z) * (R - 1) + (R - 1) * R / 2 - (c - z) * (L - 1) - (L - 1) * L / 2;
    }
    cout << ans << '\n';
}