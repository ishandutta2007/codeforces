#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <cctype>
#include <ctime>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second

typedef int _int;



const int mod = 1000 * 1000 * 1000 + 7;
const int N = 100 * 1000 + 100;
int value[4 * N][6];
pii add[4 * N];
int sum[4 * N][6];
int a[N];
int last[4 * N];
int c[6][6];
int n;
int timer = 0;



int get_pow(int base, int x)
{
    if (base == 0)
        return 0;
    int res = 1;
    for (int i = 0; i < x; ++i)
        res = 1ll * res * base % mod;
    return res;
}

int *build(int pos, int l, int r);

void init()
{
    for (int i = 0; i <= 5; ++i)
        for (int j = 0; j < 4 * N; ++j)
        {
            sum[j][i] = get_pow(j, i);
            if (j)
            {
                sum[j][i] += sum[j - 1][i];
                sum[j][i] %= mod;
            }
        }

    c[1][0] = 1;
    c[1][1] = 1;

    c[2][0] = 1;
    c[2][1] = 2;
    c[2][2] = 1;

    c[3][0] = 1;
    c[3][1] = 3;
    c[3][2] = 3;
    c[3][3] = 1;

    c[4][0] = 1;
    c[4][1] = 4;
    c[4][2] = 6;
    c[4][3] = 4;
    c[4][4] = 1;

    c[5][0] = 1;
    c[5][1] = 5;
    c[5][2] = 10;
    c[5][3] = 10;
    c[5][4] = 5;
    c[5][5] = 1;

    build(0, 0, n - 1);
}



void merge(int *t, int *sl, int *sr, int l, int r, int L, int R)
{
    int len_l = r - l + 1;
    for (int i = 0; i <= 5; ++i)
    {
        t[i] = (0ll + sl[i] + sr[i]) % mod;
        for (int j = 1; j <= i; ++j)
        {
            t[i] += 1ll * get_pow(len_l, j) * c[i][j] % mod * sr[i - j] % mod;
            t[i] %= mod;
        }
    }
}


int *get_sum(int pos, int l, int r, int tl, int tr, pii cur_add);


int *build(int pos, int l, int r)
{
    add[pos] = pii(-1, -1);
    last[pos] = -1;

    if (l == r)
    {
        for (int i = 0; i <= 5; ++i)
            value[pos][i] = a[l] % mod;
        return value[pos];
    }

    int mid = (l + r) / 2;
    int cl = 2 * pos + 1;
    int cr = 2 * pos + 2;
    int *sl = build(cl, l, mid);
    int *sr = build(cr, mid + 1, r);

    merge(value[pos], sl, sr, l, mid, mid + 1, r);

    return value[pos];
}


void assign(int pos, int l, int r, int tl, int tr, int x, pii cur_add = pii(-1, -1))
{
    if (add[pos].S > cur_add.S)
        cur_add = add[pos];

    if (l == tl && r == tr)
    {
        last[pos] = timer;
        add[pos] = pii(x, timer);
        for (int i = 0; i <= 5; ++i)
            value[pos][i] = 1ll * sum[r - l + 1][i] * x % mod;
        return;
    }


    last[pos] = timer;

    int mid = (tl + tr) / 2;
    int cl = 2 * pos + 1;
    int cr = 2 * pos + 2;

    int *sl = NULL;
    int *sr = NULL;

    if (l <= mid)
        assign(cl, l, min(r, mid), tl, mid, x, cur_add);
    if (r > mid)
        assign(cr, max(mid + 1, l), r, mid + 1, tr, x, cur_add);

    sl = get_sum(cl, tl, mid, tl, mid, cur_add);
    sr = get_sum(cr, mid + 1, tr, mid + 1, tr, cur_add);


    merge(value[pos], sl, sr, tl, mid, mid + 1, tr);
}


int *get_sum(int pos, int l, int r, int tl, int tr, pii cur_add)
{
    if (add[pos].S > cur_add.S)
        cur_add = add[pos];

    if (l == tl && r == tr)
    {
        if (cur_add.S == -1 || last[pos] > cur_add.S)
            return value[pos];
        int *t = new int[6];
        for (int i = 0; i <= 5; ++i)
            t[i] = 1ll * sum[r - l + 1][i] * cur_add.F % mod;
        return t;
    }

    int *sl = NULL;
    int *sr = NULL;
    int *res = new int[6];
    int mid = (tl + tr) / 2;
    int cl = 2 * pos + 1;
    int cr = 2 * pos + 2;

    if (l <= mid)
        sl = get_sum(cl, l, min(r, mid), tl, mid, cur_add);
    if (r > mid)
        sr = get_sum(cr, max(mid + 1, l), r, mid + 1, tr, cur_add);

    if (!sl || !sr)
        res = (sl ? sl : sr);
    else
        merge(res, sl, sr, l, mid, mid + 1, r);

    return res;
}


_int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int m;
    scanf("%d%d", & n, & m);
    for (int i = 0; i < n; ++i)
        scanf("%d", & a[i]);

    init();

    for (int i = 0; i < m; ++i)
    {
        char c = 'x';
        while (c != '?' && c != '=')
            scanf("%c", & c);

        int l, r, x;
        scanf("%d%d%d", & l, & r, & x);

        --l;
        --r;

        if (c == '=')
        {
            assign(0, l, r, 0, n - 1, x);
            timer++;
        }
        else
        {
            int *t = get_sum(0, l, r, 0, n - 1, pii(-1, -1));
            printf("%d\n", t[x]);
        }
    }

    return 0;
}