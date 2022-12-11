#include <bits/stdc++.h>


using namespace std;


using ll = long long;


using vl = vector<ll>;


#define bg(x) begin(x)
#define all(x) bg(x), end(x)


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
    int n;
    cin >> n;
    vl a(n), b(n), sum(n);
    F0R(i, n)
    {
        cin >> a[i];
    }
    F0R(i, n)
    {
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    F0R(i, n)
    {
        sum[i] = b[i] + (i ? sum[i - 1] : 0);
    }

    ll total = 0, potential = 0;
    int idx = 0;
    F0R(i, n)
    {
        while (idx < n && a[i] > b[idx])
            idx++;
        total += (a[i] * idx - (idx ? sum[idx - 1] : 0)) + ((sum[n - 1] - (idx ? sum[idx - 1] : 0)) - a[i] * (n - idx));
        potential += abs(a[i] - b[i]);
    }
    ll ans = potential + total - potential * n;
    cout << ans;
}