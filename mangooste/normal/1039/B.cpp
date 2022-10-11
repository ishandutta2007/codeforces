#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

const int BUBEN = 45;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool ask(ll l, ll r) {
    cout << l + 1 << ' ' << r << endl;

    string s;
    cin >> s;
    assert(s != "Bad");
    if (r - l == 1 && s == "Yes")
        exit(0);

    return s == "Yes";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    ll l = 0, r = n;
    while (true) {
        ll mid = (l + r) / 2;
        if (r - l > BUBEN) {
            if (ask(mid, r))
                l = mid;
            else
                r = mid;
        } else {
            ll cur = rng() % (r - l);
            ask(l + cur, l + cur + 1);
        }

        l = max(0ll, l - k);
        r = min(n, r + k);
    }
}