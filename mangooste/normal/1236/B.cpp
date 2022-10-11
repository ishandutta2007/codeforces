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

const ll MOD = 1e9 + 7;

ll bin_pow(ll a, ll b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return (a * bin_pow(a, b - 1)) % MOD;
    return bin_pow((a * a) % MOD, b / 2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    ll pw = bin_pow(2ll, m) - 1;
    if (pw == -1)
        pw = MOD - 1;
    cout << bin_pow(pw, n) << '\n';
}