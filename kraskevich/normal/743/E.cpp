#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1111;
const int M = 256;
const int INF = (int)1e9;

int dp[N][M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> diff;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i]; 
        diff.insert(a[i]);
    }   
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < M; j++)
            dp[i][j] = -INF;
    vector<int> cnt(8);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        for (int j = 0; j < 8; j++)
            dp[i + 1][1 << j] = cnt[j];    
    }                          
    for (int i = 1; i < n; i++) {
        for (int m = 1; m < M; m++) {
            dp[i + 1][m] = max(dp[i + 1][m], dp[i][m]);
            int k = __builtin_popcount(m);
            if (dp[i][m] <= 0)
                continue;
            int low = dp[i][m] / k;
            vector<int> cnt(8);
            for (int r = i; r < n; r++) {
                int c = a[r];
                cnt[c]++;
                if (m & (1 << c))
                    continue;
                int cur = cnt[c];
                if (cur < low)
                    dp[r + 1][m | (1 << c)] = max(dp[r + 1][m | (1 << c)], (cur + 1) * k + cur);
                else
                    dp[r + 1][m | (1 << c)] = max(dp[r + 1][m | (1 << c)], dp[i][m] + min(low + 1, cur));                       
            }
        }            
    }
    int res = max(dp[n][M - 1], int(diff.size()));
    cout << res << endl;
}