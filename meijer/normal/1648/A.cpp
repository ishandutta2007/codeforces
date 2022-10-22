#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MX = 1e5+10;

vector<int> difx[MX], dify[MX];

signed main() {
    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x; cin >> x;
            difx[x].push_back(i);
            dify[x].push_back(j);
        }
    }
    int ans = 0;
    for (int i=0; i<MX; i++) {
        for (auto& v : vector<vector<int>>({difx[i], dify[i]})) {
            sort(v.begin(), v.end());
            for (int j=0; j<v.size(); j++) {
                ans += j * v[j];
                ans -= (v.size() - j - 1) * v[j];
            }
        }
    }
    cout << ans << endl;
}