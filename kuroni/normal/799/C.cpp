#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, C, D; cin >> n >> C >> D;
    vector<vector<pair<int, int>>> ve(2);
    for (int i = 0; i < n; i++) {
        int b, d;
        char t;
        cin >> b >> d >> t;
        ve[t == 'D'].push_back({d, b});
    }
    sort(ve[0].begin(), ve[0].end());
    sort(ve[1].begin(), ve[1].end());
    int ans = 0;
    // C and D
    {
        int ac = numeric_limits<int>::min() / 3, ad = numeric_limits<int>::min() / 3;
        for (int i = 0; i < ve[0].size(); i++) {
            if (ve[0][i].first <= C) {
                ac = max(ac, ve[0][i].second);
            }
        }
        for (int i = 0; i < ve[1].size(); i++) {
            if (ve[1][i].first <= D) {
                ad = max(ad, ve[1][i].second);
            }
        }
        ans = max(ans, ac + ad);
    }
    // C and C
    {
        int ac = numeric_limits<int>::min() / 3;
        vector<int> prf(ve[0].size());
        for (int i = 0; i < ve[0].size(); i++) {
            prf[i] = (i == 0 ? ve[0][i].second : max(ve[0][i].second, prf[i - 1]));
        }
        for (int pt = 0, i = (int)ve[0].size() - 1; i > 0; i--) {
            for (; pt < ve[0].size() && ve[0][pt].first + ve[0][i].first <= C; pt++) {
            }
            if (pt > 0) {
                ans = max(ans, ve[0][i].second + prf[min(i, pt) - 1]);
            }
        }
    }
    // C and C
    {
        vector<int> prf(ve[1].size());
        for (int i = 0; i < ve[1].size(); i++) {
            prf[i] = (i == 0 ? ve[1][i].second : max(ve[1][i].second, prf[i - 1]));
        }
        for (int pt = 0, i = (int)ve[1].size() - 1; i > 0; i--) {
            for (; pt < ve[1].size() && ve[1][pt].first + ve[1][i].first <= D; pt++) {
            }
            if (pt > 0) {
                ans = max(ans, ve[1][i].second + prf[min(i, pt) - 1]);
            }
        }
    }
    cout << ans << '\n';
}