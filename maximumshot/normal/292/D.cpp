// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

int n, m;
vec<int> p, size;

int find(int x)
{
    return (p[x] == x?x : p[x] = find(p[x]));
}

bool solve()
{
    scanf("%d %d", &n, &m);

    size.resize(n + 1, 1);
    p.resize(n + 1);

    vec< pair<int, int> > e(m + 1);
    vec<int> addl, addr;

    for(int i(1);i <= m;i++) scanf("%d %d", &e[i].first, &e[i].second);

    for(int i(1);i <= n;i++) p[i] = i;

    for(int i(1);i <= m;i++)
    {
        int x, y, px, py;
        x = e[i].first;
        y = e[i].second;

        px = find(x);
        py = find(y);

        if(px != py)
        {
            addl.push_back(i);
            
            if(size[px] == size[py]) p[px] = py, size[py]++;
            else
            {
                if(size[px] > size[py]) swap(px, py);
                p[px] = py;
            }
        }
    }

    for(int i(1);i <= n;i++) p[i] = i, size[i] = 1;

    for(int i(m);i >= 1;i--)
    {
        int x, y, px, py;
        x = e[i].first;
        y = e[i].second;

        px = find(x);
        py = find(y);

        if(px != py)
        {
            addr.push_back(i);

            if(size[px] == size[py]) p[px] = py, size[py]++;
            else
            {
                if(size[px] > size[py]) swap(px, py);
                p[px] = py;
            }
        }
    }

    int k, l, r, ql = (int)addl.size(), qr = (int)addr.size();

    scanf("%d", &k);

    while(k--)
    {
        scanf("%d %d", &l, &r);

        for(int i(1);i <= n;i++) p[i] = i;
        size.assign(n, 1);

        for(int i(0);i < ql && addl[i] < l;i++)
        {
            int x, y, px, py;
            x = e[addl[i]].first;
            y = e[addl[i]].second;

            px = find(x);
            py = find(y);

            if(px != py)
            {
                addl.push_back(i);
            
                if(size[px] == size[py]) p[px] = py, size[py]++;
                else
                {
                    if(size[px] > size[py]) swap(px, py);
                    p[px] = py;
                }
            }
        }

        for(int i(0);i < qr && addr[i] > r;i++)
        {
            int x, y, px, py;
            x = e[addr[i]].first;
            y = e[addr[i]].second;

            px = find(x);
            py = find(y);

            if(px != py)
            {
                addl.push_back(i);
            
                if(size[px] == size[py]) p[px] = py, size[py]++;
                else
                {
                    if(size[px] > size[py]) swap(px, py);
                    p[px] = py;
                }
            }
        }

        int ans = 0;

        for(int i(1);i <= n;i++) ans += (p[i] == i);

        printf("%d\n", ans);
    }

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}