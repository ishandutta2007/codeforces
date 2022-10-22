#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

int n, m;
vec<LL> a;
LL C[6][6] = {0};

LL binpow(LL n, LL m)
{
    if(m == 0) return 1ll;

    LL q = binpow(n, m / 2);
    q = (q * q) % base;

    if(m % 2) return (q * n) % base;
    else return q;
}

struct tree
{
    LL sum, delt, bin;

    tree()
    {
        sum = bin = 0;
        delt = -1;
    }
};

vec<tree> t[6];

void pushdown(LL v)
{
    for(int i(0);i < 6;i++)
    {
        if(t[i][v].delt != -1)
        {
            t[i][v << 1].delt = t[i][v << 1 | 1].delt = t[i][v].delt % base;
            t[i][v << 1].sum = ((t[i][v << 1].delt % base) * (t[i][v << 1].bin % base)) % base;
            t[i][v << 1 | 1].sum = ((t[i][v << 1 | 1].delt % base) * (t[i][v << 1 | 1].bin % base)) % base;
            t[i][v].delt = -1;
        }
    }
}

void pushup(LL v)
{
    for(int i(0);i < 6;i++)
        t[i][v].sum = (t[i][v << 1].sum % base + t[i][v << 1 | 1].sum % base) % base;
}

void build(LL v, LL tl, LL tr)
{
    if(tl == tr)
    {
        t[0][v].bin = 1ll;
        for(int i(1);i < 6;i++) t[i][v].bin = (t[i - 1][v].bin * tl) % base;
        for(int i(0);i < 6;i++) t[i][v].sum = ((a[tl] % base) * (t[i][v].bin % base)) % base;
    }else
    {
        LL tm = (tl + tr) >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        for(int i(0);i < 6;i++) t[i][v].bin = (t[i][v << 1].bin % base + t[i][v << 1 | 1].bin % base) % base;

        pushup(v);
    }
}

void update(LL v, LL tl, LL tr, LL l, LL r, LL x)
{
    if(l <= tl && tr <= r)
    {
        for(int i(0);i < 6;i++)
        {
            t[i][v].delt = x % base;
            t[i][v].sum = (x * t[i][v].bin) % base;
        }
    }else
    {
        LL tm = (tl + tr) >> 1;
        pushdown(v);

        if(l <= tm) update(v << 1, tl, tm, l, r, x);
        if(r > tm) update(v << 1 | 1, tm + 1, tr, l, r, x);

        pushup(v);
    }
}

LL sum(LL v, LL tl, LL tr, LL l, LL r, LL k)
{
    if(l <= tl && tr <= r) return t[k][v].sum % base;
    else
    {
        LL tm = (tl + tr) >> 1;
        LL L, R;
        L = R = 0;
        
        if(t[k][v].delt != -1)
        {
            t[k][v << 1].delt = t[k][v << 1 | 1].delt = t[k][v].delt % base;
            t[k][v << 1].sum = ((t[k][v << 1].delt % base) * (t[k][v << 1].bin % base)) % base;
            t[k][v << 1 | 1].sum = ((t[k][v << 1 | 1].delt % base) * (t[k][v << 1 | 1].bin % base)) % base;
            t[k][v].delt = -1;
        }

        if(l <= tm) L = sum(v << 1, tl, tm, l, r, k);
        if(r > tm) R = sum(v << 1 | 1, tm + 1, tr, l, r, k);

        t[k][v].sum = (t[k][v << 1].sum % base + t[k][v << 1 | 1].sum % base) % base;

        return (L + R) % base;
    }   
}

LL get_ans(LL l, LL r, LL k)
{
    LL x = 1 - l;
    LL ans = 0;
    for(int i(0);i <= k;i++) ans = (ans + (((C[k][i] * binpow(x, i) % base) + base) % base) * sum(1, 1, n, l, r, k - i) % base) % base;
    return ans % base;
}

void init()
{
    C[0][0] = C[1][0] = C[1][1] = 1;
    
    for(int i(2);i < 6;i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j(1);j < i;j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
}

bool solve()
{
    init();

    scanf("%d %d", &n, &m);

    a.resize(n + 1);
    for(int i(1);i <= n;i++) scanf("%I64d", &a[i]);
    
    for(int i(0);i < 6;i++) t[i].resize(4 * (n + 1), tree());

    build(1, 1, n);

    char type;
    LL x;
    int l, r;

    while(m--)
    {
        scanf(" %c %d %d %I64d", &type, &l, &r, &x);
        if(type == '=') update(1, 1, n, l, r, x);
        else printf("%I64d\n", get_ans(l, r, x));
    }

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}