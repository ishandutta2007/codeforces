#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> b(n);
    for (ll &i : b)
        cin >> i;
    vector<ll> a(n);
    a[0] = b[0];
    ll cur_max = a[0];
    for (int i = 1; i < n; i++) {
        a[i] = cur_max + b[i];
        cur_max = max(cur_max, a[i]);
    }
    for (ll i : a)
        cout << i << ' ';
    cout << '\n';   
}