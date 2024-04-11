#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

int n, m, a, b, deg, st, ban[101];
vector<int> nei[101], nban;

void add(int a, int b)
{
    nei[a].pb(b), nei[b].pb(a);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a >> b, add(--a, --b);
    while (1)
    {
        for (int i = 0; i < n; ++i) if (!ban[i])
        {
            deg = 0;
            for (auto j: nei[i]) if (!ban[j])
                deg++;
            if (deg == 1)
                nban.pb(i);
        }
        for (auto i: nban)
            ban[i] = 1;
        if (!nban.size())
            break;
        nban.clear();
        st++;
    }
    cout << st;
    return 0;
}