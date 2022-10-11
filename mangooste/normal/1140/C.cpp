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
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for (auto &el : a)
        cin >> el.first >> el.second;
    sort(all(a), [](pii &a, pii &b) {
        return a.second < b.second;
    });
    ll ans = 0;
    multiset<ll> best;
    ll sm = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll len = sm + a[i].first;
        ans = max(ans, len * a[i].second);
        best.insert(a[i].first);
        sm += a[i].first;
        if (best.size() > k - 1) {
            sm -= *best.begin();
            best.erase(best.begin());
        }
    }
    cout << ans << '\n';
}