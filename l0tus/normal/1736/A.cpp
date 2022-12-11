#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)

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
        int a[n], b[n], sum = 0;
        F0R(i, n)
        {
            cin >> a[i];
            sum += a[i];
        }
        F0R(i, n)
        {
            cin >> b[i];
            sum -= b[i];
        }
        int diff = 0;
        F0R(i, n)
        {
            if (a[i] != b[i])
                diff++;
        }
        cout << min(diff, abs(sum) + 1) << '\n';
    }
}