#include <bits/stdc++.h>


using namespace std;


#define debug(...) 42


using ll = long long;


using vi = vector<int>;


#define sz(x) int((x).size())


#define pb push_back


#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)


#define each(a, x) for (auto &a : x)
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);


/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

/*
vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    while ((int)fact.size() < n + 1)
    {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}
*/
 // (int)1e9 + 7;


const int MN = (int)4000 + 5;
const ll INF = 1e9;

bool visited[MN], is_perfect[MN];
char s[MN][MN];
vi G[MN];
vi comp[MN];
int ord[MN], comp_size[MN];
// return size
void dfs(int idx, int s)
{
    comp[idx].pb(s);
    visited[s] = 1;
    each(e, G[s])
    {
        if (visited[e])
            continue;
        dfs(idx, e);
    }
}


int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        FOR(i, 1, n + 1)
        {
            visited[i] = 0;
            G[i].clear();
        }
        FOR(i, 1, n + 1)
        {
            FOR(j, 1, n + 1)
            {
                cin >> s[i][j];
                if (s[i][j] == '1' && i > j)
                {
                    G[i].pb(j);
                    G[j].pb(i);
                }
            }
        }
        int cnt = 0;
        FOR(i, 1, n + 1)
        {
            if (visited[i])
                continue;
            comp[cnt].clear();
            dfs(cnt, i);
            cnt++;
        }
        if (cnt == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        bool alone = false;
        FOR(i, 1, n + 1)
        {
            if (sz(G[i]) == 0)
            {
                alone = true;
                cout << 1 << '\n';
                cout << i << '\n';
                break;
            }
        }
        if (alone)
        {
            continue;
        }
        int sol = 0;
        F0R(i, cnt)
        {
            comp_size[i] = sz(comp[i]);
            ord[i] = 0;
            each(v, comp[i])
            {
                debug(G[v]);
                ord[i] += sz(G[v]);
            }
            debug(comp_size[i], ord[i]);
            is_perfect[i] = (ord[i] == comp_size[i] * (comp_size[i] - 1));
            if (!is_perfect[i])
            {
                int min_ord_idx = 0, min_ord = INF;
                each(v, comp[i])
                {
                    if (sz(G[v]) < min_ord)
                    {
                        min_ord_idx = v;
                        min_ord = sz(G[v]);
                    }
                }
                sol = min_ord_idx;
                break;
            }
        }
        if (sol)
        {
            debug(t, sol);
            cout << 1 << '\n';
            cout << sol << '\n';
            continue;
        }
        if (cnt > 2)
        {
            debug(t, "here");
            cout << 2 << '\n';
            cout << comp[0][0] << ' ' << comp[1][0] << '\n';
            continue;
        }
        if (is_perfect[0] && is_perfect[1])
        {
            cout << min(comp_size[0], comp_size[1]) << '\n';
            if (comp_size[0] <= comp_size[1])
            {
                each(v, comp[0])
                {
                    cout << v << ' ';
                }
            }
            else
            {
                each(v, comp[1])
                {
                    cout << v << ' ';
                }
            }
            cout << '\n';
        }
        else
        {
            cout << 2 << '\n';
            if (is_perfect[0])
                cout << comp[0][0] << ' ';
            else
            {
                each(v, comp[0])
                {
                    if (sz(G[v]) != comp_size[0] - 1)
                    {
                        cout << v << ' ';
                        break;
                    }
                }
            }
            if (is_perfect[1])
                cout << comp[1][0] << ' ';
            else
            {
                each(v, comp[1])
                {
                    if (sz(G[v]) != comp_size[1] - 1)
                    {
                        cout << v << ' ';
                        break;
                    }
                }
            }
            cout << '\n';
        }
    }
}