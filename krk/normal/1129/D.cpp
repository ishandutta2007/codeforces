#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 100005;
const int Maxp = 320;

int n, k;
int a[Maxn];
int lst[Maxn];
int my[Maxn];
int res[Maxn], cur[Maxn];
int all;
int has[Maxp][Maxn], add[Maxp];

void Update(int ind, int delt)
{
    int p = ind / Maxp;
    int old = cur[ind] + add[p];
    has[p][cur[ind]] = (has[p][cur[ind]] - res[ind] + mod) % mod;
    cur[ind] += delt;
    has[p][cur[ind]] = (has[p][cur[ind]] + res[ind]) % mod;
    int nw = cur[ind] + add[p];
    if (nw <= k && old > k)
        all = (all + res[ind]) % mod;
    else if (nw > k && old <= k)
        all = (all - res[ind] + mod) % mod;
}

void Update(int l, int r, int delt)
{
    while (l % Maxp != 0 && l <= r) {
        Update(l, delt);
        l++;
    }
    while ((r + 1) % Maxp != 0 && l <= r) {
        Update(r, delt);
        r--;
    }
    if (l <= r) {
        int to = r / Maxp;
        if (delt > 0)
            for (int i = l / Maxp; i <= to; i++) {
                if (add[i] <= k) all = (all - has[i][k - add[i]] + mod) % mod;
                add[i]++;
            }
        else for (int i = l / Maxp; i <= to; i++) {
            add[i]--;
            if (add[i] <= k) all = (all + has[i][k - add[i]]) % mod;
        }
    }
} 

int main()
{
    scanf("%d %d", &n, &k);
    res[1] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        my[i] = lst[a[i]]; lst[a[i]] = i;
        has[i / Maxp][0] = (has[i / Maxp][0] + res[i]) % mod;
        all = (all + res[i]) % mod;
        Update(my[i] + 1, i, 1);
        if (my[i])
            Update(my[my[i]] + 1, my[i], -1);
        res[i + 1] = all;
    }
    printf("%d\n", res[n + 1]);
    return 0;
}