#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d; cin >> n >> d;
    int ans = 0;
    vector<tuple<int, int, int>> ve;
    while (n--) {
        int s, a; cin >> s >> a;
        ve.push_back({max(a, s), min(a, s), a});
    }
    sort(ve.begin(), ve.end());
    for (auto [mx, mi, a] : ve) {
        int s = mi ^ mx ^ a;
        if (s >= d) {
            ans++;
            d = max(d, a);
        }
    }
    cout << ans;
}