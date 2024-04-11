#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

ll sum(ll x) {
    if (x <= 0) return 0;
    return x * (x + 1) / 2LL;
}

ll cnt(ll x, ll y) {
    if (x < y) swap(x, y);
    ll cnt = y;
    ll ans = 0;
    for (ll i = 0; i < cnt; ++i) {
        ans += i * (i + 1);
        ans += (x + y - i) * (i + 1);
    }
    ll add = sum(x) - sum(cnt - 1);
    ans += add * (y + 1);
    /*for (int i = cnt; i <= x; ++i) {
        ans += i * (y + 1);
    }*/
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll m, b;
    cin >> m >> b;
    ll ans = 0;
    for (ll y = b, x = 0; y >= 0; y--, x += m) {
       //     cout << x << ' ' << y << endl;
        ans = max(ans, cnt(x, y));
    }
    cout << ans;
    return 0;
}