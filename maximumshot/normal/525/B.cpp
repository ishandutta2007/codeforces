#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = 1ll << 32;
const LD eps = 1e-11;
 
vec<int> t;

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

int get(int v, int tl, int tr, int pos)
{
    if(tl == tr) return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        if(pos <= tm) return get(v << 1, tl, tm, pos);
        else return get(v << 1 | 1, tm + 1, tr, pos);
    }
}

bool solve()
{
    string a;

    cin >> a;

    int n = (int)a.size();

    t.resize(4 * n, 0);

    int m;
    scanf("%d", &m);

    for(int x, i(0);i < m;i++)
    {
        scanf("%d", &x);
        up(1, 1, n, x, n - x + 1);
    }

    for(int i(0);i < n / 2;i++) 
    {
        if(get(1, 1, n, i + 1) % 2) swap(a[i], a[n - 1 - i]);
    }

    cout << a << '\n';

    return true; 
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}