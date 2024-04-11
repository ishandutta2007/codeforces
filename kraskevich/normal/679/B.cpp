#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef pair<ll, ll> pll;

ll cube(ll x) {
    return x * x * x;
}

pll solve(ll x) {
    if (x == 0)
        return pll(0, 0);
    ll r = (ll) pow(x, 1.0 / 3.0);
    while (cube(r) <= x)
        r++;
    while (cube(r) > x)
        r--;
    pll res1 = solve(x - cube(r));
    pll res2;
    if (r > 1)
        res2 = solve(cube(r) - 1 - cube(r - 1));
    res1.first++;
    res2.first++;
    res1.second += cube(r);
    res2.second += cube(r - 1);
    return max(res1, res2); 
}

int main() {
    ios_base::sync_with_stdio(0);
    ll x;
    cin >> x;
    pll res = solve(x);
    cout << res.first << " " << res.second << endl;
    return 0;
}