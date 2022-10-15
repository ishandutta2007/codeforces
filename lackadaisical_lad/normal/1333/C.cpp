#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <bitset>
#include <queue>
#include <random>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), kek(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        kek[i] = (i ? kek[i - 1] : 0) + a[i];
    }
    set<ll> pref;
    int j = 0;
    ll sum = 0;
    ll ans = 0;
    pref.insert(0);
    for (int i = 0; i < n; i++) {
        while (j < n && !pref.count(sum + a[j])) {
            sum += a[j];
            pref.insert(sum);
            j++;
        }
        ans += j - i;
        pref.erase(i ? kek[i - 1] : 0);
    }
    cout << ans << endl;
    return 0;
}