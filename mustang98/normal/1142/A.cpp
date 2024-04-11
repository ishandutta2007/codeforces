#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

ll n, k;

vector<ll> find_div(ll a) {
    vector<ll> res;
    for (ll i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            res.PB(i);
            res.PB(a / i);
        }
    }
    return res;
}

ll mn = -1, mx = -1;
void upd(ll l) {
    if (l == 0) return;
    ll res = n * k / __gcd(n * k, l);
    if (mn == -1) {
                mn = res;
            }
            if (mx == -1) {
                mx = res;
            }
            mn = min(mn, res);
            mx = max(mx, res);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    ll a, b;
    cin >> a >> b;
    ll s1 = a;
    ll s2 = k - a;
    ll f1 = b;
    ll f2 = k - b;
    ll d1 = (f1 - s1 + 5 * k) % k;
    ll d2 = (f1 - s2 + 5 * k) % k;
    ll d3 = (f2 - s1 + 5 * k) % k;
    ll d4 = (f2 - s2 + 5 * k) % k;
    for (ll i = 0; i <= n; ++i) {
        upd(d1 + k * i);
        upd(d2 + k * i);
        upd(d3 + k * i);
        upd(d4 + k * i);
    }

    /*vector<ll> d = find_div(n * k);
    for (ll gc : d) {
        ll nxt1 = s1 + l;
        ll nxt2 = s2 + l;
        if (min(nxt1 % k, k - (nxt1 % k)) == b) {

        }
        if (min(nxt2 % k, k - (nxt2 % k)) == b) {
            if (mn == -1) {
                mn = (n * k) / l;
            }
            if (mx == -1) {
                mx = (n * k) / l;
            }
            mn = min(mn, (n * k) / l);
            mx = max(mx, (n * k) / l);
        }
    }*/
    if (mn == -1 || mx == -1) exit(228);
    cout << mn << ' ' << mx << endl;
    return 0;
}