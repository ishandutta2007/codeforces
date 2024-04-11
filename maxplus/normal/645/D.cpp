#define first f
#define second s
#include <iostream>
#include <vector>
#define all(a) a.begin(), a.end()
#define pb push_back

using namespace std;

const int N = 100002, sqn = 317;
int n, m, a, b, w[N], l[N], def, u[N], t;
pair<int, int> q[N];
vector<int> ord;
vector<int> nei[N], pnei[N];

void ts(int v)
{
    u[v] = t;
    for (auto i: nei[v]) if (u[i] != t)
        ts(i);
    ord.pb(v);
}

bool check()
{
    ++t;
    ord.clear();
    int k = 1;
    for (int i = 1; i <= n; ++i) if (u[i] != t)
    {
        ts(i);
        while (k < n && k < ord.size())
        {
            int f = 0;
            for (auto j: nei[ord[k]])
                if (j == ord[k - 1])
                {
                    f = 1;
                    break;
                }
            if (!f)
                return 0;
            ++k;
        }
    }
    return 1;
}

void apply(int i)
{
    nei[q[i].f].pb(q[i].s);
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    int nxt = max(n - 3, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> q[i].f >> q[i].s;
        apply(i);
        if (i == nxt || i == m - 1)
        {
            if (i == nxt)
                nxt += sqn;
            if (!check())
                for (int i = 1; i <= n; ++i)
                    pnei[i] = nei[i];
            else
            {
                for (int i = 1; i <= n; ++i)
                    nei[i] = pnei[i];
                int j = max(nxt - sqn - sqn + 1, 0);
                while (!check())
                    apply(j++);
                return cout << j, 0;
            }
        }
    }
    cout << -1;
    return 0;
}