#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000006;
const int mod = 1000000007;

int pw2[Maxn];
int n, k;
char str[Maxn];
int B[Maxn], W[Maxn], X[Maxn];
int dp[Maxn];
deque <ii> D;
int all;
int res;

int Get(int A[], int l, int r)
{
    return A[r] - A[l - 1];
}

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    scanf("%d %d", &n, &k);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        B[i] += B[i - 1];
        W[i] += W[i - 1];
        X[i] += X[i - 1];
        if (str[i] == 'B') B[i]++;
        else if (str[i] == 'W') W[i]++;
        else X[i]++;
    }
    all = 1;
    D.push_back(ii(n + 1, 1));
    for (int i = n; i >= 1; i--) {
        int cur = all;
        // W
        if (str[i] == 'W' || str[i] == 'X') {
            while (!D.empty() && D[0].first - i >= k) {
                all = (all - D[0].second + mod) % mod;
                D.pop_front();
            }
        } else {
            D.clear();
            all = 0;
        }
        // B
        if (str[i] == 'B' || str[i] == 'X') {
            D.push_back(ii(i, cur));
            all = (all + cur) % mod;
        }
        dp[i] = (pw2[Get(X, i, n)] - all + mod) % mod;
    }
    D.clear();
    all = 1;
    D.push_back(ii(0, 1));
    for (int i = 1; i <= n; i++) {
        int cur = all;
        // B
        if (str[i] == 'B' || str[i] == 'X') {
            while (!D.empty() && i - D[0].first >= k) {
                res = (res + ll(D[0].second) * dp[i + 1]) % mod;
                all = (all - D[0].second + mod) % mod;
                D.pop_front();
            }
        } else {
            D.clear();
            all = 0;
        }
        // W
        if (str[i] == 'W' || str[i] == 'X') {
            D.push_back(ii(i, cur));
            all = (all + cur) % mod;
        }
    }
    printf("%d\n", res);
    return 0;
}