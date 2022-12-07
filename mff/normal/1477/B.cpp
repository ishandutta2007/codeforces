#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

struct st
{
    int n;
    vector<int> d, lz;

    st(string s) : n(s.length()), d(4 * n), lz(4 * n, -1)
    {
        build(1, 0, n, s);
    }

    void build(int p, int b, int e, string &s)
    {
        if (b + 1 == e)
        {
            d[p] = s[b] - '0';
        }
        else
        {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            build(l, b, m, s);
            build(r, m, e, s);
            d[p] = d[l] + d[r];
        }
    }

    void push(int p, int l, int r, int b, int m, int e)
    {
        if (lz[p] != -1)
        {
            lz[l] = lz[r] = lz[p];
            d[l] = lz[p] * (m - b);
            d[r] = lz[p] * (e - m);
            lz[p] = -1;
        }
    }

    int sum(int p, int b, int e, int x, int y)
    {
        if (x <= b && e <= y)
            return d[p];

        int m = (b + e) >> 1, l = p << 1, r = l | 1;
        push(p, l, r, b, m, e);

        int res = 0;

        if (x < m)
            res += sum(l, b, m, x, y);

        if (m < y)
            res += sum(r, m, e, x, y);

        return res;
    }

    void put(int p, int b, int e, int x, int y, int v)
    {
        if (x <= b && e <= y)
        {
            lz[p] = v;
            d[p] = v * (e - b);
        }
        else
        {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push(p, l, r, b, m, e);

            if (x < m)
                put(l, b, m, x, y, v);

            if (m < y)
                put(r, m, e, x, y, v);

            d[p] = d[l] + d[r];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        st S(b);

        vector<pair<int, int>> qr(q);
        for (int i = 0; i < q; ++i)
            cin >> qr[i].first >> qr[i].second;

        bool ok = true;

        for (int i = q - 1; i >= 0 && ok; --i)
        {
            int b = qr[i].first, e = qr[i].second;
            b--;

            int s = S.sum(1, 0, n, b, e);
            if (2 * s == (e - b))
            {
                ok = false;
                break;
            }
            else if (2 * s < (e - b))
            {
                S.put(1, 0, n, b, e, 0);
            }
            else
            {
                S.put(1, 0, n, b, e, 1);
            }
        }

        if (ok)
        {
            for (int i = 0; i < n && ok; ++i)
                ok &= S.sum(1, 0, n, i, i + 1) == (a[i] - '0');
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}