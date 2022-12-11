#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
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
        int a[n + 2];
        a[0] = a[n + 1] = 1;
        FOR(i, 1, n + 1)
        cin >> a[i];
        bool poss = 1;
        FOR(i, 1, n + 1)
        {
            if (gcd(lcm(a[i], a[i - 1]), lcm(a[i], a[i + 1])) != a[i])
                poss = 0;
        }
        if (poss)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}