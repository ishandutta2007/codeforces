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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<ll> v;
    ll cur = 2050;
    while (true) {
        v.push_back(cur);
        if (cur > 1e18) {
            break;
        }
        cur *= 10;
    }
    int T;
    cin >> T;
    reverse(v.begin(), v.end());
    while (T--) {
        ll x;
        cin >> x;
        int ans = 0;
        for (ll a : v) {
            while (x >= a) {
                x -= a;
                ++ans;
            }
        }
        if (x) {
            puts("-1");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}