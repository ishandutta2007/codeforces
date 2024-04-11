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

bool solve()
{
    map<LL, int> l, r;

    int n;

    scanf("%d", &n);

    vec<LL> a(n + 1), suml(n + 1), sumr(n + 2), summ(n + 2);

    for(int i(1);i <= n;i++)
    {
        scanf("%I64d", &a[i]);
        if(!l[a[i]]) l[a[i]] = i;
        r[a[i]] = i;
        suml[i] = suml[i - 1] + a[i];
    }

    for(int i(n);i >= 1;i--) sumr[i] = sumr[i + 1] + a[i];

    for(int i(1);i <= n;i++) summ[i] = summ[i - 1] + max(0ll, a[i]);
    
    int pos = -1;
    LL delt = -inf64;

    for(int i(1);i <= n;i++)
    {
        LL tmp;
        int tl, tr;

        tl = l[a[i]];
        tr = r[a[i]];

        if(tl == tr) continue;

        tmp = summ[tr - 1] - summ[tl] + a[tl] + a[tr];

        if(tmp > delt) delt = tmp, pos = i;
    }

    vec<int> q;

    for(int i(1);i < l[a[pos]];i++) q.push_back(i);
    for(int i(r[a[pos]] + 1);i <= n;i++) q.push_back(i);

    for(int i(l[a[pos]] + 1);i < r[a[pos]];i++) if(a[i] < 0) q.push_back(i);

    printf("%I64d %d\n", delt, (int)q.size());

    sort(ALL(q));

    for(int i(0);i < (int)q.size();i++) printf("%d ", q[i]);

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}