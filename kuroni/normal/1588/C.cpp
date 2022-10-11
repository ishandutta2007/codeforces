#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<long long, int> ma; ma[0] = 1;
        long long sum = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            int u; cin >> u;
            sum += ((i & 1) ? 1 : -1) * u;
            ans += ma[sum]++;
            if (i & 1) {
                while (!ma.empty() && prev(ma.end())->first > sum) {
                    ma.erase(prev(ma.end()));
                }
            } else {
                while (!ma.empty() && ma.begin()->first < sum) {
                    ma.erase(ma.begin());
                }
            }
        }
        cout << ans << '\n';
    }
}