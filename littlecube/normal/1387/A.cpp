#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

pll Plus(pll p1, pll p2)
{
    return pll{p1.F + p2.F, p1.S + p2.S};
}

pll Minus(pll p1, pll p2)
{
    return pll{p1.F - p2.F, p1.S - p2.S};
}

// ax + b = k
pair<int, ld> solve(pll p, ll k)
{
    if (p.F == 0 && p.S == k)
        return pair<int, ld>{0, 0};
    else if (p.F == 0)
        return pair<int, ld>{2, 0};
    else
        return pair<int, ld>{1, (ld)(k - p.S) / (ld)(p.F)};
}

ll N, M, pre[100005];
bool vis[100005];
vector<pll> E[100005];
vector<int> point;
pll val[100005];
ld res[100005];
pair<int, ld> sol = {0, 0};

void dfs(int k)
{
    vis[k] = 1;
    point.emplace_back(k);
    for (auto p : E[k])
        if (!vis[p.F])
        {
            pre[p.F] = k;
            val[p.F] = Minus(pll{0, p.S}, val[k]);
            dfs(p.F);
        }
        else
        {
            pair<int, ld> newsol = solve(Plus(val[k], val[p.F]), p.S);
            if (sol.F == 1 && newsol.F == 1)
            {
                if (abs(sol.S - newsol.S) >= 0.00001)
                    sol = pair<int, ld>{2, 0};
            }
            else
                sol = max(sol, newsol);
        }
}

signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        E[x].emplace_back(pll{y, c});
        E[y].emplace_back(pll{x, c});
    }

    for (int i = 1; i <= N; i++)
        if (!vis[i])
        {
            sol = {0, 0};
            val[i] = pll{1, 0};
            point.clear();
            dfs(i);

            if (sol.F == 0)
            {
                vector<ld> v;
                for (int i : point)
                {
                    assert(abs(val[i].F) == 1);
                    if (val[i].F > 0)
                        v.emplace_back((-val[i].S));
                    else if (val[i].F < 0)
                        v.emplace_back((ld)(val[i].S));
                }
                sort(v.begin(), v.end());

                ll median = (v.size()) / 2;
                ld final;
                if (!v.empty())
                    final = v[median];
                if (v.empty())
                    final = 0;
                for (int i : point)
                    res[i] = final * val[i].F + val[i].S;
            }
            else if (sol.F == 1)
            {
                for (int i : point)
                    res[i] = sol.S * val[i].F + val[i].S;
            }
            else if (sol.F == 2)
            {
                cout << "NO\n";
                return 0;
            }
        }
    cout << fixed << setprecision(18);

    cout << "YES\n";
    for (int i = 1; i <= N; i++)
        cout << res[i] << " \n"[i == N];
}