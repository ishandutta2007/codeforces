#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Maxb = 63;

int n;
int mask[Maxn];
int maskforbit[Maxb];
ll val[Maxn];

ll Ask(int q)
{
    vector <int> seq;
    for (int i = 1; i <= n; i++)
        if (mask[i] & 1 << q)
            seq.push_back(i);
    if (seq.empty()) return 0;
    printf("? %d", int(seq.size()));
    for (int i = 0; i < seq.size(); i++)
        printf(" %d", seq[i]);
    printf("\n"); fflush(stdout);
    ll res; scanf("%I64d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        while (__builtin_popcount(cur) != 6) cur++;
        mask[i] = cur++;
    }
    for (int i = 0; i < 13; i++) {
        ll got = Ask(i);
        for (int j = 0; j < Maxb; j++)
            if (got & 1ll << ll(j))
                maskforbit[j] |= 1 << i;
    }
    for (int j = 0; j < Maxb; j++) if (maskforbit[j]) {
        int av = 1;
        while (av <= n && maskforbit[j] != mask[av]) av++;
        for (int i = 1; i <= n; i++) if (i != av)
            val[i] |= 1ll << ll(j);
    }
    printf("!");
    for (int i = 1; i <= n; i++)
        printf(" %I64d", val[i]);
    printf("\n");
    return 0;
}