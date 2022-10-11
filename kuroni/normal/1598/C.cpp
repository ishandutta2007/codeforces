#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (2 * sum % n != 0) {
            cout << "0\n";
        } else {
            long long tar = 2 * sum / n;
            long long ans = 0;
            map<int, int> ma;
            for (int i = 0; i < n; i++) {
                ans += ma[tar - a[i]];
                ma[a[i]]++;
            }
            cout << ans << '\n';
        }
    }
}