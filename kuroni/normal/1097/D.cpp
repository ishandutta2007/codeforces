#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
using namespace std;

const int MX = 64, MOD = 1E9 + 7;

long long n, inv[MX];
int q;

vector<pair<long long, long long>> cur, pro, ans = {{1, 1}};

void reduce(long long u)
{
    long long pw = 1;
    cur = {{pw, 0}};
    pro.clear();
    while (n % u == 0)
    {
        cur.push_back({(pw *= u % MOD) %= MOD, 0});
        n /= u;
    }
    cur.back().se = 1;
    for (int i = 1; i <= q; i++)
        for (int j = 0; j < cur.size(); j++)
        {
            for (int k = 0; k < j; k++)
                (cur[k].se += cur[j].se * inv[j + 1]) %= MOD;
            (cur[j].se *= inv[j + 1]) %= MOD;
        }
    for (pair<long long, long long> &u : ans)
        for (pair<long long, long long> &v : cur)
            pro.push_back({u.fi * v.fi % MOD, u.se * v.se % MOD});
    ans.swap(pro);
}

int main()
{
    inv[1] = 1;
    for (int i = 2; i < MX; i++)
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    scanf("%lld%d", &n, &q);
    for (int i = 2; 1LL * i * i <= n; i++)
        if (n % i == 0)
            reduce(i);
    if (n > 1)
        reduce(n);
    long long ret = 0;
    for (pair<long long, long long> &v : ans)
        (ret += v.fi * v.se) %= MOD;
    printf("%lld", ret);
}