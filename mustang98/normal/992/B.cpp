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

ll l, r, x, y;

bool fit(int a) {
    return a >= l && a <= r;
}

ll poww(ll a, ll b) {
    ll ans = 1;
    for (int i = 0; i < b; ++i) {
        ans *= a;
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> l >> r >> x >> y;
    /*if (x == y) {
        if (fit(x)) {
            cout << 1;
            return 0;
        } else {
            cout << 0;
            return 0;
        }
    }*/
    if (y % x != 0) {
        cout << 0;
        return 0;
    }
    y /= x;
    map<int, int> s;

    for (ll i = 2; i * i <= y; ++i) {
        if (y % i == 0) {
            y /= i;
            s[i]++;
            --i;
        }
    }
    if (y > 1) {
        s[y]++;
    }
    int k = s.size();
    //cout << k << endl;
    vector<ll> vv;
    for (auto a = s.begin(); a != s.end(); ++a) {
        vv.PB(poww(a->F, a->S));
    }
    int ans = 0;
    for (ll i = 0; i < (1LL << k); ++i) {
        //cout << i << endl;
        ll a = x, b=  x;
        for (int j = 0; j < k; ++j) {
            if (i & (1LL << j)) {
                a *= vv[j];
            } else {
                b *= vv[j];
            }
        }
        if (fit(a) && fit(b)) ++ans;
    }
    cout << ans;

    return 0;
}