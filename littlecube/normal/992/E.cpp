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
//#define int long long
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

#define LOCAL

const int C = 30;
vector<pll> seg[400005];
ll lazy[400005], N, Q, arr[200005], pre[200005];

pll operator+(pll p, ll d)
{
    return pll{p.F + d, p.S};
}

void pull(int i, int l, int r)
{
    int lp = 0, rp = 0;
    seg[i].clear();
    while (seg[i].size() < C && (lp < seg[l].size() || rp < seg[r].size()))
    {
        if (rp >= seg[r].size())
        {
            seg[i].emplace_back(seg[l][lp] + lazy[l]);
            lp++;
        }
        else if (lp >= seg[l].size())
        {
            seg[i].emplace_back(seg[r][rp] + lazy[r]);
            rp++;
        }
        else if (seg[l][lp] + lazy[l] > seg[r][rp] + lazy[r])
        {
            seg[i].emplace_back(seg[l][lp] + lazy[l]);
            lp++;
        }
        else
        {
            seg[i].emplace_back(seg[r][rp] + lazy[r]);
            rp++;
        }
    }
}

void modify(int mL, int mR, ll val, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        lazy[i] += val;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2, l = i + 1, r = i + 2 * (mid - L + 1);
        lazy[l] += lazy[i];
        lazy[r] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, l, L, mid);
        modify(mL, mR, val, r, mid + 1, R);
        pull(i, l, r);
    }
}

void build(int i = 1, int L = 1, int R = N)
{
    if (L == R)
        seg[i] = vector<pll>{pll{0, L}};
    else
    {
        int mid = (L + R) / 2, l = i + 1, r = i + 2 * (mid - L + 1);
        build(l, L, mid);
        build(r, mid + 1, R);
        pull(i, l, r);
    }
}

void debug(int i = 1, int L = 1, int R = N)
{
    //printf("%d : [%d, %d] = ", i, L, R);
    //for (pll p : seg[i])
    //    printf("([%lld]%lld) ", p.S, p.F + lazy[i]);
    //cout << '\n';
    if (L != R)
    {
        int mid = (L + R) / 2, l = i + 1, r = i + 2 * (mid - L + 1);
        debug(l, L, mid);
        debug(r, mid + 1, R);
    }
}

signed main()
{
    fast;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= N; i++)
        pre[i] = pre[i - 1] + arr[i];
    for (int i = 1; i <= N; i++)
        modify(i, i, arr[i] * 2 - pre[i]);
    build();
    for (int i = 1; i <= Q; i++)
    {
        ll p, x;
        cin >> p >> x;
        modify(p, p, x - arr[p]);
        modify(p + 1, N, arr[p] - x);
        arr[p] = x;
        if (arr[1] == 0)
            cout << 1 << '\n';
        else
        {
            bool found = false;
            for (auto [j, pos] : seg[1])
                if (j + lazy[1] == 0)
                {
                    cout << pos << '\n';
                    found = 1;
                    break;
                }
            if (!found)
                cout << -1 << '\n';
        }
    }
}