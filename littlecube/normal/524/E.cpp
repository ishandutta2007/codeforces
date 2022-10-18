/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct Q
{
    int i, x1, x2, y1, y2;
};
struct P
{
    int x, y;
};

int n, m, k, q, seg[400000], ans[200005];
vector<P> point;
vector<Q> query;

void Modify(int l, int r, int i, int pos, int val)
{
    if (l == r)
        seg[i] = val;
    else
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
            Modify(l, mid, i * 2, pos, val);
        else
            Modify(mid + 1, r, i * 2 + 1, pos, val);
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
}

int Query(int l, int r, int i, int a, int b)
{
    if (a <= l && r <= b)
        return seg[i];
    else if (b < l || r < a)
        return 100000000;
    else
    {
        int mid = (l + r) / 2;
        return min(Query(l, mid, i * 2, a, b), Query(mid + 1, r, i * 2 + 1, a, b));
    }
}

signed main()
{
    fast;
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        point.emplace_back(P{x, y});
    }
    for (int i = 1; i <= q; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        query.emplace_back(Q{i, x1, x2, y1, y2});
    }

    sort(query.begin(), query.end(), [](Q q1, Q q2) { return q1.x2 < q2.x2; });
    sort(point.begin(), point.end(), [](P p1, P p2) { return p1.x < p2.x; });

    for (int i = 1, pi = 0, qi = 0; i <= n; i++)
    {
        while (pi < k && point[pi].x == i)
        {
            Modify(1, m, 1, point[pi].y, i);
            pi++;
        }
        while (qi < q && query[qi].x2 == i)
        {
            if (Query(1, m, 1, query[qi].y1, query[qi].y2) >= query[qi].x1)
                ans[query[qi].i] = 1;
            qi++;
        }
    }
    for (int i = 1; i < 400000; i++)
        seg[i] = 0;
    
    sort(query.begin(), query.end(), [](Q q1, Q q2) { return q1.y2 < q2.y2; });
    sort(point.begin(), point.end(), [](P p1, P p2) { return p1.y < p2.y; });

    for (int i = 1, pi = 0, qi = 0; i <= m; i++)
    {
        while (pi < k && point[pi].y == i)
        {
            Modify(1, n, 1, point[pi].x, i);
            pi++;
        }
        while (qi < q && query[qi].y2 == i)
        {
            if (Query(1, n, 1, query[qi].x1, query[qi].x2) >= query[qi].y1)
                ans[query[qi].i] = 1;
            qi++;
        }
    }
    for (int i = 1; i <= q;i++)
        if(ans[i])
            puts("YES");
        else
            puts("NO");
}