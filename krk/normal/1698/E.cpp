#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int T;
int n, s;
int a[Maxn];
int b[Maxn];
int oth[Maxn];

int Solve()
{
    int res = 1;
    int pnt = 1, q = 0;
    for (int i = 1; i <= n; i++) {
        while (pnt <= min(i + s, n)) {
            q += int(b[pnt] == -1);
            pnt++;
        }
        if (oth[i] == -1) {
            res = ll(res) * q % mod;
            q = (q - 1 + mod) % mod;
        } else if (oth[i] > s + i) return 0;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &s);
        fill(oth, oth + n + 1, -1);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) {
            int val; scanf("%d", &val);
            b[a[i]] = val;
            if (val != -1) oth[val] = a[i];
        }
        printf("%d\n", Solve());
    }
    return 0;
}