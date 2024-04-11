#include <algorithm>
#include <cassert>
#include <cmath>
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

ll bin_pow(ll a, ll b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return a * bin_pow(a, b - 1);
    return bin_pow(a * a, b / 2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &el : a)
        cin >> el;
    map<ll, vector<int>> mapa;
    for (auto el : a) {
        for (ll i = 2; i * i <= el; i++)
            if (el % i == 0) {
                int cnt = 0;
                while (el % i == 0)
                    el /= i, cnt++;
                mapa[i].pb(cnt);
            }
        if (el != 1)
            mapa[el].pb(1);
    }
    ll ans = 1;
    for (auto el : mapa) {
        if (el.second.size() < n - 1)
            continue;        
        sort(all(el.second));
        if (el.second.size() == n) {
            ans *= bin_pow(el.first, el.second[1]);
            continue;
        }
        ans *= bin_pow(el.first, el.second[0]);
    }
    cout << ans << '\n';
}