#include <bits/stdc++.h>


using namespace std;


using vi = vector<int>;


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


const int MN = (int)2e3 + 5;


vi G[MN];
int orig_indeg[MN], indeg[MN], orig_p[MN], p[MN], num[MN];
bool done[MN];

void dfs(int cur, int bound)
{
    done[cur] = true;
    each(next, G[cur])
    {
        p[next] = min(p[next], bound);
        indeg[next]--;
        if (indeg[next] == 0)
            dfs(next, p[next]);
    }
}

bool valid(int n, int x, int k)
{
    bool res = true;
    FOR(i, 1, n + 1)
    {
        indeg[i] = orig_indeg[i];
        p[i] = orig_p[i];
        done[i] = false;
    }
    p[x] = k;
    FOR(i, 1, n + 1)
    {
        if (indeg[i] || done[i])
            continue;
        dfs(i, p[i]);
    }
    FOR(i, 1, n + 1)
    {
        num[i] = 0;
    }
    FOR(i, 1, n + 1)
    {
        num[p[i]]++;
    }
    int sum = 0;
    FOR(i, 1, n + 1)
    {
        sum += num[i];
        if (sum > i)
        {
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    FAST_IO;
    int n, m;
    cin >> n >> m;
    FOR(i, 1, n + 1)
    {
        cin >> orig_p[i];
    }
    F0R(i, m)
    {
        int a, b;
        cin >> a >> b;
        G[b].pb(a);
        orig_indeg[a]++;
    }
    FOR(i, 1, n + 1)
    {
        int s = 1, e = orig_p[i];
        while (s < e)
        {
            int m = (s + e) / 2;
            if (valid(n, i, m))
                e = m;
            else
                s = m + 1;
        }
        cout << s << ' ';
    }
}