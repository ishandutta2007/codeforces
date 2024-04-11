/*
    21.10.2018 11:46:11
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

typedef long long ll;

int main(int argc, char const *argv[]) {
    ll a, b;
    cin >> a >> b;
    ll mx = 0;
    ll s = 0;
    while (s <= a + b) {
        ++mx;
        s += mx;
    }
    s -= mx;
    --mx;
    vector< ll > toa, tob;
    ll sa = 0, sb = 0;
    for (ll i = mx; i > 0; --i) {
        if (sa + i <= a) {
            toa.push_back(i);
            sa += i;
        } else {
            tob.push_back(i);
            sb += i;
        }
    }
    reverse(toa.begin(), toa.end());
    reverse(tob.begin(), tob.end());
    cout << toa.size() << '\n';
    for (auto item : toa) {
        cout << item << ' ';
    }
    cout << '\n';
    cout << tob.size() << '\n';
    for (auto item : tob) {
        cout << item << ' ';
    }
    cout << '\n';
    return 0;
}