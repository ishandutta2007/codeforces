
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x;
    cin >> x;
    vector<tuple<ll, ll, char>> ops;
    while(x > 1) {
        int pos = 20;
        while(((x >> pos) & 1) == 0) pos--;
        if((x >> (pos - 1)) & 1) {
            ll y = x + x;
            ll z = (y ^ x) + x;
            ll w = y + x;
            assert((z ^ w) < x);
            ops.emplace_back(x, x, '+');
            ops.emplace_back(x, y, '^');
            ops.emplace_back(x, y, '+');
            ops.emplace_back(x ^ y, x, '+');
            ops.emplace_back(z, w, '^');
            x = (z ^ w);
        }else {
            ll y = ((1LL * x) << pos);
            ll z = (x ^ y);
            ll w = z + x;
            ll a = (w ^ y);
            int pos2 = 20;
            while(((a >> pos2) & 1) == 0) pos2--;
            rep(i, 0, pos) {
                ops.emplace_back((x << i), (x << i), '+');
            }
            ops.emplace_back(x, y, '^');
            ops.emplace_back(x, z, '+');
            ops.emplace_back(w, y, '^');
            rep(i, 0, pos - pos2) {
                ops.emplace_back(a << i, a << i, '+');
            }
            ops.emplace_back(x, a << (pos - pos2), '^');
            x ^= (a << (pos - pos2));
        }
    }
    cout << sz(ops) << '\n';
    for(auto &T : ops) {
        ll x, y;
        char c;
        tie(x, y, c) = T;
        cout << x << ' ' << c << ' ' << y << '\n';
    }
    // int y = x * 4;
    // int z = (y ^ x) + x;
    // int w = y + x;
    // cout << (z ^ w) << endl;
    // vi ve;
    // for(int i = 20; i >= 0; i--) {
    //     if((x >> i) & 1) {
    //         ve.push_back(i);
    //     }
    // }
    // for(int x : ve) cout << x << ' ';
    // cout << endl;
}