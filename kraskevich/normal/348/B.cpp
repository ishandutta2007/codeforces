#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e14;
const int N = 100 * 1000 + 10;

vector<int> g[N];
long long s[N];
long long f[N];
long long a[N];
vector<bool> u;
int n;

long long gcd(long long a, long long b)
{
    if (a < b)
        swap(a, b);
    return b ? gcd(b, a % b) : a;
}

long long _lcm(long long a, long long b)
{
    long long g = gcd(a, b);
    double aa = a / g;
    double bb = b;
    if (aa * bb > 1e14)
        return INF;
    return a / g * b;
}

long long mul(long long a, long long b)
{
    double aa = a;
    double bb = b;
    if (aa * bb > 1e14)
        return INF;
    return a * b;
}

long long get_lcm(vector<long long> &v)
{
    long long res = v[0];
    for (auto x: v)
    {
        res = _lcm(res, x);
        if (res == INF)
            break;
    }
    return res;
}

void dfs(int v)
{
    u[v] = true;
    vector<long long> cs;
    vector<long long> cf;
    for (auto to: g[v])
        if (!u[to])
        {
            dfs(to);
            cs.push_back(s[to]);
            cf.push_back(f[to]);
        }
    if (!cs.size())
    {
        s[v] = a[v];
        f[v] = 1;
        return;
    }
    long long low = *min_element(cs.begin(), cs.end());
    long long lcm = get_lcm(cf);
    long long have = low - low % lcm;
    s[v] = have * (long long)cs.size();
    f[v] = mul(lcm, (long long)cs.size());
}

int main()
{
    ios_base::sync_with_stdio(false);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    long long tot = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    u.assign(n, 0);
    dfs(0);

    cout << tot - s[0];

    return 0;
}