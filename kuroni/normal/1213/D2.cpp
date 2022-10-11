#include <bits/stdc++.h>
using namespace std;

const int MX = 2E5 + 5;

int n, k, u;
long long ans = 1E18 + 7;
vector<int> ve[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        for (int j = 0; u > 0; j++, u /= 2) {
            ve[u].push_back(j);
        }
    }
    for (int i = 1; i < MX; i++) {
        if (ve[i].size() >= k) {
            sort(ve[i].begin(), ve[i].end());
            ans = min(ans, accumulate(ve[i].begin(), ve[i].begin() + k, 0LL));
        }
    }
    cout << ans;
}