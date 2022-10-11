#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const long long INF = 9223372036854775807LL, MOD = 1LL << 32;

long long t, mi, pos, n, l, r, x, y, z, ans;
unsigned long long b[3];
vector<long long> ve;

void add(long long x)
{
    // neg and pos
    if (x <= 0)
        mi = min(mi, x);
    else if (mi <= 0)
        ans = min(ans, mi * x);

    // pos and pos
    if (x > 0)
    {
        if (pos > 0 && x > pos)
            ans = min(ans, x * pos);
        else
            pos = x;
    }

    // neg and neg
    if (x <= 0)
    {
        while (!ve.empty() && ve.back() < x)
        {
            ans = min(ans, x * ve.back());
            ve.pop_back();
        }
        if (ve.empty() || ve.back() != x)
            ve.push_back(x); 
    }
}

void init()
{
    ans = INF;
    ve.clear();
    mi = 1;
    pos = -1;
}

void solve()
{
    init();
    cin >> n >> l >> r >> x >> y >> z >> b[0] >> b[1];
    add(b[0] % (r - l + 1) + l);
    add(b[1] % (r - l + 1) + l);
    for (int i = 3; i <= n; i++)
    {
        b[2] = (b[0] * x + b[1] * y + z) % MOD;
        add(b[2] % (r - l + 1) + l);
        b[0] = b[1];
        b[1] = b[2];
    }
    if (ans == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans << '\n';
}

int main()
{
    cin >> t;
    while (t--)
        solve();
}