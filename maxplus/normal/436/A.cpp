#include <iostream>
#include <set>
#define f first
#define s second

using namespace std;

typedef multiset<pair<int, int>> mspi;
multiset<pair<int, int>> p[2];
typedef multiset<int> msi;
msi c[2];
int ans, n, x, t, h, m;

void eat(mspi* p, msi* c, int ct, int ce, int cp)
{
    for (auto i = p[ct].begin(); i != p[ct].end();)
    {
        if (i->f > cp)
            break;
        c[ct].insert(i->s);
        i = p[ct].erase(i);
    }
    if (c[ct].empty())
        return ans = max(ans, ce), void();
    cp += *c[ct].rbegin();
    c[ct].erase(prev(c[ct].end()));
    ct = !ct;
    return eat(p, c, ct, ce + 1, cp);
}

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> t >> h >> m;
        p[t].insert({h, m});
    }
    mspi np[2];
    np[0] = p[0], np[1] = p[1];
    eat(np, (new msi[2]), 0, 0, x);
    np[0] = p[0], np[1] = p[1];
    eat(np, (new msi[2]), 1, 0, x);
    cout << ans;
    return 0;
}