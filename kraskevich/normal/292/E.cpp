#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair

struct triple
{
    int x, y, time;
    triple() {}
    triple(int _x, int _y, int _time): x(_x), y(_y), time(_time) {}
};

const int N = 100 * 1000;
triple add[4 * N];
int a[N];
int b[N];
int n, q;

void init()
{
    fill(add, add + 4 * N, triple(-1, -1, -1));
}

triple get_pos(int i, int pos, int tl, int tr)
{
    if (tl == pos && tr == pos)
        return add[i];
    int m = (tl + tr) / 2;
    triple cur;
    if (pos <= m)
        cur = get_pos(2 * i + 1, pos, tl, m);
    else
        cur = get_pos(2 * i + 2, pos, m + 1, tr);
    if (cur.time < add[i].time)
        cur = add[i];
    return cur;
}

void set_val(int i, int l, int r, int tl, int tr, triple n_add)
{
    if (l == tl && r == tr)
    {
        add[i] = n_add;
        return;
    }
    int m = (tl + tr) / 2;
    if (l <= m)
        set_val(2 * i + 1, l, min(r, m), tl, m, n_add);
    if (r > m)
        set_val(2 * i + 2, max(m + 1, l), r, m + 1, tr, n_add);
}

void solve()
{
    init();

    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < q; ++i)
    {
        int t;
        cin >> t;;
        if (t == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;

            --x;
            --y;
            set_val(0, y, y + k - 1, 0, N - 1, triple(x, y, i));
        }
        else
        {
            int x;
            cin >> x;

            --x;
            triple cur = get_pos(0, x, 0, N - 1);
            if (cur.x == -1)
            {
                cout << b[x] << "\n";
            }
            else
            {
                int pos = x - cur.y;
                pos += cur.x;
                cout << a[pos] << "\n";
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}