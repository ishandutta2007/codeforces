#include <bits/stdc++.h>


using namespace std;


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


const int MN = 105;


char b[MN][MN];
vi G[MN], R[MN];
int ord[MN], n;
bool done[MN];
int exist[MN][MN];
vi ans[MN];
void remove(int i)
{
    done[i] = true;
    exist[i][i] = 1;
    each(j, R[i])
    {
        F0R(k, n)
        {
            exist[i][k] |= exist[j][k];
        }
    }
    F0R(k, n)
    {
        if (exist[i][k])
            ans[i].pb(k + 1);
    }
    each(j, G[i])
    {
        ord[j]--;
    }
    each(j, G[i])
    {
        if (ord[j])
            continue;
        if (!done[j])
            remove(j);
    }
}
int main()
{
    FAST_IO;
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        F0R(i, n)
        {
            done[i] = false;
            ord[i] = 0;
            ans[i].clear();
            G[i].clear();
            R[i].clear();
            F0R(k, n)
            {
                exist[i][k] = 0;
            }
        }
        F0R(i, n)
        {
            F0R(j, n)
            {
                cin >> b[i][j];
                if (b[i][j] == '1')
                {
                    G[i].pb(j);
                    R[j].pb(i);
                    ord[j]++;
                }
            }
        }
        F0R(i, n)
        {
            if (ord[i])
                continue;
            if (!done[i])
                remove(i);
        }
        F0R(i, n)
        {
            cout << sz(ans[i]) << ' ';
            each(x, ans[i])
            {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}