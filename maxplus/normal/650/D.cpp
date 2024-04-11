#define first f
#define second s
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const int N = 400003;
int n, m, a[N], sd[N], fp[N], pl[N], sl[N], ans[N], bisl;
vector<pair<int, int>> pd[N];
vector<int> qh[N], qn[N];

inline bool operator <(const vector<pair<int, int>> &a, const int &key)
{
    return a.back().f < key;
}

inline bool operator <(const int &key, const vector<pair<int, int>> &a)
{
    return key < a.back().f;
}

inline bool operator <(const int &key, const pair<int, int> &a)
{
    return key < a.f;
}

inline bool operator <(const pair<int, int> &a, const int &key)
{
    return a.f < key;
}

template<class it, class key>
it lower(it b, it e, key x)
{
    b = prev(b), e = prev(e);
    int len = e - b;
    while (len != 1)
    {
        it m = b + ((len + 1) >> 1);
        if (*m < x)
            b = m, len >>= 1;
        else
            e = m, len -= len >> 1;;
    }
    return e;
}

template<class it, class key>
it upper(it b, it e, key x)
{
    int len = e - b;
    while (len != 1)
    {
        it m = b + (len >> 1);
        if (x < *m)
            e = m, len >>= 1;
        else
            b = m, len -= len >> 1;
    }
    return e;
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    a[0] = -1e9 - 1;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[n + 1] = 1e9 + 1;
    ++++n;
    for (int i = 0; i <= n; ++i)
        pd[i].pb({1e9 + 2, n + 1});
    pd[0][0] = {-1e9 - 2, 0};
    memset(sd, 63, sizeof(sd));
    sd[0] = -sd[0];
    for (int i = 0; i < n; ++i)
    {
        bisl = max(bisl, pl[i] = lower(pd + 0, pd + n, a[i]) - pd);
        int j = upper(pd + 0, pd + n, a[i]) - pd;
        if (pd[j - 1] < a[i])
            pd[j].pb({a[i], i});
    }
    for (int i = n - 1; i > -1; --i)
    {
        sl[i] = lower(sd, sd + n, -a[i]) - sd;
        int j = upper(sd, sd + n, -a[i]) - sd;
        if (sd[j - 1] < -a[i])
            sd[j] = -a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        auto it = lower(rall(pd[bisl - sl[i]]), a[i]);
        if (it != pd[bisl - sl[i]].rbegin())
            fp[i] = (--it)->s;
        else
            fp[i] = n;
    }
    for (int i = 0, c, h; i < m; ++i)
    {
        cin >> c >> h;
        qh[c].pb(h);
        qn[c].pb(i);
    }
    memset(sd, 63, sizeof(sd));
    sd[0] = -sd[0];
    for (int i = n - 1, j, bfp, bwo; i > -1; --i)
    {
        bwo = bfp < i? bisl: bisl - 1;
        bfp = min(bfp, fp[i]);
        for (int k = 0; k < qh[i].size(); ++k)
        {
            j = lower(sd, sd + n, -qh[i][k]) - sd;
            auto it = lower(rall(pd[bisl + 1 - j]), qh[i][k]);
            if (it != pd[bisl + 1 - j].rbegin() && (--it)->f < qh[i][k] && it->s < i)
                ans[qn[i][k]] = bisl + 1;
            else if ((it = lower(rall(pd[bisl - j]), qh[i][k]))
                         != pd[bisl - j].rbegin() && (--it)->f < qh[i][k] && it->s < i)
                    ans[qn[i][k]] = bisl;
                else
                    ans[qn[i][k]] = bwo;
        }
        j = upper(sd, sd + n, -a[i]) - sd;
        if (sd[j - 1] < -a[i])
            sd[j] = -a[i];
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] - 2 << '\n';
    return 0;
}