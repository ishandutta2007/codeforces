
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// a < b
// only do bitwise once
// (a + x) | (b + y)
// minimize x + (a + x) | (b + y)
// iterate all x
// find y that minimizes a | (b + y)
// find first 01, absorb the rest of b bits

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = b - a;
    for(int x = a; x < b; x++) {
        int i = 20;
        for(; i >= 0; i--) {
            if((~b >> i & 1) && (x >> i & 1)) {
                break;
            }
        }
        int val = (i >= 0 ? (b | (1 << i)) & ~((1 << i) - 1) : b);
        ans = min(ans, x - a + (x | val) - b + 1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int te;
    cin >> te;
    while(te--) solve();
}