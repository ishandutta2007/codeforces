#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int q, t, k, b, s;
long long n, it = 0, ss = 0, sb = 0, sk = 0;
bool fro = true, bac = false;
pair<long long, long long> ans = mp(0, 0);

struct SLine
{
    long long a, b;

    SLine(long long _a = 0, long long _b = 0)
    {
        a = _a;
        b = _b;
    }

    double intersect(SLine oth)
    {
        return 1.0 * (oth.b - b) / (a - oth.a);
    }

    long long at(long long x)
    {
        return a * x + b;
    }
};
vector<SLine> con;

void push(SLine u)
{
    while (con.size() >= 2 && con[con.size() - 2].intersect(u) >= con[con.size() - 2].intersect(con.back()))
        con.pop_back();
    con.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> k;
            ans = min(ans, mp(0LL, 0LL));
            sk += k;
            fro = true;
        }
        else if (t == 2)
        {
            cin >> k;
            ans = min(ans, mp(0LL, n));
            sk += k;
            bac = true;
        }
        else
        {
            cin >> b >> s;
            if (fro)
            {
                con.clear();
                push(SLine(0LL, 0LL));
                ss = s;
                sb = b;
            }
            else
            {
                if (bac)
                    push(SLine(n, -ss * n - sb));
                ss += s;
                sb += b;
            }
            while (con.size() >= 2 && con[con.size() - 1].at(ss) >= con[con.size() - 2].at(ss))
                con.pop_back();
            fro = bac = false;
            n += sk;
            sk = 0;
            ans = mp(con.back().at(ss) + sb, con.back().a);
        }
        cout << ans.se + 1 << " " << ans.fi << '\n';
    }
}