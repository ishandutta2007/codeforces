#include <bits/stdc++.h>
using namespace std;

const int N = 505, MX = 1E6 + 5, M = 1005, MOD = 998244353;

int n, m, le[N], ri[N], a[MX], pos[M], eve[M];
long long ans[M][M];
bool chk[M][M];

long long find_ans(int l, int r)
{
    if (chk[l][r])
        return ans[l][r];
    chk[l][r] = true;
    int mi = N, ma = 0;
    for (int i = l; i <= r; i++)
    {
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
    }
    if (mi >= ma)
        return ans[l][r] = 1;
    long long lv = 0, rv = 0;
    for (int su = 0, i = l; i <= le[mi]; i++)
    {
        if (su == 0)
            (lv += find_ans(l, i - 1) * find_ans(i, le[mi] - 1)) %= MOD;
        su += eve[i];
    }
    for (int su = 0, i = r; i >= ri[mi]; i--)
    {
        if (su == 0)
            (rv += find_ans(ri[mi] + 1, i) * find_ans(i + 1, r)) %= MOD;
        su += eve[i];
    }
    ans[l][r] = lv * rv % MOD;
    for (int i = le[mi] + 1, pt = le[mi] + 1, su = 0; i <= ri[mi] - 1; i++)
    {
        su += eve[i];
        if (su == 0 && (pos[i] != pos[i + 1] - 1 || i == ri[mi] - 1))
        {
            (ans[l][r] *= find_ans(pt, i)) %= MOD;
            pt = i + 1;
        }
    }
    return ans[l][r];
}

bool check()
{
    set<int, greater<int>> se;
    for (int i = 1; i <= m; i++)
    {
        if (le[a[i]] == i)
            se.insert(a[i]);
        if (*se.begin() != a[i])
            return false;
        if (ri[a[i]] == i)
            se.erase(a[i]);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        if (le[a[i]] == 0)
            le[a[i]] = i;
        ri[a[i]] = i;
    }
    if (!check())
        return cout << 0, 0;
    m = 0;
    for (int i = 1; i <= n; i++)
    {
        pos[++m] = le[i];
        pos[++m] = ri[i];
    }
    sort(pos + 1, pos + m + 1);
    m = distance(pos + 1, unique(pos + 1, pos + m + 1));
    for (int i = 1; i <= n; i++)
    {
        le[i] = distance(pos + 1, upper_bound(pos + 1, pos + m + 1, le[i]));
        ri[i] = distance(pos + 1, upper_bound(pos + 1, pos + m + 1, ri[i]));
        eve[le[i]] += i; eve[ri[i]] -= i;
        a[le[i]] = a[ri[i]] = i;
    }
    cout << find_ans(1, m);
}