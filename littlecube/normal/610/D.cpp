/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma loop_opt(on)
#include <bits/extc++.h>
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
using namespace __gnu_pbds;

int n;
vector<pair<int, pii>> xseg, yseg, uxseg, uyseg;
vector<pii> in, out;
ll ans;

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
            yseg.emplace_back(make_pair(x1, pii{min(y1, y2), max(y1, y2)}));
        else
            xseg.emplace_back(make_pair(y1, pii{min(x1, x2), max(x1, x2)}));
    }
    sort(xseg.begin(), xseg.end());
    for (auto p : xseg)
    {
        if (!uxseg.empty() && uxseg.back().F == p.F && p.S.F <= uxseg.back().S.S)
            uxseg.back().S.S = max(uxseg.back().S.S, p.S.S);
        else
            uxseg.emplace_back(p);
    }
    sort(yseg.begin(), yseg.end());
    for (auto p : yseg)
    {
        if (!uyseg.empty() && uyseg.back().F == p.F && p.S.F <= uyseg.back().S.S)
            uyseg.back().S.S = max(uyseg.back().S.S, p.S.S);
        else
            uyseg.emplace_back(p);
    }
    for (auto p : uyseg)
    {
        in.emplace_back(make_pair(p.S.F, p.F));
        out.emplace_back(make_pair(p.S.S, p.F));
        ans += p.S.S - p.S.F + 1;
    }
    for (auto p : uxseg)
        ans += p.S.S - p.S.F + 1;
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> bst;

    // _ O _ O O _ _
    // 0 0 1 1 2 3 3
    int idx = 0, odx = 0, qdx = 0;
    while (idx < in.size() || odx < out.size() || qdx < uxseg.size())
    {
        int cur = min({(idx < in.size() ? in[idx].F : 1e9),
                       (odx < out.size() ? out[odx].F : 1e9),
                       (qdx < uxseg.size() ? uxseg[qdx].F : 1e9)});
        while (idx < in.size() && in[idx].F <= cur)
        {
            //cout << "in " << in[idx].S << '\n';
            bst.insert(in[idx].S);
            ++idx;
        }
        while (qdx < uxseg.size() && uxseg[qdx].F <= cur)
        {
            //for (int i : bst)
            //    cout << i << " ";
            //cout << '\n';
            //cout << "order[" << uxseg[qdx].S.S << "] = " << bst.order_of_key(uxseg[qdx].S.S) << ", "
            //     << "order[" << uxseg[qdx].S.F << "] = " << bst.order_of_key(uxseg[qdx].S.F) << "\n";
            ans -= bst.order_of_key(uxseg[qdx].S.S + 1) - bst.order_of_key(uxseg[qdx].S.F);
            qdx++;
        }
        while (odx < out.size() && out[odx].F <= cur)
        {
            //cout << "out " << out[odx].S << '\n';
            bst.erase(bst.find(out[odx].S));
            ++odx;
        }
    }
    cout << ans << '\n';
}

//   0 1 2 3 4
// 0
// 1 X X X
// 2   X
// 3 X X X
// 4   X