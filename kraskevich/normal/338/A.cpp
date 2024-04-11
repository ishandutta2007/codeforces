#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000 * 1000 * 1000 + 9;
long long n, m, k, f;

bool can(long long cnt)
{
    long long pref = k * cnt + k - 1;
    if (pref >= m)
        return true;
    long long have = n - pref;
    long long sep = have / k;
    if (have % k)
        sep++;
    return sep <= f;
}

long long bpow(long long b, long long x)
{
    long long res = 1;
    while (x > 0)
    {
        if (x % 2)
            res = res * b % MOD;
        b = b * b % MOD;
        x /= 2;
    }
    return res;
}
long long solve(long long cnt)

{
    long long res = bpow(2, cnt + 1);
    res -= 2;
    res += MOD;
    res %= MOD;
    res *= k;
    res %= MOD;
    long long l = m - k * cnt;
    res += l;
    res %= MOD;
    return res;

}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    cin >> n >> m >> k;
    f = n - m;
    long long l = 0;
    long long r = 1000 * 1000 * 1000;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (can(mid))
            r = mid;
        else
            l = mid + 1;
    }
    //cerr << l << endl;
    cout << solve(l);

    return 0;
}