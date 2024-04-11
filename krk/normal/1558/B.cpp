#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 4000005;

int n, mod;
int delt[Maxn];

int main()
{
    scanf("%d %d", &n, &mod);
    delt[1] = 1; delt[2] = mod - 1;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur = (cur + delt[i]) % mod;
        if (i == n) {
            printf("%d\n", cur);
            return 0;
        }
        delt[i + 1] = (delt[i + 1] + cur) % mod;
        for (int j = 2; i * j <= n; j++) {
            int from = i * j, to = i * j + j;
            delt[from] = (delt[from] + cur) % mod;
            if (to <= n) delt[to] = (delt[to] - cur + mod) % mod;
        }
    }
    return 0;
}