#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 16;
const int S = 256;

int dp[1 << N][S];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<bool> red(n);
    int totA = 0;
    int totB = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s >> a[i] >> b[i];
        totA += a[i];
        totB += b[i];
        red[i] = (s == "R");    
    }
    for (int mask = 0; mask < (1 << n); mask++)
        for (int s = 0; s < S; s++)
            dp[mask][s] = -1;
    dp[0][0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int A = 0;
        int B = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) {
                if (red[i])
                    A++;
                else
                    B++;
            }
        for (int s = 0; s < S; s++) {
            if (dp[mask][s] == -1)
                continue;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    continue;
                int newS = s + min(A, a[i]);
                int newV = dp[mask][s] + min(B, b[i]);
                dp[mask | (1 << i)][newS] = max(dp[mask | (1 << i)][newS], newV);                             
            }                        
        }    
    }
    int res = totA + totB;
    for (int s = 0; s < S; s++) {
        if (dp[(1 << n) - 1][s] == -1)
            continue;
        res = min(res, max(totA - s, totB - dp[(1 << n) - 1][s])); 
    }
    cout << res + n << endl;
}