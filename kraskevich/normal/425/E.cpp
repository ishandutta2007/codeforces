#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const int MOD = 1000 * 1000 * 1000 + 7;
const int N = 505;

int old[N][N];
int now[N][N];
int pw[N];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            old[i][j] = 0;
    old[0][0] = 1;
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = pw[i - 1] * 2 % MOD;
    for (int pos = 1; pos <= n; pos++)
    {
        memset(now, 0, sizeof(now));
        for (int cnt = 0; cnt <= k; cnt++)
            for (int last = 0; last < pos; last++) {
                now[last][cnt] = (now[last][cnt] + old[last][cnt] * 1ll * pw[last]) % MOD;
                now[pos][cnt + 1] = (now[pos][cnt + 1] + old[last][cnt] * 1ll * (pw[pos - last] - 1 + MOD) % MOD * pw[last]) % MOD;
            }
        memcpy(old, now, sizeof(now));
    }
    long long res = 0;
    for (int last = 0; last <= n; last++)
        res += old[last][k], res %= MOD;

    cout << res;

    return 0;
}