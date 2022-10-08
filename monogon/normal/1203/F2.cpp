
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 105, MAX_R = 60005;
int n, r, a, b;
vector<pair<int, int> > inc, d;
int dp[MAX_R][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> r;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(b >= 0) {
            inc.push_back({a, b});
        }else {
            d.push_back({max(a, -b) + b, b});
        }
    }
    sort(inc.begin(), inc.end());
    sort(d.begin(), d.end());
    int proj = 0;
    for(auto p : inc) {
        if(r >= p.first) {
            proj++;
            r += p.second;
        }
    }
    int len = d.size();
    for(int i = 0; i <= len; i++) {
        if(i == 0) {
            for(int j = 0; j <= r; j++) {
                dp[j][i] = proj;
            }
            continue;
        }
        int a = d[i - 1].first - d[i - 1].second;
        int b = d[i - 1].second;
        for(int j = 0; j <= r; j++) {
            if(j >= a) {
                dp[j][i] = max(dp[j][i - 1], 1 + dp[j + b][i - 1]);
            }else {
                dp[j][i] = dp[j][i - 1];
            }
        }
    }
    cout << dp[r][len] << endl;
}