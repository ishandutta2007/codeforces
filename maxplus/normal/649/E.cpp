#define first f
#define second s
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

const int N = 200001;
int n, a, dlv, l, r, m;
pair<pair<int, int>, int> t[N];
multiset<int> es;
set<pair<int, int>> e;

int main()
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> n >> a;
    for (int i = 0; i < n; ++i)
        cin >> t[i].f.f >> t[i].f.s, t[i].f.s += t[i].f.f, t[i].s = i + 1;
    sort(t, t + n);
    l = 1, r = a + 1;
    while (r - l > 1)
    {
        m = (l + r) / 2 - 1;
        es.clear();
        dlv = 0;
        for (int i = 0; i < n; ++i)
        {
            while (!es.empty() && *es.begin() <= t[i].f.f)
                es.erase(es.begin()), ++dlv;
            if (es.size() < m)
                es.insert(t[i].f.s);
            else if (*es.rbegin() > t[i].f.s)
                es.erase(prev(es.end())),
                es.insert(t[i].f.s);
        }
        dlv += es.size();
        if (dlv >= a)
            r = m + 1;
        else
            l = m + 1;
    }
    cout << l << '\n';
    e.clear();
    int am = 0;
    for (int i = 0; i < n; ++i)
    {
        while (!e.empty() && e.begin()->f <= t[i].f.f)
            am++ < a? cout << e.begin()->s << ' ': cout, e.erase(e.begin());
        if (e.size() < l)
            e.insert({t[i].f.s, t[i].s});
        else if (e.rbegin()->f > t[i].f.s)
            e.erase(prev(e.end())),
            e.insert({t[i].f.s, t[i].s});
    }
    for (auto &i: e)
        am++ < a? cout << i.s << ' ': cout;
    return 0;
}