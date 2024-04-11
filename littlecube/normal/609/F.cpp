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
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;  

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int N, M, s[200005];
pll x[200005], ans[200005];

set<pll> frog;
set<pll> mosquito;

signed main()
{
    //fast;
    cin >> N >> M;

    vector<pll> v;
    for (int i = 1; i <= N; i++)
    {
        cin >> x[i].F >> x[i].S;
        ans[i].S = x[i].S;
        v.pb(make_pair(x[i].F, i));
    }

    sort(v.begin(), v.end());

    for (auto i : v)
    {
        if (frog.empty())
            frog.insert(i);
        else
        {
            pll p = *prev(frog.end());
            if (p.F + x[p.S].S >= i.F + x[i.S].S)
                continue;
            else if (p.F + x[p.S].S >= i.F)
            {
                x[i.S].S -= (p.F + x[p.S].S + 1) - x[i.S].F;
                x[i.S].F = p.F + x[p.S].S + 1;
                frog.insert(make_pair(x[i.S].F, i.S));
            }
            else
                frog.insert(i);
        }
    }

    for (int i = 1; i <= M; i++)
    {

        int p, b, id;
        cin >> p >> b;

        auto iter = frog.upper_bound(make_pair(p, 1e18));

        if (iter == frog.begin())
            continue;
        --iter;

        //if (iter != frog.end())
        id = iter->S;

        if (/*iter != frog.end() &&*/ x[id].F + x[id].S >= p)
        {
            //cout << "eaten " << id << "\n";
            x[id].S += b;
            ans[id].F += 1;
            ans[id].S += b;

            auto bound = mosquito.lower_bound(make_pair(x[id].F, -1));
            while (bound != mosquito.end() && bound->F <= x[id].F + x[id].S)
            {
                //cout << "additional eaten " << bound->F << " " << bound->S << "\n";
                b = s[bound->S];
                x[id].S += b;
                ans[id].F += 1;
                ans[id].S += b;
                mosquito.erase(bound);
                bound = mosquito.lower_bound(make_pair(x[id].F, -1));
            }

            //cout << "edit iter\n";
            frog.erase(iter);
            frog.insert(make_pair(x[id].F, id));

            iter = frog.lower_bound(make_pair(x[id].F, id));

            while (next(iter) != frog.end() && iter->F + x[iter->S].S >= next(iter)->F)
            {
                int nxt = next(iter)->S;
                int newx = iter->F + x[iter->S].S + 1;
                x[nxt].S -= newx - x[nxt].F;
                x[nxt].F = newx;
                frog.erase(next(iter));
                if (x[nxt].S >= 0)
                    frog.insert(make_pair(x[nxt].F, nxt));
            }
        }
        else
        {
            //cout << "not eaten\n";
            mosquito.insert(make_pair(p, i));
            s[i] = b;
        }
        //for (pii j : frog)
        //{
        //    int id = j.S;
        //    //cout << "(" << id << ": " << j.F << ", " << x[id].S << ") ";
        //}
        //cout << '\n';
    }
    for (int i = 1; i <= N; i++)
        cout << ans[i].F << " " << ans[i].S << '\n';
}