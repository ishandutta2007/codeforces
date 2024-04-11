#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const double eps = 1e-10;
const int N = 1111;
const int A = 10000;

double dp[A][N];

int main() {
#if FALSE
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    int k, q;
    cin >> k >> q;
    dp[0][0] = 1;
    for (int i = 1; i < A; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (k - j + 1)) / k;
    for (int i = 0; i < q; i++) {
        double x;
        cin >> x;
        int ans = k;
        while (dp[ans][k] < x / 2000. - eps)
            ans++;
        cout << ans << endl;
    }
}