#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

LL binpow(LL n, LL m)
{
    if(m == 0) return 1ll;
    
    LL q = binpow(n, m / 2);
    q = (q * q) % base;

    if(m % 2)
        return (q * n) % base;
    else
        return q;
}

const LL P = 157;

vec<int> t, a;

void push(int v)
{
    if(t[v])
    {
        t[v << 1] += t[v];
        t[v << 1 | 1] += t[v];
        t[v] = 0;
    }
}

void up(int v, int tl, int tr, int l, int r)
{
    if(l <= tl && tr <= r) t[v]++;
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        if(l <= tm) up(v << 1, tl, tm, l, r);
        if(r > tm) up(v << 1 | 1, tm + 1, tr, l, r);
    }
}

void shot(int v, int tl, int tr)
{
    if(tl == tr) a.push_back(t[v]);
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        shot(v << 1, tl, tm);
        shot(v << 1 | 1, tm + 1, tr);
    }
}

bool solve()
{
    int n, m;

    scanf("%d %d", &n, &m);

    string p;
    cin >> p;
    
    int psz = (int)p.size();

    t.resize(4 * (n + 1), 0);

    vec<int> mas;

    for(int i(0);i < m;i++)
    {
        int x, l, r;
        scanf("%d", &x);
        mas.push_back(x);
        l = x;
        r = x + psz - 1;

        if(r > n) 
        {
            puts("0");
            return true;
        }

        up(1, 1, n, l, r);
    }

    shot(1, 1, n);

    int cnt = count(ALL(a), 0);

    vec<bool> used(psz + 1);

    for(int i(0);i < m - 1;i++) {
        int len = mas[i + 1] - mas[i];
        if(len <= psz) {
            used[psz - len] = 1;
        }
    }

    vec<bool> can(psz + 1, 0);

    vec<int> preff(psz);

    preff[0] = 0;

    for(int i(1);i < psz;i++) {
        int j = preff[i - 1];
        while(j > 0 && p[i] != p[j]) j = preff[j - 1];
        if(p[i] == p[j]) j++;
        preff[i] = j;
    }

    for(int i(psz - 1);i >= 0;i = preff[i] - 1) {
        can[preff[i]] = 1;
    }

    for(int i(1);i <= psz;i++)
    {
        if(used[i] && !can[i])
        {
            puts("0");
            return true;
        }
    }

    printf("%I64d\n", binpow(26ll, (LL)cnt));

    return true;
}   

int main()
{
    //while(solve());
    solve();

    return 0;
}