#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf64 / 100 + 7;
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}
int sign(LD x) {return (x >= 0?1 : -1);}

using namespace std;

void make()
{
    int m, k;

    scanf("%d %d", &m, &k);

    int delt = 0, t, r;
    vec<int> a(k + 1, 0);
    bool f = 0;

    for(int i(1);i <= k;i++) scanf("%d", &a[i]);

    vec< pair<int, int> > q(m - 1);

    for(int i(0);i < m - 1;i++)
    {
        scanf("%d %d", &q[i].first, &q[i].second);
        if(q[i].second) f = 1;
    }
    
    if(!f)
    {
        for(int i(0);i < m - 1;i++)
        {
            if(q[i].first == 0) delt++;
            else a[q[i].first]--;
        }

        for(int i(1);i <= k;i++) printf(a[i] - delt <= 0?"Y" : "N");    
        puts("");
        return;
    }

    int pos = 0;
    for(pos;pos < m - 1 && !q[pos].second;pos++) a[q[pos].first]--;

    vec<bool> can(k + 1, 0);

    f = 0;
    for(int i(1);i <= k;i++) if(a[i] == 0) f = 1, can[i] = 1;

    if(f)
    {
        for(pos;pos < m - 1;pos++) a[q[pos].first]--;
        for(int i(1);i <= k;i++)
        {
            if(can[i] || a[i] + a[0] <= 0) printf("Y");
            else printf("N");
        }
        puts("");
        return;
    }

    vec<int> first(k + 1, inf), last(k + 1, -inf);

    for(int i(0);i < m - 1;i++)
    {
        int x = q[i].first;
        last[x]  = max(last[x], i);
        first[x] = min(first[x], i);
    }

    int mn = inf;

    for(int x(1);x <= k;x++)
    {
        if(last[x] >= pos) continue;

        if(a[x] + a[0] <= 0)
        {
            can[x] = 1;
            mn = min(mn, a[x]);
        }
    }

    delt = -a[0] - mn;

    for(int i(pos);i < m - 1;i++)
    {
        int t, r;
        t = q[i].first;
        r = q[i].second;

        if(t == 0) delt++;
        else a[t]--;
    }

    for(int i(1);i <= k;i++) printf(a[i] - delt <= 0 || can[i]?"Y" : "N");
    puts("");
}

bool solve()
{   
    int t;

    scanf("%d", &t);

    while(t--) make();

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}