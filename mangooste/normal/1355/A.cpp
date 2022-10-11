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
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, k;
        cin >> a >> k;
        bool was = false;
        while (--k) {
            ll mn = 10, mx = 0;
            ll val = a;
            while (val) {
                ll dg = val % 10;
                mn = min(mn, dg);
                mx = max(mx, dg);
                val /= 10;
            }
            if (mn == 0)
                break;
            a += mn * mx;
        }
        cout << a << '\n';
    }
}