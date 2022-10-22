#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 400;
const int Maxm = (Maxn + 1) * Maxn / 2;

int dp[Maxm][Maxn];
int n, m;
int st[Maxn];
int a[Maxn];
ll res;

int Get(int s, int t) { return st[s] + t - s; }

int main()
{
    scanf("%d %d", &n, &m);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        st[i] = cur;
        cur += n - i;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++)
            dp[Get(i, i)][j] = 0;
        for (int j = i + 1; j < n; j++) {
            int k = i + 1;
            for (int z = n - 1; z > 0; z--) {
                dp[Get(i, j)][z] = max(a[k] - a[i], dp[Get(k, j)][z - 1]);
                while (k + 1 <= j && a[k + 1] - a[i] <= dp[Get(k + 1, j)][z - 1])
                    k++;
                dp[Get(i, j)][z] = min(dp[Get(i, j)][z], max(a[k] - a[i], dp[Get(k, j)][z - 1]));
                if (k + 1 <= j)
                    dp[Get(i, j)][z] = min(dp[Get(i, j)][z],
                                           max(a[k + 1] - a[i], dp[Get(k + 1, j)][z - 1]));
            }
            dp[Get(i, j)][0] = a[j] - a[i];
        }
    }
    while (m--) {
        int s, f, c, r; scanf("%d %d %d %d", &s, &f, &c, &r);
        s--; f--;
        r = min(r, n - 1);
        res = max(res, ll(dp[Get(s, f)][r]) * c);
    }
    cout << res << endl;
    return 0;
}