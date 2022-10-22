#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lim = 1000000000000000007ll;
const int Maxn = 17;

int bits[1 << Maxn];
int n;
ll y;
int m;
int nd[Maxn];
ll dp[1 << Maxn];
int mypos[Maxn];
int res[Maxn];

ll Solve()
{
    dp[(1 << n) - 1] = 1;
    for (int i = (1 << n) - 2; i >= 0; i--) {
        dp[i] = 0;
        int ind = bits[i];
        int l = 0, r = n - 1;
        if (mypos[ind] != -1) l = r = mypos[ind];
        for (int j = l; j <= r; j++) 
            if (!(i & 1 << j) && (i & nd[j]) == nd[j])
                dp[i] = min(lim, dp[i] + dp[i | 1 << j]);
    }
    return dp[0];
}

int main()
{
    for (int i = 0; i < 1 << Maxn; i++)
        bits[i] = __builtin_popcount(i);
    scanf("%d %I64d %d", &n, &y, &m);
    y -= 2000;
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        a--; b--;
        nd[b] |= 1 << a;
    }
    fill(mypos, mypos + n, -1);
    if (Solve() < y)
        printf("The times have changed\n");
    else {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) if (mypos[j] == -1) {
                mypos[j] = i;
                ll got = Solve();
                if (y <= got) {
                    res[i] = j;
                    break;
                }
                y -= got;
                mypos[j] = -1;
            }
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i] + 1, i + 1 < n? ' ': '\n');
    }
    return 0;
}