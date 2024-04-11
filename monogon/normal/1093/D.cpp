#pragma GCC optimize("O3")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
using ll = long long int;
using ld = long double;
#define pq_min priority_queue<ll, vector<ll>, greater<ll>>
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> // s.erase(s.upper_bound(x)) to erase elements
#define MOD 1000000007
#define mod 998244353
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

void init_code()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ll power(ll a, ll b, ll m = MOD)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = 1ll * ans * a % m;
        a = 1ll * a * a % m;
        b >>= 1;
    }
    return ans;
}

ll fast_pow(int b, int p)
{
    if (p == 0)
        return 1;
    else if (p == 1)
        return b;
    else
    {
        ll r = fast_pow(b, p / 2);
        if (p % 2 == 0)
            return (r * r) % MOD;
        else
            return (((r * r) % MOD) * b) % MOD;
    }
}

class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        iota(begin(parent), end(parent), 0);
    }

    int getParent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = getParent(parent[x]);
    }

    bool join(int x, int y)
    {
        x = getParent(x);
        y = getParent(y);

        if (x == y)
            return false;

        if (size[x] > size[y])
            swap(x, y);

        parent[x] = y;
        size[y] += size[x];
        return true;
    }

    int getSize(int x)
    {
        return size[x] = size[getParent(x)];
    }
};

vector<int> primes;
bool prime[10000001 + 1];
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;

    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}

ll __lcm(ll a, ll b)
{
    ll gcd = __gcd(a, b);
    return (a * b) / gcd;
}

// Read and try to understand every single test case
// Divide test cases into cases. Almost every test case is there for a reason.
// Taking more time than expected? Open paint and start writing
// Still can't find a pattern? Write a bruteforce and look for a pattern there.
// Try to minimize code for A and B. It will almost always have a simple solution.
// __builtin_popcount(x): the number of ones in the bit representation
const int N = int(3e5) + 999;
vector<ll> edges[N];
int col[N];
bool bad;
ll c[2];

void dfs(int v, int co)
{
    col[v] = co;
    c[co]++;

    for (auto u : edges[v])
    {
        if (col[u] == -1)
            dfs(u, co ^ 1);
        if (col[u] == col[v])
            bad = true;
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        edges[i].clear(), col[i] = -1;
    bad = false;

    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    ll ans = 1;

    for (int i = 1; i <= n; i++)
    {
        if (col[i] != -1)
            continue;

        c[0] = c[1] = 0;
        dfs(i, 0);

        if (bad)
        {
            cout << 0 << "\n";
            return;
        }

        ans = (ans * ((power(2ll, c[0], mod) + power(2ll, c[1], mod)) % mod)) % mod;
    }

    cout << ans << "\n";
}

int main()
{
    init_code();
    cout << fixed;

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}