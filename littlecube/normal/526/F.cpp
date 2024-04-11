/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

int N, arr[300005], pos[300005], lazy[600005];
pii seg[600005];
ll ans;

pii merge(pii p1, pii p2)
{
    pii ans = {min(p1.F, p2.F), 0};
    if (p1.F == ans.F)
        ans.S += p1.S;
    if (p2.F == ans.F)
        ans.S += p2.S;
    return ans;
}

pii getval(int i)
{
    return {seg[i].F + lazy[i], seg[i].S};
}

void init(int i = 1, int L = 1, int R = N)
{
    seg[i] = {0, R - L + 1};
    if (L != R)
    {
        int mid = (L + R) / 2;
        init(i + 1, L, mid);
        init(i + 2 * (mid - L + 1), mid + 1, R);
    }
}

void modify(int mL, int mR, int val, int i = 1, int L = 1, int R = N)
{
    //cout << "modify " << mL << " " << mR << " " << i << " " << L << " " << R << '\n';
    if (mL <= L && R <= mR)
        lazy[i] += val;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        lazy[i + 1] += lazy[i];
        lazy[i + 2 * (mid - L + 1)] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, i + 1, L, mid);
        modify(mL, mR, val, i + 2 * (mid - L + 1), mid + 1, R);
        seg[i] = merge(getval(i + 1), getval(i + 2 * (mid - L + 1)));
    }
}

pii query(int qL, int qR, int i = 1, int L = 1, int R = N)
{
    //cout << "query " << qL << " " << qR << " " << i << " " << L << " " << R << '\n';

    if (qL <= L && R <= qR)
        return getval(i);
    else if (R < qL || qR < L)
        return {1e9, 0};
    else
    {
        int mid = (L + R) / 2;
        seg[i] = getval(i);
        lazy[i + 1] += lazy[i];
        lazy[i + 2 * (mid - L + 1)] += lazy[i];
        lazy[i] = 0;
        return merge(query(qL, qR, i + 1, L, mid), query(qL, qR, i + 2 * (mid - L + 1), mid + 1, R));
    }
}

signed main()
{
    fast;
    cin >> N;
    init();
    for (int i = 1; i <= N; i++)
    {
        int u, v;
        cin >> u >> v;
        pos[u] = v;
        arr[v] = u;
    }
    arr[0] = arr[N + 1] = N + 1;
    for (int i = 1; i <= N; i++)
    {
        int val = (arr[pos[i] - 1] > i ? 1 : -1) + (arr[pos[i] + 1] > i ? 1 : -1);
        modify(i, N, val);
        //cout << i << " = " << val << '\n';
    }

    for (int i = 1; i <= N; i++)
    {
        pii res = query(i, N);
        //cout << i << " " << N << " = " << res.F << " " << res.S << '\n';
        if (res.F == 2)
        {
            ans += (ll)res.S;
        }
        modify(i, N, -2);
        if (arr[pos[i] - 1] > i)
            modify(arr[pos[i] - 1], N, 2);

        if (arr[pos[i] + 1] > i)
            modify(arr[pos[i] + 1], N, 2);
    }
    cout << ans << '\n';
}