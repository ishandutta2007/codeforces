#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll X;
    cin >> X;
    ll a = 1, b = X;
    for (ll i = 2; i * i <= X; i++) {
        if (X % i)
            continue;
        ll cur_a = i;
        ll cur_b = X / i;
        ll lcm = cur_a / __gcd(cur_a, cur_b) * cur_b;
        if (cur_b < b && lcm == X)
            a = cur_a, b = cur_b;
    }
    cout << a << ' ' << b << '\n';
}