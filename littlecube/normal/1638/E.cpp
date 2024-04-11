/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

int N, Q;
ll bit[1000005];
map<int, ll, greater<int>> add[1000005];
map<pii, pii> arr;

void modify(int pos, ll val)
{
    //cout << "modify [" << pos << ", inf) " << val << '\n';
    if (pos == 0)
        return;
    for (int i = pos; i <= N; i += (i & -i))
        bit[i] += val;
}

ll query(int pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

signed main()
{
     fast;
    cin >> N >> Q;
    arr[{1, N}] = {1, 0};
    for (int i = 1; i <= N; i++)
        add[i][0] = 0;
    for (int i = 1; i <= Q; i++)
    {
        string s;
        ll l, r, c;
        cin >> s;
        if (s == "Color")
        {
            cin >> l >> r >> c;
            if (arr.find({l, r}) != arr.end())
            {
                auto iter = arr.find({l, r});
                ll m = add[iter->S.F].lower_bound(i)->S - add[iter->S.F].lower_bound(iter->S.S)->S;
                modify(l, m);
                modify(r + 1, -m);
                arr[{l, r}] = {c, i};
                continue;
            }
            auto iter = arr.lower_bound({l, N + 1});
            if (iter != arr.begin() && r <= prev(iter)->F.S)
            {
                iter = prev(iter);
                ll m = add[iter->S.F].lower_bound(i)->S - add[iter->S.F].lower_bound(iter->S.S)->S;
                modify(l, m);
                modify(r + 1, -m);
                if (iter->F.F <= l - 1)
                    arr[{iter->F.F, l - 1}] = iter->S;
                if (r + 1 <= iter->F.S)
                    arr[{r + 1, iter->F.S}] = iter->S;
                arr.erase(iter);
                arr[{l, r}] = {c, i};
                continue;
            }
            iter = arr.lower_bound({l, 0});
            while (iter != arr.end() && iter->F.S <= r)
            {
                ll m = add[iter->S.F].lower_bound(i)->S - add[iter->S.F].lower_bound(iter->S.S)->S;
                modify(iter->F.F, m);
                modify(iter->F.S + 1, -m);
                arr.erase(iter);
                iter = arr.lower_bound({l, 0});
            }

            if (iter != arr.begin() && l <= prev(iter)->F.S)
            {
                iter = prev(iter);
                ll m = add[iter->S.F].lower_bound(i)->S - add[iter->S.F].lower_bound(iter->S.S)->S;
                modify(l, m);
                modify(iter->F.S + 1, -m);
                arr[{iter->F.F, l - 1}] = iter->S;
                arr.erase(iter);
            }
            iter = arr.lower_bound({l, 0});
            if (iter != arr.end() && iter->F.F <= r)
            {
                ll m = add[iter->S.F].lower_bound(i)->S - add[iter->S.F].lower_bound(iter->S.S)->S;
                modify(iter->F.F, m);
                modify(r + 1, -m);
                arr[{r + 1, iter->F.S}] = iter->S;
                arr.erase(iter);
            }
            arr[{l, r}] = {c, i};
        }
        else if (s == "Add")
        {
            cin >> c >> l;
            auto iter = add[c].begin();
            add[c][i] = iter->S + l;
            //for (auto [j, k] : add[c])
            //    cout << "[" << j << "] = " << k << " ";
            //cout << '\n';
        }
        else if (s == "Query")
        {
            cin >> l;
            auto iter = prev(arr.upper_bound({l, N}));
            ll m = add[iter->S.F].lower_bound(i)->S - add[iter->S.F].lower_bound(iter->S.S)->S;
            // cout << m << '\n';
            cout << m + query(l) << '\n';
        }

        //for (auto [p, q] : arr)
        //    cout << "[" << p.F << ", " << p.S << "] = color " << q.F << " time " << q.S << "\n";
        //for (int i = 1; i <= N; i++)
        //    cout << query(i) << " \n"[i == N];
        // cout << '\n';
    }
}