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

int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char a[n << 1];
        F0R(i, n << 1)
        {
            cin >> a[i];
        }
        bool prev = 0;
        vi b;
        F0R(i, n)
        {
            if (a[i << 1] != a[i << 1 | 1])
            {
                if (a[i << 1] - '0' == prev)
                    b.pb(i << 1 | 1);
                else
                    b.pb(i << 1);
                prev = !prev;
            }
        }
        if (prev)
        {
            cout << "-1\n";
            continue;
        }
        cout << sz(b) << ' ';
        each(x, b) cout << x + 1 << ' ';
        cout << '\n';
        F0R(i, n)
        {
            cout << (i << 1 | 1) << ' ';
        }
        cout << '\n';
    }
}