#include <bits/stdc++.h>


using namespace std;


#define debug(...) 42


using ll = long long;
using db = long double;


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


const int MN = (int)5e3 + 5;
const ll INF = 1e9;

struct contract
{
    db x, cost, value;
};

bool cmp(contract a, contract b)
{
    return a.x < b.x;
}

db dp[MN][MN];
int main()
{
    FAST_IO;
    fixed(cout);
    cout.precision(9);
    int n, k;
    cin >> n >> k;
    vector<contract> v(n + 1);
    FOR(i, 1, n + 1)
    {
        cin >> v[i].x >> v[i].cost >> v[i].value;
    }
    sort(v.begin() + 1, v.end(), cmp);
    each(p, v)
    {
        debug(p.x);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = -v[i].cost;
        for (int j = 1; j < i; j++)
        {
            dp[i][i] = max(dp[i][i], dp[i - 1][j] + (db)(v[i].value + v[j].value) * (v[i].x - v[j].x) * k / 200 - v[i].cost);
            dp[i][j] = dp[i - 1][j];
        }
        dp[i][0] = dp[i - 1][0];
    }
    db ans = -INF;
    F0R(i, n + 1)
    {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}