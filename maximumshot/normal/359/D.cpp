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

#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

int Abs (int x) {return (x >= 0?x : -x);}

int gcd(int x, int y)
{
    return (x == 0?y : gcd(y % x, x));
}

struct Node
{
    int g, mn;

    Node()
    {
        mn = inf;
        g = 1;
    }

    const Node & operator = (const Node & a)
    {
        g = a.g;
        mn = a.mn;

        return *this;
    }
};

vec<Node> t;
int n;
vec<int> a;

void build(int v, int tl, int tr)
{
    if(tl == tr) t[v].g = t[v].mn = a[tl];
    else
    {
        int tm = (tl + tr) >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v].g = gcd(t[v << 1].g, t[v << 1 | 1].g);
        t[v].mn = min(t[v << 1].mn, t[v << 1 | 1].mn);
    }
}

Node get(int v, int tl, int tr, int l, int r)
{
    if(l <= tl && tr <= r) return t[v];
    else
    {
        int tm = (tl + tr) >> 1;

        if(l <= tm && r > tm) 
        {
            Node L, R, ans;

            L = get(v << 1, tl, tm, l, r);
            R = get(v << 1 | 1, tm + 1, tr, l, r);

            ans.g = gcd(L.g, R.g);
            ans.mn = min(L.mn, R.mn);

            return ans;
        }else if(l <= tm) return get(v << 1, tl, tm, l, r);
        else return get(v << 1 | 1, tm + 1, tr, l, r);
    }
}

bool check(int x)
{
    Node q;

    for(int i(1);i + x - 1 <= n;i++)
    {
        q = get(1, 1, n, i, i + x - 1);
        if(q.g == q.mn) return true;
    }

    return false;
}

bool solve()
{
    scanf("%d", &n);
    
    a.resize(n + 1);
    t.resize(4 * (n + 1), Node());

    for(int i(1);i <= n;i++) scanf("%d", &a[i]); 

    build(1, 1, n);

    int l, r, mid, p;

    l = 1, r = n;

    while(r - l > 1)
    {
        mid = (l + r) >> 1;

        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    if(check(r)) p = r;
    else p = l;

    vec<int> ans;

    Node q;

    for(int i(1);i + p - 1 <= n;i++)
    {
        q = get(1, 1, n, i, i + p - 1);

        if(q.g == q.mn) ans.push_back(i);
    }

    printf("%d %d\n", (int)ans.size(), p - 1);
    
    for(int i(0);i < (int)ans.size();i++) printf("%d ", ans[i]);

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}