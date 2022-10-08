
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5, K = 2520 * 2 + 5;
int t, n, x, y, z;
int dp[6][6][6][K][3];
ll a[N];

int mex(vector<int> &v) {
    sort(v.begin(), v.end());
    if(v[0] > 0) return 0;
    for(int i = 1; i < (int) v.size(); i++) {
        if(v[i] > v[i - 1] + 1) return v[i - 1] + 1;
    }
    return v.back() + 1;
}
inline int grundy(ll a, int j) {
    return dp[x][y][z][a < 2520 ? a : 2520 + (a % 2520)][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int x = 1; x <= 5; x++) {
        for(int y = 1; y <= 5; y++) {
            for(int z = 1; z <= 5; z++) {
                for(int i = 1; i < K; i++) {
                    vector<int> v = {dp[x][y][z][max(0, i - x)][0], dp[x][y][z][max(0, i - y)][1], dp[x][y][z][max(0, i - z)][2]};
                    dp[x][y][z][i][0] = mex(v);
                    v = {dp[x][y][z][max(0, i - x)][0], dp[x][y][z][max(0, i - z)][2]};
                    dp[x][y][z][i][1] = mex(v);
                    v = {dp[x][y][z][max(0, i - x)][0], dp[x][y][z][max(0, i - y)][1]};
                    dp[x][y][z][i][2] = mex(v);
                }
            }
        }
    }
    cin >> t;
    while(t--) {
        cin >> n >> x >> y >> z;
        int g = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            g ^= grundy(a[i], 0);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += ((g ^ grundy(a[i], 0) ^ grundy(max(a[i] - x, 0LL), 0)) == 0);
            ans += ((g ^ grundy(a[i], 0) ^ grundy(max(a[i] - y, 0LL), 1)) == 0);
            ans += ((g ^ grundy(a[i], 0) ^ grundy(max(a[i] - z, 0LL), 2)) == 0);
        }
        cout << ans << endl;
    }
}