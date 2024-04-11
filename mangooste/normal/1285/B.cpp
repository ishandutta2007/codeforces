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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        ll sm = 0;
        for (auto &el : a)
            cin >> el, sm += el;
        vector<ll> pr;
        pr.pb(0);
        for (int i = 0; i < n; i++)
            pr.pb(pr.back() + a[i]);
        ll mx = pr[n];
        bool fnd = false;
        for (int i = n - 1; i > 0; i--) {
            fnd |= (mx - pr[i] >= sm);
            mx = max(mx, pr[i]);
        }
        mx = *max_element(pr.begin(), pr.end() - 1);
        fnd |= (mx >= sm);
        cout << (!fnd ? "Yes\n" : "No\n");
    }
}