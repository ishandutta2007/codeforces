#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100 * 1000 + 10;
const int M = 17 * 2;

vector<int> mul;
int dp[N][M + 1];

int safe_mul(ll a, ll b) {
    return min(a * b, (ll)N - 1);
}

int solve(int s1, int s2, int e1, int e2) {
    int m = mul.size();
    for (int i = 0; i < N; i++)
        fill(dp[i], dp[i] + m + 1, 0);
    dp[s1][0] = s2;
    for (int pos = 0; pos < m; pos++)
        for (int x = s1; x < N; x++) {
            dp[x][pos + 1] = max(dp[x][pos + 1], safe_mul(dp[x][pos], mul[pos]));
            int y = safe_mul(mul[pos], x);
            dp[y][pos + 1] = max(dp[y][pos + 1], dp[x][pos]);
        }
    for (int pos = 0; pos <= m; pos++)
        for (int x = e1; x < N; x++)
            if (dp[x][pos] >= e2)
                return pos;
    return m + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int a, b, h, w;
    cin >> a >> b >> h >> w;
    int n;
    cin >> n;
    mul.resize(n);
    for (int i = 0; i < n; i++)
        cin >> mul[i];
    sort(mul.rbegin(), mul.rend());
    if (mul.size() > M)
        mul.resize(M);
    int ans = min(solve(h, w, a, b), solve(w, h, a, b));
    if (ans > (int)mul.size())
        ans = -1;
    cout << ans << endl;
}