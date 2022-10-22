#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n, mod, k;
map <int, int> M;
ll res;

int main()
{
    scanf("%d %d %d", &n, &mod, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        int cand = ll(a) * a % mod * a % mod * a % mod;
        cand = (cand - ll(a) * k % mod + mod) % mod;
        res += M[cand]++;
    }
    printf("%I64d\n", res);
    return 0;
}