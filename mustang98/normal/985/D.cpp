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

const ll magic = 1414223562;

ll sum(ll a) {
    return a * (a + 1) / 2;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, h;
    cin >> n >> h;
    ll l = 1, r = magic;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (sum(mid) <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ll cnt_lvl = l;
    if (cnt_lvl <= h) {
        ll ans = cnt_lvl;
        if (n > sum(cnt_lvl)) {
            ++ans;
        }
        cout << ans;
        return 0;
    }
    ll sumh = sum(h);
    ll ans = h;
    n -= sum(h);
    n -= h;
    ans++;
    l = h, r = magic;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        ll cnt = (sum(mid) - sumh) * 2;
        if (cnt <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ll max_lvl = l;
    ans += (l - h) * 2;
    n -= ((sum(l) - sumh) * 2);
    if (n > (l + 1) * 2) {
        return 228;
    }
    if (n > (l + 1)) {
        ans += 2;
    } else if (n > 0) {
        ans++;
    }
    cout << ans;
    return 0;
}