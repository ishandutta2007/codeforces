#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define f first
#define s second
#define N 100002
#define lgN 20

using namespace std;

int n, a[N];
pair<int, int> nxt[lgN][N];
vector<pair<int, int>> st;

void prec()
{
    int nxt[2] = {-1, -1};
    for (int i = n - 1; i >= 0; --i)
        ::nxt[0][i].f = nxt[0], ::nxt[0][i].s = nxt[1], nxt[a[i]] = i;
//    ::nxt[0][n].f = ::nxt[0][n].s = -1;
    for (int d = 1; d < lgN; ++d)
        for (int i = 0; i < n; ++i)
        {
            if (::nxt[d - 1][i].f != -1)
                ::nxt[d][i].f = ::nxt[d - 1][::nxt[d - 1][i].f].f;
            else
                ::nxt[d][i].f = -1;
            if (::nxt[d - 1][i].s != -1)
                ::nxt[d][i].s = ::nxt[d - 1][::nxt[d - 1][i].s].s;
            else
                ::nxt[d][i].s = -1;
        }
}

int getnextf(int c, int s)
{
    if (!a[c])
        s--;
    for (int d = 0; s >= (1 << d); ++d)
    {
        if (s & (1 << d))
        {
            c = nxt[d][c].f;
            if (c == -1)
                break;
        }
    }
    return c;
}

int getnexts(int c, int s)
{
    if (a[c])
        s--;
    for (int d = 0; s >= (1 << d); ++d)
    {
        if (s & (1 << d))
        {
            c = nxt[d][c].s;
            if (c == -1)
                break;
        }
    }
    return c;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        (cin >> a[i]), --a[i];
    int w = a[n - 1];
    prec();

    for (int s = 1; s <= n; ++s)
    {
        int cp = 0, np = 1, t[2] = {0, 0};
        while (np && cp != n)
        {
            np = getnextf(cp, s) + 1;
            if (!np || np - cp >= 2 * s)
            {
                np = getnexts(cp, s) + 1;
                if (np && np - cp < 2 * s)
                    ++t[1];
            }
            else
                ++t[0];
            cp = np;
        }
        if (cp == n && t[w] > t[!w])
            st.push_back(make_pair(t[w], s));
    }
    sort(st.begin(), st.end());
    cout << st.size();
    for (auto i: st)
        cout << '\n' << i.f << ' ' << i.s;
    return 0;
}