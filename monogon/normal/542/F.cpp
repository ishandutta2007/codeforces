
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// dp[H][N] = answer(height, num leaves)

const int N = 1005, TT = 105;
int n, T, t[N], q[N], dp[TT][N];
vector<int> nodes[TT];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> T;
    vector<pair<int, int>> ve;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> q[i];
        nodes[t[i]].push_back(q[i]);
    }
    for(int i = 1; i <= T; i++) {
        sort(nodes[i].rbegin(), nodes[i].rend());
    }
    for(int h = 1; h <= T; h++) {
        for(int i = 1; i <= n; i++) {
            int sum = 0;
            for(int k = 0; k <= min(i, (int) nodes[h].size()); k++) {
                if(k > 0) sum += nodes[h][k - 1];
                dp[h][i] = max(dp[h][i], sum + dp[h - 1][min(n, (i - k) * 2)]);
            }
        }
    }
    cout << dp[T][1] << endl;
}