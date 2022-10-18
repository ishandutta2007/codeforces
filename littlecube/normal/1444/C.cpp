/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
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

int n, m, k, a[500005], idx[500005], cc[500005], cnt, ccid = 1, ccdsu[500005], ccinv[500005];
bool notbipart[500005];
vector<pii> e;
vector<pii> ae;
vector<int> sg[500005];
vector<int> ccdsuval[500005];

void Merge(int from, int to, int inv)
{
    ccdsu[from] = to;
    while (!ccdsuval[from].empty())
    {
        ccinv[ccdsuval[from].back()] ^= inv;
        ccdsuval[to].pb(ccdsuval[from].back());
        ccdsuval[from].pop_back();
    }
}

int Find(int k)
{
    return k == ccdsu[k] ? k : Find(ccdsu[k]);
}

void dfs(int p)
{
    //cout << "DFS " << p << " " << idx[p] << '\n';
    int nxtidx = (idx[p] == 0 ? 1 : 0);
    for (int i : sg[p])
    {
        if (!cc[i])
        {
            cc[i] = ccid;
            idx[i] = nxtidx;
            dfs(i);
        }
        if (idx[i] == idx[p])
            notbipart[a[p]] = 1;
        //cout << "Not Bipart : " << a[p] << " " << notbipart[a[p]] << '\n';
    }
}

signed main()
{
    fast;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ccdsu[i] = i;
        ccdsuval[i] = vector<int>{i};
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (a[x] > a[y])
            swap(x, y);
        if (a[x] != a[y])
        {
            e.pb(make_pair(x, y));
            ae.pb(make_pair(a[x], a[y]));
        }
        else
        {
            sg[x].pb(y);
            sg[y].pb(x);
        }
    }
    sort(ae.begin(), ae.end(), [&](pii p1, pii p2) { return p1 < p2; });
    sort(e.begin(), e.end(), [&](pii p1, pii p2) { return pii{a[p1.F], a[p1.S]} > pii{a[p2.F], a[p2.S]}; });
    ae.resize(unique(ae.begin(), ae.end()) - ae.begin());

    for (int i = 1; i <= n; i++)
        if (!cc[i])
        {
            idx[i] = 1;
            cc[i] = ccid;
            dfs(i);
            ccid++;
        }

    //for (int i = 1; i <= n; i++)
    //    cout << cc[i] << " \n"[i == n];
    //for (int i = 1; i <= n; i++)
    //    cout << idx[i] << " \n"[i == n];
    //for (int i = 1; i <= k; i++)
    //    cout << notbipart[i] << " \n"[i == k];

    int notbipartcnt = 0;
    for (int i = 1; i <= k; i++)
        if (notbipart[i])
            notbipartcnt++;

    //cout << "Not Bipart Graph Counter: " << notbipartcnt << '\n';

    cnt = (k - notbipartcnt) * (k - notbipartcnt - 1) / 2;

    for (auto p : ae)
    {
        int i = p.F, j = p.S;

        if (notbipart[i] || notbipart[j])
        {
            while (!e.empty() && a[e.back().F] == i && a[e.back().S] == j)
                e.pop_back();
            continue;
        }

        bool b = 1;
        vector<int> redo;
        while (!e.empty() && a[e.back().F] == i && a[e.back().S] == j)
        {
            int x = e.back().F, y = e.back().S, rx = Find(cc[x]), ry = Find(cc[y]);
            //cout << "Dealing " << x << " " << y << '\n';
            if (rx == ry)
            {
                if ((idx[x] ^ ccinv[cc[x]]) == (idx[y] ^ ccinv[cc[y]]))
                    b = 0;
            }
            else
            {
                //cout << " - Merging " << rx << " " << ry << '\n';
                redo.pb(rx);
                redo.pb(ry);
                int inv = ((idx[x] ^ ccinv[cc[x]]) == (idx[y] ^ ccinv[cc[y]]));
                if (ccdsuval[rx].size() > ccdsuval[ry].size())
                    Merge(ry, rx, inv);
                else
                    Merge(rx, ry, inv);
            }
            e.pop_back();
        }
        for (int k : redo)
        {
            ccdsu[k] = k;
            ccdsuval[k] = vector<int>{k};
            //ccinv[k] = 0;
        }
        //cout << "Validate " << i << " " << j << '\n';
        if (!b)
            cnt--;
        //else
        //    cout << "Success\n";
    }

    cout << cnt << '\n';
}