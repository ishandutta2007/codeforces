#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#define N 20001

using namespace std;

struct eevent{
    int t, s, num;
};

eevent tmp;
eevent me(int a, int b, int c)
{
    tmp.t = a, tmp.s = b, tmp.num = c;
    return tmp;
}

bool operator<(eevent a, eevent b)
{
    if (a.t != b.t)
        return a.t < b.t;
    return a.s < b.s;
}

void out()
{
    cout << "No solution";
    exit(0);
}

bool sc;
char c;
int col[N], lu[N];
vector<eevent> ev;

int main()
{
    int t, t0, n, m, T;
    memset(col, 255, sizeof(col));
    cin >> n >> m >> T;
    for (int i = 0; i < n; ++i)
    {
         cin >> t0 >> c >> t >> c; t0 = t0 * 60 + t; cin >> t; t += t0 * 60;
         ev.push_back(me(t, 1, i));
         ev.push_back(me(t + T, -1, i));
    }
    sort(ev.begin(), ev.end());
    int cp = 0, cc = 0, cop = 0, lc;
    for (; cp < ev.size() && cc < m; ++cp)
    {
        cop += ev[cp].s;
        if (ev[cp].s != 1)
            continue;
        lu[col[ev[cp].num] = lc = cc++] = ev[cp].num;
    }
    if (cc != m)
        out();
    if (cop == m)
        sc = 1;
    for (; cp < ev.size(); ++cp)
    {
        if (ev[cp].s != 1)
        {
            if (ev[cp].num == lu[col[ev[cp].num]])
                cop--;
            continue;
        }
        if (cop < m)
            lu[lc = col[ev[cp].num] = cc++] = ev[cp].num, cop++;
        else
            lu[col[ev[cp].num] = lc] = ev[cp].num;
        if (cop == m)
            sc = 1;
    }
    if (!sc)
        out();
    cout << cc << '\n';
    for (int i = 0; i < n; ++i)
        cout << col[i] + 1 << '\n';
    return 0;
}