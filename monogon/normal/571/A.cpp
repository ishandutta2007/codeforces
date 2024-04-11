
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

// how many ways to increase? ways to split up L into 4 parts
// part added to a, b, c, and ignored
// stars and bars -> (L + 3 choose 3)

// subtract ways where (A+x) >= (B+y) + (C+z)
// and symmetries
// iterate through all x. For a fixed x, how many ways to choose y, z so that
// A + x - B - C >= (y + z)?
// 0 <= y + z <= min(L, A + x - B - C)

// sum_{i=0}^up (ways to partition i = y + z: i + 1)
// = sum_{i = 0}^up (i + 1) = sum_{i=1}^{up+1} (i) = (up + 1) * (up + 2) / 2

ll a, b, c, l;

// ways where a + x >= b + y + c + z
ll solve(ll a, ll b, ll c) {
    ll ans = 0;
    rep(x, 0, l + 1) {
        ll up = min(l - x, a + x - b - c);
        if(up >= 0) {
            ans += (up + 1) * (up + 2) / 2;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> l;
    ll ways = (l + 3) * (l + 2) * (l + 1) / 6;
    ways -= solve(a, b, c) + solve(b, a, c) + solve(c, a, b);
    cout << ways << '\n';
}