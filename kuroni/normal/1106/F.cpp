#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

const int MOD = 998244353, K = 105, G = 3, INV = 332748118;

int n, m, des;
map<long long, int> ma;

struct SMatrix
{
    int m, n;
    long long f[K][K];

    SMatrix operator*(const SMatrix &b)
    {
        SMatrix ans;
        ans.m = m; ans.n = b.n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < b.n; j++)
            {
                ans.f[i][j] = 0;
                for (int k = 0; k < n; k++)
                    (ans.f[i][j] += f[i][k] * b.f[k][j]) %= (MOD - 1);
            }
        return ans;
    }

    SMatrix operator^(const int &b)
    {
        SMatrix ans = *this;
        for (int i = 30 - __builtin_clz(b); i >= 0; i--)
        {
            ans = ans * ans;
            if (b >> i & 1)
                ans = ans * (*this);
        }
        return ans;
    }
} ori, bas;

pair<long long, long long> euclid(int a, int b)
{
    if (b == 0)
        return make_pair(1, 0);
    pair<long long, long long> tmp = euclid(b, a % b);
    return make_pair(tmp.second, tmp.first - tmp.second * (a / b));
}

long long gcd(int a, int b)
{
    pair<long long, long long> tmp = euclid(a, b);
    return tmp.first * a + tmp.second * b;
}

int pw(int u)
{
    (u += MOD - 1) %= (MOD - 1);
    long long ret = 1;
    for (int i = 31 - __builtin_clz(u); i >= 0; i--)
    {
        (ret *= ret) %= MOD;
        if (u >> i & 1)
            (ret *= G) %= MOD;
    }
    return ret;
}

int get(long long des)
{
    int d = sqrt(MOD - 1) + 1;
    long long inv = 1, cur = 1;
    for (int i = 0; i < d; i++)
    {
        ma[cur] = i;
        (cur *= G) %= MOD;
        (inv *= INV) %= MOD;
    }
    for (int i = 0; i < d; i++)
        if (ma.find(des) != ma.end())
            return i * d + ma[des];
        else        
            (des *= inv) %= MOD;
}

int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%lld", &bas.f[i][0]);
    scanf("%d%d", &n, &des);
    for (int i = 1; i < m; i++)
        bas.f[i - 1][i] = 1;
    bas.m = bas.n = m;
    ori.m = 1; ori.n = m; ori.f[0][0] = 1;
    ori = ori * (bas ^ (n - m));
    int c = get(des), k = ori.f[0][0], tmp = gcd(k, c);
    if (tmp == 0)
        return printf("1"), 0;
    c /= tmp; k /= tmp;
    if (gcd(k, MOD - 1) > 1)
        return printf("-1"), 0;
    else
        printf("%d", pw(euclid(k, MOD - 1).first % (MOD - 1) * c % (MOD - 1)));
}