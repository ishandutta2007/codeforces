#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 555;

int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int len = 1; len <= n; len++)
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            bool pal = true;
            int L = l;
            int R = r;
            while (L < R) {
                if (a[L] != a[R])
                    pal = false;
                L++;
                R--;
            }
            if (pal)
                dp[l][r] = 1;
            else
                dp[l][r] = len;
            if (len > 2 && a[l] == a[r])
                dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
            for (int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
        }
    cout << dp[0][n - 1] << endl;
}