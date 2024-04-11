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

void read(LL &n, vec<LL> &a)
{
    cin >> n;
    a.resize(n);
    for(int i(0);i < n;i++) cin >> a[i];
    sort(ALL(a));
}

pair<LL, LL> get(LL n, vec<LL> a, LL m, vec<LL> b, bool f)
{
    LL ans, A, B, d, l, r, mid, c1, c2, p;

    ans = 3 * (n - m), A = 3 * n, B = 3 * m;

    if(ans < 2 * (n - m))
        ans = 2 * (n - m), A = 2 * n, B = 2 * m;

    for(int i(0);i < n;i++)
    {
        d = a[i] - 1;

        l = 0, r = m - 1;
        
        while(r - l > 1)
        {
            mid = (l + r) >> 1;
            
            if(b[mid] <= d) l = mid;
            else r = mid - 1;
        }
            
        if(b[r] <= d) p = r;
        else p = l;

        c1 = 3 * (n - i) + 2 * i;

        if(b[0] > d) c2 = 3 * m;
        else if(b[m - 1] <= d) c2 = 2 * m;
        else c2 = (p + 1) * 2 + (m - p - 1) * 3;

        if(f) swap(c1, c2);

        if(ans < (c1 - c2)) ans = c1 - c2, A = c1, B = c2;
        else if(ans == c1 - c2 && A < c1) A = c1, B = c2; 
    }
    c1 = 2 * n;
    for(int i(0);i < m;i++)
    {
        if(b[i] <= a[n - 1] + 1) continue;
        c2 = 2 * i + 3 * (m - i);
        
        if(f) swap(c1, c2);

        if(ans < (c1 - c2)) ans = c1 - c2, A = c1, B = c2;
        else if(ans == c1 - c2 && A < c1) A = c1, B = c2; 
    }

    return mp(A, B);
}

bool solve()
{
    LL n, m;
    vec<LL> a, b;
    
    read(n, a);
    read(m, b);

    pair<LL, LL> l = get(n, a, m, b, 0);
    
    cout << l.first << ':' << l.second << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}