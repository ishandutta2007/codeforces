#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>

using ll = long long;
using namespace std;

// #define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

vector<ll> a, b;
map<ll, int> mapa;
vector<char> used;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    a.resize(n);
    forn(i, n) {
        cin >> a[i];
        mapa[a[i]]++;
    }
    b.resize(n);
    forn(i, n) cin >> b[i];
    ll ans = 0;
    used.resize(n);
    for (auto i : mapa) if (i.second > 1) {
        forn(j, n) if (!used[j]) {
            if ((i.first & a[j]) == a[j]) ans += b[j], used[j] = 1;
        }
    }
    cout << ans << '\n';
}