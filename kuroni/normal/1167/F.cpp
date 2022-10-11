#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500005, MOD = 1E9 + 7;

int n, a[N];
long long ans = 0, cur = 0;
vector<int> ve;

struct TBIT
{
    int bit[N];

    void upd(int u, int v)
    {
        for (; u <= n; u += u & -u)
            (bit[u] += v) %= MOD;
    }

    int que(int u)
    {
        int ret = 0;
        for (; u > 0; u -= u & -u)
            (ret += bit[u]) %= MOD;
        return ret;
    }
} bas, sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ve.push_back(a[i]);
    }
    sort(ve.begin(), ve.end());
    for (int i = 1; i <= n; i++)
    {
        int pos = distance(ve.begin(), upper_bound(ve.begin(), ve.end(), a[i]));
        int ini = bas.que(pos - 1);
        (cur += 1LL * (i + ini) * a[i]) %= MOD;
        (cur += sum.que(n) - sum.que(pos)) %= MOD;
        bas.upd(pos, i);
        sum.upd(pos, 1LL * i * a[i] % MOD);
        (ans += cur) %= MOD;
    }
    cout << (ans + MOD) % MOD << '\n';
}