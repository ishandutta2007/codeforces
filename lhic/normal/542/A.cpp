#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
    
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 200001;

pair <int, int> ch[MAXN];

int lv[MAXN], rv[MAXN], cn = 0;
int rmq[4 * MAXN];
int aa[MAXN], bb[MAXN], cc[MAXN];
int ls[MAXN], rs[MAXN];

void create_rmq(int v, int l, int r)
{
    if (l == r) rmq[v] = rv[l] - lv[l];
    else
    {
        create_rmq(v * 2 + 1, l, (l + r) / 2);
        create_rmq(v * 2 + 2, (l + r) / 2 + 1, r);
        rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]);
    }
}

int lz, rz;

int get_rmq(int v, int l, int r)
{
    if ((l > rz) || (lz > r)) return 0;
    if ((lz <= l) && (r <= rz)) return rmq[v];
    return max(get_rmq(v * 2 + 1, l, (l + r) / 2), get_rmq(v * 2 + 2, (l + r) / 2 + 1, r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ch[i].first >> ch[i].second;
        ls[i] = ch[i].first, rs[i] = ch[i].second;
        ch[i].second = -ch[i].second;
    }
    sort(ch, ch + n);
    int mx = -1;
    long long ans = 0;
    int ach = -1;
    for (int i = 0; i < n; i++)
    {
        ch[i].second = -ch[i].second;
        if (ch[i].second <= mx) continue;
        mx = ch[i].second;
        lv[cn] = ch[i].first, rv[cn] = ch[i].second;
        cn++;
    }
    create_rmq(0, 0, cn - 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        aa[i] = a, bb[i] = b, cc[i] = c;
        int ca = 0;
        int  lg = 0, rg = cn - 1;
        int ll, rr;
        while (lg < rg)
        {
            int md = (lg + rg + 1) / 2;
            if (lv[md] >= a) rg = md - 1;
            else lg = md;
        }
        ll  = lg;
        lg = 0, rg = cn - 1;
        while (lg < rg)
        {
            int md = (lg + rg) / 2;
            if (rv[md] <= b) lg = md + 1;
            else rg = md;
        }
        rr = lg;
        ca = max(ca, min(rv[rr], b) - max(lv[rr], a));
        ca = max(ca, min(rv[ll], b) - max(lv[ll], a));
        lz = ll + 1, rz = rr - 1;
        ca = max(ca, get_rmq(0, 0, cn - 1));
        long long na = (long long)ca * (long long)c;
        if (ans < na) ans = na, ach = i;
    }
    cout << ans << endl;
    if (ans != 0)
    {
        int nv = ans / cc[ach];
        for (int i = 0; i < n; i++)
        {
            if (min(rs[i], bb[ach]) - max(ls[i], aa[ach]) == nv)
            {
                cout << i + 1 << " " << ach + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}