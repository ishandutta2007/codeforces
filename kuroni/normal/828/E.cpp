#include <iostream>
#include <cstdio>
using namespace std;

string s, e;
char c;
int i, j, n, m, q, t, l, r, x, y, ans, bit[4][12][10][100005];

int cv(const char &ch)
{
    switch (ch)
    {
        case 'A': return 0; break;
        case 'T': return 1; break;
        case 'G': return 2; break;
        case 'C': return 3; break;
    }
}

void upd(int ch, int div, int mod, int u, int val)
{
    while (u <= n / div + 1)
    {
        bit[ch][div][mod][u] += val;
        u += u & -u;
    }
}

void upg(int pos, int ch, int val)
{
    for (int j = 1; j <= 10; j++)
        upd(ch, j, pos % j, pos / j + 1, val);
}

int que(int ch, int div, int mod, int u)
{
    int res = 0;
    while (u > 0)
    {
        res += bit[ch][div][mod][u];
        u -= u & -u;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie();
    cin >> s; n = s.size();
    for (i = 0; i < n; i++)
        upg(i, cv(s[i]), 1);
    cin >> q;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x >> c; --x;
            upg(x, cv(s[x]), -1);
            upg(x, cv(c), 1);
            s[x] = c;
        }
        else
        {
            cin >> l >> r >> e; ans = 0; --l; --r; j = e.size();
            x = l; m = x % j; y = (r - m) / j * j + m;
            for (i = 0; i < j; i++)
            {
                ans += que(cv(e[i]), j, m, y / j + 1) - que(cv(e[i]), j, m, x / j + 1) + (s[x] == e[i]);
                ++x; ++y; ++m;
                if (x > r)
                    break;
                if (y > r)
                    y -= j;
                m %= j;
            }
            cout << ans << '\n';
        }
    }
}